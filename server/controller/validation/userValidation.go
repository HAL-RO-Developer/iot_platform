package validation

import (
	"net/http"

	"github.com/HAL-RO-Developer/iot_platform/server/model"
	"github.com/gin-gonic/gin"
)

type User struct {
	Name string
	Pass string
}

func ToUser(c *gin.Context) (*User, bool) {
	name := c.PostForm("name")
	if name == "" {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "nameが未入力です",
		})
		return nil, false
	}
	pass := c.PostForm("password")
	if pass == "" {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "passが未入力です",
		})
		return nil, false
	}
	pass = model.ToHash(pass)

	return &User{
		Name: name,
		Pass: pass,
	}, true
}
