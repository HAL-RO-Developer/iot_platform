package logger

import (
	"fmt"

	"github.com/gin-gonic/gin"
)

func JsonLogger(c *gin.Context) {
	s, _ := c.GetRawData()
	fmt.Println(string(s))
}
