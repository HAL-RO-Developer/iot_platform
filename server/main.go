package main

import (
	"net/http"

	"github.com/HAL-RO-Developer/iot_platform/server/controller"
	"github.com/HAL-RO-Developer/iot_platform/server/logger"
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
	r.Static("/fonts", "./public/fonts")

	r.LoadHTMLGlob("view/*")

	r.GET("/", func(c *gin.Context) {
		c.HTML(http.StatusOK, "index.html", nil)
	})

	// ダッシュボード仮設置
	user := r.Group("/user/:name")
	user.GET("/dashboard", func(c *gin.Context) {
		c.HTML(http.StatusOK, "dashboard.html", nil)
	})

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
	device.Use(logger.JsonLogger)
	device.POST("/iam", controller.DeviceRegistration)
	device.POST("/receive", controller.DeviceReceiveController)

	r.Run()
}
