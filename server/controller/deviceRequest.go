package controller

import (
	"net/http"

	"github.com/HAL-RO-Developer/iot_platform/server/controller/validation"
	"github.com/HAL-RO-Developer/iot_platform/server/model"
	"github.com/gin-gonic/gin"
)

func DeviceRegistration(c *gin.Context) {
	_, ok := validation.SearchMyDevice(c)
	if !ok {
		return
	}

	macaddr := c.PostForm("mac")
	model.AdditionalDevice(macaddr)

	c.JSON(http.StatusOK, gin.H{
		"success": "",
	})
	return
}

func DeviceRequestController(c *gin.Context) {

	setFunc, ok := validation.SearchMyFunction(c)
	if !ok {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "失敗",
		})
		return
	}

	value := model.GetTaskInfo(setFunc.DeviceID)
	c.JSON(http.StatusOK, value)

	return
}
