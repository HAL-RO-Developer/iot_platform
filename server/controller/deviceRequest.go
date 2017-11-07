package controller

import (
	"net/http"

	"strconv"

	"github.com/HAL-RO-Developer/iot_platform/server/model"
	"github.com/gin-gonic/gin"
)

func DeviceRequestController(c *gin.Context) {
	userName, ok := model.AuthorityCheck(c)

	if !ok {
		c.JSON(401, gin.H{
			"err": "ログイン出来ません",
		})
		return
	}

	/*
		デバイスIDチェック
	*/
	deviceID := c.PostForm("device_id")
	ret := model.ExistDevice(userName, deviceID)
	if !ret {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "デバイスが見つかりません。",
		})
		return
	}

	for i := 0; i < len(portInfo); i++ {
		if deviceID == portInfo[i].DeviceID {
			function := strconv.FormatUint(portInfo[i].Func, 16)
			c.JSON(http.StatusOK, gin.H{
				"args": portInfo[i].Args,
				"func": function,
				"port": portInfo[i].Port,
			})
			return
		}
	}

	c.JSON(http.StatusBadRequest, gin.H{
		"err": "命令が見つかりません。",
	})
	return
}
