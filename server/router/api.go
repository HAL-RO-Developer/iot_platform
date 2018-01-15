package router

import (
	"github.com/HAL-RO-Developer/iot_platform/server/controller"
	"github.com/HAL-RO-Developer/iot_platform/server/logger"
	"github.com/gin-gonic/gin"
)

func apiRouter(api *gin.RouterGroup) {
	ws := controller.GetHandle()

	api.Use(controller.Cros)
	api.POST("/signup", controller.CreateUserController)
	api.POST("/signin", controller.LoginController)
	api.POST("/device", controller.CreateNewProject)
	api.GET("/device", controller.GetDevice)
	api.DELETE("/device", controller.DeleteDevice)
	api.OPTIONS("/function", controller.PreflightRequest)
	api.POST("/function", controller.UserRequestController)
	api.GET("/ws/:device_id", func(c *gin.Context) {
		if !controller.UserWebSocketController(c) {
			ws(c.Writer, c.Request)
		}
	})

	device := api.Group("/device")
	device.Use(logger.JsonLogger)
	device.POST("/iam", controller.DeviceRegistration)
	device.POST("/receive", controller.DeviceReceiveController)
}
