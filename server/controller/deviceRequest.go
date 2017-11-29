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

	req, ok = validation.PermissionMyDevice(c)
	if !ok {
		return
	}
	res := model.ExistDeviceByIam(req.DeviceID, "")
	if !res {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "デバイスIDが不正です。",
		})
		return
	}

	model.AdditionalDevice(req.MacAddr)

	c.JSON(http.StatusOK, gin.H{
		"success": true,
	})
	return
}

func DeviceReceiveController(c *gin.Context) {

	// デバイスへの命令検索
	req, ok := validation.SearchMyFunction(c)
	if !ok {
		return
	}

	// デバイスの登録チェック(未登録時エラーを返す)
	ret := model.ExistDeviceByIam(req.DeviceID, "")
	if ret {
		c.JSON(http.StatusForbidden, gin.H{
			"err": "デバイスが登録されていません。",
		})
		return
	}

	// デバイスIDチェック
	res := model.ExistDeviceByIam(req.DeviceID, req.MacAddr)
	if !res {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "デバイスIDが使用済みです。",
		})
		return
	}

	// 命令取得
	value := model.GetTaskInfo(req.DeviceID)
	c.JSON(http.StatusOK, gin.H{
		"success": value,
	})

	// センサー値等の一時保存
	model.ReturnValueInfo(req.DeviceID, req.Value)

	return
}
