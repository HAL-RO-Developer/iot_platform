package validation

import (
	"net/http"

	"github.com/HAL-RO-Developer/iot_platform/server/model"
	"github.com/gin-gonic/gin"
)

func SearchMyDevice(c *gin.Context) (string, bool) {
	var req model.GetDevice
	err := c.BindJSON(&req)
	if err != nil {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": err,
		})
		return "", false
	}
	res := model.ExistDeviceByIam(req.DeviceID, "")
	if !res {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "デバイスが見つかりません。",
		})
		return "", false
	}

	return req.DeviceID, true
}

// TODO なんとかしろ
func SearchMyFunction(c *gin.Context) (*SetFunc, bool) {
	var req model.GetDevice
	err := c.BindJSON(&req)
	if err != nil {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": err,
		})
		return nil, false
	}
	/*
		デバイスIDチェック
	*/
	res := model.ExistDeviceById(req.DeviceID)
	if !res {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "デバイスが見つかりません。",
		})
		return nil, false
	}

	return &SetFunc{
		DeviceID: req.DeviceID,
		Port:     []model.PortTask{},
	}, true
}
