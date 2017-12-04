package main

import (
	"github.com/HAL-RO-Developer/iot_platform/test/socket"
	"github.com/gin-gonic/gin"
)

func main() {

	r := gin.Default()
	ws := socket.GetHandle()
	r.GET("/ws/:device_id", func(c *gin.Context) {
		ws(c.Writer, c.Request)
	})
	r.GET("/@:device_id/:msg", func(c *gin.Context) {
		deviceID := c.Param("device_id")
		msg := c.Param("msg")
		go socket.Send(deviceID, msg)
	})
	r.Run(":3000")
}
