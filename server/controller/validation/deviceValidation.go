package validation

import (
	"net/http"

	"github.com/HAL-RO-Developer/iot_platform/server/model"
	"github.com/gin-gonic/gin"
)

func SearchMyDevice(c *gin.Context) (string, bool) {
	deviceID := c.PostForm("device_id")
	res := model.ExistDeviceByIam(deviceID, "")
	if !res {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "デバイスが見つかりません。",
		})
		return "", false
	}

	return deviceID, true
}

func SearchMyFunction(c *gin.Context) (*SetFunc, bool) {
	/*
		デバイスIDチェック
	*/
	deviceID := c.PostForm("device_id")
	res := model.ExistDeviceById(deviceID)
	if !res {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "デバイスが見つかりません。",
		})
		return nil, false
	}

	return &SetFunc{
		DeviceID: deviceID,
		Port:     []model.PortTask{},
	}, true
}
