package controller

import (
	"net/http"

	"github.com/HAL-RO-Developer/iot_platform/server/controller/validation"
	"github.com/HAL-RO-Developer/iot_platform/server/model"
	"github.com/gin-gonic/gin"
)

func DeviceRegistration(c *gin.Context) {
	var req model.GetDevice
	err := c.BindJSON(&req)
	if err != nil {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": err,
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

	value := model.GetTaskInfo(setFunc.DeviceID)
	c.JSON(http.StatusOK, value)

	return
}
