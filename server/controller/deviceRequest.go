package controller

import (
	"fmt"
	"net/http"

	"github.com/HAL-RO-Developer/iot_platform/server/controller/validation"
	"github.com/HAL-RO-Developer/iot_platform/server/model"
	"github.com/gin-gonic/gin"
	"gopkg.in/olahol/melody.v1"
)

func DeviceRegistration(c *gin.Context) {
	var req model.GetDevice
	var ok bool

	req, ok = validation.PermissionMyDevice(c)
	if !ok {
		return
	}
	res := model.ExistDeviceByPin(req.Pin)
	if !res {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "pinが不正です",
		})
		return
	}

	device, err := model.UpdateDeviceMacById(req.Pin, req.MacAddr)
	if err != nil {
		panic(err)
	}

	c.JSON(http.StatusOK, gin.H{
		"device_id": device.DeviceID,
	})
	return
}

func DeviceReceiveController(c *gin.Context, m *melody.Melody) {
	// デバイスへの命令検索
	req, ok := validation.SearchMyFunction(c)
	if !ok {
		fmt.Println("test")
		return
	}

	// デバイスの登録チェック(未登録時エラーを返す)
	ret := model.ExistDeviceByIam(req.DeviceID, "")
	if ret {
		fmt.Println("test2")
		c.JSON(http.StatusForbidden, gin.H{
			"err": "デバイスが登録されていません。",
		})
		return
	}

	// デバイスIDチェック
	res := model.ExistDeviceByIam(req.DeviceID, req.MacAddr)
	if !res {
		fmt.Println("test3")
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

	dev := []byte(req.DeviceID)
	port := []byte(req.PortNo)
	function := []byte(req.Func)
	result := []byte(req.Res)

	//msg := []byte(req.DeviceID)
	m.Broadcast(dev)
	m.Broadcast(port)
	m.Broadcast(function)
	m.Broadcast(result)
	//m.Broadcast(msg1)
	return
}
