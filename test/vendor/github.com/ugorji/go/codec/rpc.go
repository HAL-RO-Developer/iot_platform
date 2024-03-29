// Copyright (c) 2012-2015 Ugorji Nwoke. All rights reserved.
// Use of this source code is governed by a MIT license found in the LICENSE file.

package codec

import (
	"errors"
	"io"
	"net/rpc"
	"sync"
)

// Rpc provides a rpc Server or Client Codec for rpc communication.
type Rpc interface {
	ServerCodec(conn io.ReadWriteCloser, h Handle) rpc.ServerCodec
	ClientCodec(conn io.ReadWriteCloser, h Handle) rpc.ClientCodec
}

// // RpcCodecBuffered allows access to the underlying bufio.Reader/Writer
// // used by the rpc connection. It accommodates use-cases where the connection
// // should be used by rpc and non-rpc functions, e.g. streaming a file after
// // sending an rpc response.
// type RpcCodecBuffered interface {
// 	BufferedReader() *bufio.Reader
// 	BufferedWriter() *bufio.Writer
// }

// -------------------------------------

type rpcFlusher interface {
	Flush() error
}

// rpcCodec defines the struct members and common methods.
type rpcCodec struct {
	c io.Closer
	r io.Reader
	w io.Writer
	f rpcFlusher

	dec *Decoder
	enc *Encoder
	// bw  *bufio.Writer
	// br  *bufio.Reader
	mu sync.Mutex
	h  Handle

	cls    bool
	clsmu  sync.RWMutex
	clsErr error
}

func newRPCCodec(conn io.ReadWriteCloser, h Handle) rpcCodec {
	// return newRPCCodec2(bufio.NewReader(conn), bufio.NewWriter(conn), conn, h)
	return newRPCCodec2(conn, conn, conn, h)
}

func newRPCCodec2(r io.Reader, w io.Writer, c io.Closer, h Handle) rpcCodec {
	// defensive: ensure that jsonH has TermWhitespace turned on.
	if jsonH, ok := h.(*JsonHandle); ok && !jsonH.TermWhitespace {
		panic(errors.New("rpc requires a JsonHandle with TermWhitespace set to true"))
	}
	f, _ := w.(rpcFlusher)
	return rpcCodec{
		c:   c,
		w:   w,
		r:   r,
		f:   f,
		h:   h,
		enc: NewEncoder(w, h),
		dec: NewDecoder(r, h),
	}
}

// func (c *rpcCodec) BufferedReader() *bufio.Reader {
// 	return c.br
// }

// func (c *rpcCodec) BufferedWriter() *bufio.Writer {
// 	return c.bw
// }

func (c *rpcCodec) write(obj1, obj2 interface{}, writeObj2, doFlush bool) (err error) {
	if c.isClosed() {
		return io.EOF
	}
	if err = c.enc.Encode(obj1); err != nil {
		return
	}
	if writeObj2 {
		if err = c.enc.Encode(obj2); err != nil {
			return
		}
	}
	if doFlush && c.f != nil {
		return c.f.Flush()
	}
	return
}

func (c *rpcCodec) read(obj interface{}) (err error) {
	if c.isClosed() {
		return io.EOF
	}
	//If nil is passed in, we should still attempt to read content to nowhere.
	if obj == nil {
		var obj2 interface{}
		return c.dec.Decode(&obj2)
	}
	return c.dec.Decode(obj)
}

func (c *rpcCodec) isClosed() bool {
	if c.c == nil {
		return false
	}
	c.clsmu.RLock()
	x := c.cls
	c.clsmu.RUnlock()
	return x
}

func (c *rpcCodec) Close() error {
	if c.c == nil {
		return nil
	}
	if c.isClosed() {
		return c.clsErr
	}
	c.clsmu.Lock()
	c.cls = true
	var fErr error
	if c.f != nil {
		fErr = c.f.Flush()
	}
	_ = fErr
	c.clsErr = c.c.Close()
	if c.clsErr == nil && fErr != nil {
		c.clsErr = fErr
	}
	c.clsmu.Unlock()
	return c.clsErr
}

func (c *rpcCodec) ReadResponseBody(body interface{}) error {
	return c.read(body)
}

// -------------------------------------

type goRpcCodec struct {
	rpcCodec
}

func (c *goRpcCodec) WriteRequest(r *rpc.Request, body interface{}) error {
	// Must protect for concurrent access as per API
	c.mu.Lock()
	defer c.mu.Unlock()
	return c.write(r, body, true, true)
}

func (c *goRpcCodec) WriteResponse(r *rpc.Response, body interface{}) error {
	c.mu.Lock()
	defer c.mu.Unlock()
	return c.write(r, body, true, true)
}

func (c *goRpcCodec) ReadResponseHeader(r *rpc.Response) error {
	return c.read(r)
}

func (c *goRpcCodec) ReadRequestHeader(r *rpc.Request) error {
	return c.read(r)
}

func (c *goRpcCodec) ReadRequestBody(body interface{}) error {
	return c.read(body)
}

// -------------------------------------

// goRpc is the implementation of Rpc that uses the communication protocol
// as defined in net/rpc package.
type goRpc struct{}

// GoRpc implements Rpc using the communication protocol defined in net/rpc package.
// Its methods (ServerCodec and ClientCodec) return values that implement RpcCodecBuffered.
//
// By default, the conn parameter got from a network is not buffered.
// For performance, considering using a buffered value e.g.
//   var conn io.ReadWriteCloser // connection got from a socket
//   conn2 := codec.NewReadWriteCloser(conn, conn, 1024, 1024) // wrapped in 1024-byte bufer
//   var h = GoRpc.ServerCodec(conn2, handle)
var GoRpc goRpc

func (x goRpc) ServerCodec(conn io.ReadWriteCloser, h Handle) rpc.ServerCodec {
	return &goRpcCodec{newRPCCodec(conn, h)}
}

func (x goRpc) ClientCodec(conn io.ReadWriteCloser, h Handle) rpc.ClientCodec {
	return &goRpcCodec{newRPCCodec(conn, h)}
}

// var _ RpcCodecBuffered = (*rpcCodec)(nil) // ensure *rpcCodec implements RpcCodecBuffered
