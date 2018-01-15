package router

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

func Getrouter() *gin.Engine {
	r := gin.Default()
	r.Static("/js", "./public/js")
	r.Static("/image", "./public/image")
	r.Static("/css", "./public/css")
	r.Static("/fonts", "./public/fonts")

	r.LoadHTMLGlob("view/*")

	r.GET("/", func(c *gin.Context) {
		c.HTML(http.StatusOK, "index.html", nil)
	})

	user := r.Group("/user/:name")
	user.GET("/dashboard", func(c *gin.Context) {
		c.HTML(http.StatusOK, "dashboard.html", nil)
	})

	api := r.Group("/api")
	apiRouter(api)

	return r
}
