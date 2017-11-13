package validation

import (
	"net/http"

	"github.com/gin-gonic/gin"
	"fmt"
)

type Device struct {
	Name     string
	DeviceID string
	Mac      string
}

func SearchMyFunction(c *gin.Context) {
	/*
		デバイスIDチェック
	*/
	deviceID := c.PostForm("device_id")

	fmt.Println(len(portInfo))
	fmt.Println(portInfo[0].DeviceID)
	for i := 0; i < len(portInfo); i++ {
		if deviceID == portInfo[i].DeviceID {
			c.JSON(http.StatusOK, portInfo)
			//function := strconv.FormatUint(portInfo[i].Port.Func, 16)
			//c.JSON(http.StatusOK, gin.H{
			//	"args": portInfo[i].Port.Args,
			//	"func": function,
			//	"port": portInfo[i].Port.Id,
			//})
			return
		}
	}

	c.JSON(http.StatusBadRequest, gin.H{
		"err": "命令が見つかりません。",
	})
	return
}
