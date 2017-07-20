package main

import (
	"github.com/gin-gonic/gin"
	"github.com/itsjamie/gin-cors"
	"github.com/HAL-RO-Developer/iot_platform/server/midelware"
	"github.com/HAL-RO-Developer/iot_platform/server/websocket"
	"github.com/HAL-RO-Developer/iot_platform/server/socket"
)

func main() {
	//gin.SetMode(gin.ReleaseMode)
	go socket.ServerInit(1234)
	webRouter := createRouter()
	webRouter.Run(":3000")
}

func createRouter() *gin.Engine{
	r := gin.Default()
	r.Static("/js", "./public/js")
	r.Static("/image", "./public/image")
	r.Static("/css", "./public/css")

	r.LoadHTMLGlob("view/*")
	//ウェルカムページ
	r.GET("/", func(c *gin.Context) {
		c.HTML(200, "index.html", nil)
	})
	//wsハンドラ
	r.GET("/ws", func(c *gin.Context) {
		websocket.GetHandle()(c.Writer, c.Request)
	})
	api := r.Group("/api")
	// crosの許可
	api.Use(cors.Middleware(middleware.CorsConfig))
	api.GET("/makki", func(c *gin.Context) {
		c.JSON(200, gin.H{
			"name":  "katsuramaki taiki",
			"sex":   "man",
			"email": "llxo2_5oxll@icloud.com",
		})
	})
	return r
}