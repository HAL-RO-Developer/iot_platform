package controller

import (
	"strings"
	"github.com/trevex/golem"
	"net/http"
	"github.com/HAL-RO-Developer/iot_platform/server/model"
)

type Connection struct {
	DeviceID string
	Conn     golem.Connection
}

var connes []Connection

func GetHandle() func(http.ResponseWriter, *http.Request) {
	return createRouter().Handler()
}

func createRouter() *golem.Router {
	router := golem.NewRouter()
	router.OnConnect(connectHandle)

	return router
}

// connection接続時の処理はここに書く
func connectHandle(conn *golem.Connection, http *http.Request) {
	device_id := strings.Split(http.URL.Path, "/")[3]
	connes = append(connes, Connection{DeviceID: device_id, Conn: *conn})
}

func MessageSend(msg model.Message ) {
	for _, value := range connes {
		if value.DeviceID == msg.DeviceID {
			value.Conn.Emit("message", msg)
		}
	}
}

//type Msg struct {
//	Msg model.Message `json:"msg"`
//}
