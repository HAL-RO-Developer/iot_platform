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
	r.POST("/account", controller.CreateUserController)
	r.POST("/login", controller.LoginController)
	r.POST("/project", controller.CreateNewProject)
	r.POST("/function", controller.UserRequestController)
	r.POST("/receive", controller.DeviceRequestController)
	r.Run()
}
