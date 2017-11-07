package controller

import (
	"net/http"
	"strconv"

	"github.com/HAL-RO-Developer/iot_platform/server/model"
	"github.com/gin-gonic/gin"
)

func UserRequestController(c *gin.Context) {
	var err error
	var index []Information

	res := model.AuthorityCheck(c)
	if res == "error" {
		c.JSON(http.StatusUnauthorized, gin.H{"error": "ログイン出来ません"})
		return
	}

	/*
		デバイスIDチェック
	*/
	deviceID := c.PostForm("device_id")
	args := c.PostForm("args")
	function, err := strconv.ParseUint(c.PostForm("func"), 0, 16)
	if err != nil {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "数字を入力してください。"})
		return
	} else if model.FunctionCheck(function) == false {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "関数IDが不正です。"})
		return
	}
	port, err := strconv.Atoi(c.PostForm("port"))
	if err != nil {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "数字を入力してください。"})
		return
	} else if port < portID_MIN || port > portID_MAX {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "ポートIDが不正です。"})
		return
	}

	if len(portInfo) != 0 {
		ret := model.ExistDevice(res, deviceID)
		if !ret {
			c.JSON(http.StatusBadRequest, gin.H{
				"err": "デバイス名が不正です。"})
			return
		} else {
			for i := 0; i < len(portInfo); i++ {
				if deviceID == portInfo[i].DeviceID {
					index = portInfo[i : i+1]
					index[0].DeviceID = deviceID
					index[0].Args = args
					index[0].Func = function
					index[0].Port = port

					c.JSON(http.StatusOK, gin.H{
						"success": ""})
					return
				}
			}
		}
	}
	portInfo = append(portInfo, Information{deviceID, args, function, port})

	c.JSON(http.StatusOK, gin.H{
		"success": ""})
	return

}

func CreateUserController(c *gin.Context) {
	// リクエストパラメーター取得
	name := c.PostForm("name")
	pass := model.ToHash(c.PostForm("password"))

	// 作成済みユーザーか？
	if model.ExistUserByName(name) {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "登録済みのユーザーネームです",
		})
		return
	}

	//DBinsert
	err := model.CreateUser(name, pass)
	if err != nil {
		c.JSON(http.StatusInternalServerError, gin.H{
			"err": "データベースエラー",
		})
		return
	}

	token, err := model.CreateTokenString(name)
	if err != nil {
		c.JSON(http.StatusInternalServerError, gin.H{"err": "アクセストークンを作成できませんでした"})
		return
	}

	c.JSON(http.StatusOK, gin.H{
		"success": token,
	})
}

func LoginController(c *gin.Context) {
	name := c.PostForm("name")
	pass := c.PostForm("password")

	pass = model.ToHash(pass)

	if model.CheckLogin(name, pass) {
		token := model.CreateTokenString(name)
		c.JSON(http.StatusOK, gin.H{
			"success": token})

		return
	}
	c.JSON(http.StatusBadRequest, gin.H{
		"fail": "ユーザー名またはパスワードが間違っています"})
	return
}

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
