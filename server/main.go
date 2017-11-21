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
	api := r.Group("/api")

	api.POST("/signup", controller.CreateUserController)
	api.POST("/signin", controller.LoginController)
	api.POST("/device", controller.CreateNewProject)
	api.POST("/function", controller.UserRequestController)

	device := r.Group("/device")
	device.POST("/iam", controller.DeviceRegistration)
	device.POST("/receive", controller.DeviceRequestController)

	r.Run()
}
