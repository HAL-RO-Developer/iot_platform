package socket

import (
	"net/http"

	"strings"

	"github.com/trevex/golem"
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
	router.OnConnect(connectHndle)

	return router
}

// connection接続時の処理はここに書く
func connectHndle(conn *golem.Connection, http *http.Request) {
	device_id := strings.Split(http.URL.Path, "/")[2]
	connes = append(connes, Connection{DeviceID: device_id, Conn: *conn})
}

func Send(deviceID string, msg string) {
	for _, value := range connes {
		if value.DeviceID == deviceID {
			value.Conn.Emit("msg", Msg{Msg: msg})
		}
	}
}

type Msg struct {
	Msg string `json:"msg"`
}
