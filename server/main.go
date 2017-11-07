package main

import (
	"github.com/HAL-RO-Developer/iot_platform/server/controller"
	"github.com/HAL-RO-Developer/iot_platform/server/model"
	"github.com/gin-gonic/gin"
)

// TODO 後で消す
type Test struct {
	Name string `json:"name"`
	Foo  Foo    `json:"foo"`
}
type Foo struct {
	Id   uint   `json:"id"`
	Pass string `json:"pass"`
}

func main() {
	model.DB.AutoMigrate(&model.User{})
	model.DB.AutoMigrate(&model.Device{})

	r := gin.Default()
	// TODO 後で消す
	r.GET("/test", func(c *gin.Context) {
		foo := Foo{
			Id:   23,
			Pass: "hoge",
		}
		test := Test{
			Name: "こうめい",
			Foo:  foo,
		}
		c.JSON(200, test)
	})
	api := r.Group("/api")

	api.POST("/signup", controller.CreateUserController)
	api.POST("/signin", controller.LoginController)
	api.POST("/device", controller.CreateNewProject)
	api.POST("/function", controller.UserRequestController)

	device := r.Group("/device")
	device.POST("/receive", controller.DeviceRequestController)

	r.Run()
}
