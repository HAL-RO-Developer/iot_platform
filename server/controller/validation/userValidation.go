package validation

import (
	"net/http"

	"github.com/HAL-RO-Developer/iot_platform/server/model"
	"github.com/gin-gonic/gin"
)

type User struct {
	Name string
	Pass string
}

type SetFunc struct {
	DeviceID string           `json:"device_id"`
	MacAddr  string           `json:"mac"`
	Port     []model.PortTask `json:"port"`
}

/*
	ユーザー情報入力チェック
*/
func ToUser(c *gin.Context) (*User, bool) {
	name := c.PostForm("name")
	if name == "" {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "nameが未入力です",
		})
		return nil, false
	}
	pass := c.PostForm("password")
	if pass == "" {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "passが未入力です",
		})
		return nil, false
	}

	return &User{
		Name: name,
		Pass: pass,
	}, true
}

/*
	関数への入力情報チェック
*/
func ToFunction(c *gin.Context, user string) (*SetFunc, bool) {
	var req SetFunc
	//err := c.BindJSON(&req)
	//if err != nil {
	//	c.JSON(http.StatusBadRequest, gin.H{
	//		"err": err,
	//	})
	//	return nil, false
	//}

	deviceId := c.PostForm("device_id")
	// DeviceID確認
	if !model.ExistDevice(user, deviceId) {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "デバイスが見つかりません",
		})
		return nil, false
	}
	return &req, true
}

/*
	デバイスから結果返却
*/
func ToReturn(c *gin.Context) (*model.Message, bool) {
	var req model.Message

	deviceId := c.Param("device_id")
	// DeviceID確認
	if !model.ExistDeviceById(deviceId) {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "デバイスが見つかりません",
		})
		return nil, false
	}
	return &req, true
}
