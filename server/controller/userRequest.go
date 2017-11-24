package controller

import (
	"net/http"

	"github.com/HAL-RO-Developer/iot_platform/server/controller/validation"
	"github.com/HAL-RO-Developer/iot_platform/server/model"
	"github.com/gin-gonic/gin"
)

type Task struct {
	PortNo int    `json:"port_no"`
	Func   uint64 `json:"function"`
	Args   int    `json:"args"`
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

	res := model.ExistDeviceById(setFunc.DeviceID)
	if !res {
		c.JSON(http.StatusBadRequest, gin.H{
			"success": "",
		})
		return
	}
	c.JSON(http.StatusOK, gin.H{
		"success": validation.Message{},
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

	if !ok {
		c.JSON(401, gin.H{
			"err": "ログイン出来ません",
		})
		return
	}

	deviceID := model.CreateDeviceID()

	// macアドレス仮登録
	mac := ""
	err := model.CreateDevice(userName, deviceID, mac)
	if err != nil {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "データベースエラー"})
		return
	}
	c.JSON(http.StatusOK, gin.H{
		"success": deviceID,
	})
}
