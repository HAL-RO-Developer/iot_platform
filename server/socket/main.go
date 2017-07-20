package socket

import (
	"net"
	"fmt"
	"strconv"
)

func ServerInit(port int){
	listener, err := net.Listen("tcp", "0.0.0.0:"+ strconv.Itoa(port))
	if err != nil {
		fmt.Printf("Listen error: %s\n", err)
		return
	}
	for  {
		conn, _ := listener.Accept()
		go serverHandle(conn)
	}
}
func serverHandle(conn net.Conn){
	socket := SocketManager(conn)
	uuid := socket.Read()
	// TODO UUIDのデータベース照合
	if _, ok := sockets[uuid]; !ok {
		panic("uuidが重複しました")
	}
	sockets[uuid] = socket
	for{
		message := socket.Read()
		if message == ""{
			delete(sockets, uuid)
			fmt.Println("[切断]"+ socket.conn.RemoteAddr().String())
			break
		}
		// TODO clientに渡す
		fmt.Println("[device->]: " + message)
	}
}
