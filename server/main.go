package main

import (
	"github.com/HAL-RO-Developer/iot_platform/server/controller"
	"github.com/HAL-RO-Developer/iot_platform/server/model"
	"github.com/gin-gonic/gin"
	"gopkg.in/olahol/melody.v1"
)

func main() {
	model.DB.AutoMigrate(&model.User{})
	model.DB.AutoMigrate(&model.Device{})

	r := gin.Default()
	m := melody.New()

	api := r.Group("/api")
	api.POST("/signup", controller.CreateUserController)
	api.POST("/signin", controller.LoginController)
	api.POST("/device", controller.CreateNewProject)
	api.POST("/function", controller.UserRequestController)
	api.GET("/ws/:token", func(c *gin.Context) {
		m.HandleRequest(c.Writer, c.Request)
		controller.UserWebSocketController(c, m)
	})

	device := r.Group("/device")
	device.POST("/iam", controller.DeviceRegistration)
	device.POST("/receive", controller.DeviceReceiveController)

	r.Run()
}
