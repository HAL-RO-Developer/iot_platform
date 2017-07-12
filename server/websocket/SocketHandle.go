package websocket

import (
	"github.com/trevex/golem"
	"net/http"
)

type joinModel struct {
	ID int `json:"id"`
}

func GetHandle() func(http.ResponseWriter, *http.Request) {
	return createRouter().Handler()
}

func createRouter() *golem.Router {
	router := golem.NewRouter()
	router.OnConnect(connectHndle)

	return router
}

// connection接続時の処理はここに書く
func connectHndle(conn *golem.Connection, http *http.Request) {
	id := GetManager().Set(conn)
	conn.Emit("join", joinModel{
		ID: id,
	})
}
