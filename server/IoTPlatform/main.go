package main

import (
	"github.com/Komei1009/IoTPlatform/controller"
	"github.com/Komei1009/IoTPlatform/model"
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
