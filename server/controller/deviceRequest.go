package controller

import (
	"net/http"

	"github.com/HAL-RO-Developer/iot_platform/server/controller/validation"
	"github.com/HAL-RO-Developer/iot_platform/server/model"
	"github.com/gin-gonic/gin"
)

func DeviceRegistration(c *gin.Context) {
	var req model.GetDevice
	var ok bool

	req.DeviceID, ok = validation.PermissionMyDevice(c)
	if !ok {
		return
	}
	res := model.ExistDeviceByIam(req.DeviceID, "")
	if !res {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "デバイスが見つかりません。",
		})
		return
	}
	model.AdditionalDevice(req.MacAddr)

	c.JSON(http.StatusOK, gin.H{
		"success": true,
	})
	return
}

func DeviceRequestController(c *gin.Context) {

	setFunc, ok := validation.SearchMyFunction(c)
	if !ok {
		return
	}
	/*
		デバイスIDチェック
	*/
	res := model.ExistDeviceByIam(setFunc.DeviceID, setFunc.MacAddr)
	if !res {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "デバイスが見つかりません。",
		})
		return
	}

	value := model.GetTaskInfo(setFunc.DeviceID)
	c.JSON(http.StatusOK, value)

	return
}

func DeviceSend(c *gin.Context) {

	req, ok := validation.SearchMe(c)
	if !ok {
		return
	} /*
		デバイスIDチェック
	*/
	res := model.ExistDeviceByIam(req.DeviceID, req.MacAddr)
	if !res {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "デバイスが見つかりません。",
		})
		return
	}

	return
}
