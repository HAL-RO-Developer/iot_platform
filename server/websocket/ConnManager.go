package websocket

import (
	"github.com/trevex/golem"
	"sync"
)

//connectionを保持するクラス
var currentIdLock sync.Mutex
var currentId = 0
var ConnManagerInstance = newConnManage()

type ConnManager struct {
	connModels []*Conn
	lock       sync.Mutex
}

func GetManager() *ConnManager {
	return ConnManagerInstance
}
func newConnManage() *ConnManager {
	return &ConnManager{}
}

type Conn struct {
	Id   int
	Conn *golem.Connection
}

func NewConn(conn *golem.Connection) *Conn {
	// トランザクション
	currentIdLock.Lock()
	id := currentId
	currentId += 1
	currentIdLock.Unlock()

	return &Conn{
		Id:   id,
		Conn: conn,
	}
}

func (self *ConnManager) Set(conn *golem.Connection) int {
	self.lock.Lock()
	self.connModels = append(self.connModels, NewConn(conn))
	connModel := self.connModels[len(self.connModels)-1]
	self.lock.Unlock()
	return connModel.Id
}

// 検索のロジックをここに書く
func (self *ConnManager) Get(id int) *golem.Connection {
	return self.connModels[id].Conn
}
