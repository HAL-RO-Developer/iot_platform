package controller

import (
	"net/http"

	"strconv"

	"github.com/Komei1009/IoTPlatform/model"
	"github.com/gin-gonic/gin"
)

func CreateNewProject(c *gin.Context) {
	res := model.AuthorityCheck(c)

	if res == "error" {
		c.JSON(401, gin.H{"error": "ログイン出来ません"})
		return
	}

	deviceID := model.CreateDeviceID()

	mac := "00000"
	err := model.CreateDevice(res, deviceID, mac)
	if err != nil {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "データベースエラー"})
		return
	}
	c.JSON(http.StatusOK, gin.H{
		"success": "登録完了"})
}

func DeviceRequestController(c *gin.Context) {
	res := model.AuthorityCheck(c)

	if res == "error" {
		c.JSON(401, gin.H{"error": "ログイン出来ません"})
		return
	}

	/*
		デバイスIDチェック
	*/
	deviceID := c.PostForm("device_id")
	ret := model.ExistDeviceById(deviceID)
	if !ret {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "デバイスが見つかりません。"})
		return
	}

	for i := 0; i < len(portInfo); i++ {
		if deviceID == portInfo[i].DeviceID {
			function := strconv.FormatUint(portInfo[i].Func, 16)
			c.JSON(http.StatusOK, gin.H{
				"args": portInfo[i].Args,
				"func": function,
				"port": portInfo[i].Port})
			return
		}
	}

	c.JSON(http.StatusBadRequest, gin.H{
		"err": "命令が見つかりません。"})
	return
}
