package controller

import (
	"net/http"

	"time"

	"github.com/HAL-RO-Developer/iot_platform/server/controller/validation"
	"github.com/HAL-RO-Developer/iot_platform/server/model"
	"github.com/gin-gonic/gin"
)

type Result struct {
	Result  string        `json:"result"`
	Time    time.Time     `json:"time"`
	Message model.Message `json:"message"`
}

type Task struct {
	PortNo uint16   `json:"port"`
	Func   uint16   `json:"function"`
	Args[] int16  	`json:"args"`
}

func UserRequestController(c *gin.Context) {
	user, ok := model.AuthorityCheck(c)
	if !ok {
		c.JSON(http.StatusUnauthorized, gin.H{
			"err": "ログイン出来ません",
		})
		return
	}

	/* デバイスIDサーチ */
	setFunc, ok := validation.ToFunction(c, user)
	if !ok {
		return
	}
	model.SetTaskInfo(setFunc.DeviceID, setFunc.Port)

	c.JSON(http.StatusOK, gin.H{
		"success": "",
	})
	return
}

func CreateUserController(c *gin.Context) {
	// リクエストパラメーター取得
	user, ok := validation.ToUser(c)
	if !ok {
		return
	}
	// 作成済みユーザーか？
	if model.ExistUserByName(user.Name) {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "登録済みのユーザーネームです",
		})
		return
	}

	user.Pass = model.ToHash(user.Pass)

	// DBinsert
	err := model.CreateUser(user.Name, user.Pass)
	if err != nil {
		c.JSON(http.StatusInternalServerError, gin.H{
			"err": "データベースエラー",
		})
		return
	}

	token, err := model.CreateTokenString(user.Name)
	if err != nil {
		c.JSON(http.StatusInternalServerError, gin.H{
			"err": "アクセストークンを作成できませんでした",
		})
		return
	}

	c.JSON(http.StatusOK, gin.H{
		"token": token,
	})
}

func LoginController(c *gin.Context) {
	// リクエストパラメータチェック
	user, ok := validation.ToUser(c)
	if !ok {
		return
	}

	user.Pass = model.ToHash(user.Pass)

	// ログインチェック
	if !model.CheckLogin(user.Name, user.Pass) {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "ユーザー名またはパスワードが間違っています",
		})
		return
	}

	// トークンを生成
	token, err := model.CreateTokenString(user.Name)
	if err != nil {
		c.JSON(http.StatusInternalServerError, gin.H{
			"err": err,
		})
	}

	c.JSON(http.StatusOK, gin.H{
		"token": token,
	})
}

func CreateNewProject(c *gin.Context) {
	userName, ok := model.AuthorityCheck(c)
	deviceName := c.PostForm("device_name")
	if !ok {
		c.JSON(401, gin.H{
			"err": "ログイン出来ません",
		})
		return
	}
	device, err := model.CreateDevice(userName, deviceName)
	if err != nil {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "データベースエラー"})
		return
	}
	c.JSON(http.StatusOK, gin.H{
		"pin": device.Pin,
	})
}
func GetDevice(c *gin.Context) {
	userName, ok := model.AuthorityCheck(c)
	if !ok {
		c.JSON(401, gin.H{
			"err": "ログイン出来ません",
		})
		return
	}
	c.JSON(http.StatusOK, gin.H{
		"devices": model.GetDeviceByUserName(userName),
	})
}
func UserWebSocketController(c *gin.Context) bool {

	/* デバイスIDサーチ */
	setFunc, ok := validation.ToReturn(c)
	if !ok {
		return false
	}

	res := model.ExistDeviceById(setFunc.DeviceID)
	if !res {
		return false
	}
	return true
}
