package controller

import (
	"net/http"
	"strconv"

	"github.com/HAL-RO-Developer/iot_platform/server/controller/validation"
	"github.com/HAL-RO-Developer/iot_platform/server/model"
	"github.com/gin-gonic/gin"
)

func UserRequestController(c *gin.Context) {
	var err error
	var index []Information

	userName, ok := model.AuthorityCheck(c)
	if !ok {
		c.JSON(http.StatusUnauthorized, gin.H{
			"err": "ログイン出来ません",
		})
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
			"err": "数字を入力してください。",
		})
		return
	} else if model.FunctionCheck(function) == false {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "関数IDが不正です。",
		})
		return
	}
	port, err := strconv.Atoi(c.PostForm("port"))
	if err != nil {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "数字を入力してください。",
		})
		return
	} else if port < portID_MIN || port > portID_MAX {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "ポートIDが不正です。",
		})
		return
	}

	if len(portInfo) != 0 {
		ret := model.ExistDevice(userName, deviceID)
		if !ret {
			c.JSON(http.StatusBadRequest, gin.H{
				"err": "デバイス名が不正です。",
			})
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
						"success": "",
					})
					return
				}
			}
		}
	}
	portInfo = append(portInfo, Information{deviceID, args, function, port})

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

	//DBinsert
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

	//TODO macアドレスの処理後で書く
	mac := "00000"
	err := model.CreateDevice(userName, deviceID, mac)
	if err != nil {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "データベースエラー"})
		return
	}
	c.JSON(http.StatusOK, gin.H{
		"success": "登録完了",
	})
}
