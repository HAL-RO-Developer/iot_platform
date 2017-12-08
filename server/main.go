package main

import (
	"github.com/HAL-RO-Developer/iot_platform/server/controller"
	"github.com/HAL-RO-Developer/iot_platform/server/model"
	"github.com/gin-gonic/gin"
)

func main() {
	model.DB.AutoMigrate(&model.User{})
	model.DB.AutoMigrate(&model.Device{})

	r := gin.Default()
	r.Static("/js", "./public/js")
	r.Static("/image", "./public/image")
	r.Static("/css", "./public/css")

	r.LoadHTMLGlob("view/*")
	ws := controller.GetHandle()

	api := r.Group("/api")
	api.POST("/signup", controller.CreateUserController)
	api.POST("/signin", controller.LoginController)
	api.POST("/device", controller.CreateNewProject)
	api.POST("/function", controller.UserRequestController)
	api.GET("/ws/:device_id", func(c *gin.Context) {
		if !controller.UserWebSocketController(c) {
			ws(c.Writer, c.Request)
		}
	})

	device := r.Group("/device")
	device.POST("/iam", controller.DeviceRegistration)
	device.POST("/receive", controller.DeviceReceiveController)

	r.Run()
}
