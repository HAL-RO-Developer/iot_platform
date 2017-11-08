package validation

import (
	"net/http"

	"github.com/HAL-RO-Developer/iot_platform/server/model"
	"github.com/gin-gonic/gin"
	"strconv"
)

type User struct {
	Name string
	Pass string
}

/*
	ユーザー情報入力チェック＆パスワード暗号化
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
	pass = model.ToHash(pass)

	return &User{
		Name: name,
		Pass: pass,
	}, true
}

/*
	関数への入力情報チェック
 */
func ToFunction(c *gin.Context) bool {

	function, err := strconv.ParseUint(c.PostForm("func"), 0, 16)
	if err != nil {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "数字を入力してください。",
		})
		return false
	} else if model.FunctionCheck(function) == false {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "関数IDが不正です。",
		})
		return false
	}
	return true

	port, err := strconv.Atoi(c.PostForm("port"))
	if err != nil {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "数字を入力してください。",
		})
		return false
	} else if port < portID_MIN || port > portID_MAX {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "ポートIDが不正です。",
		})
		return false
	}
	res := searchDevice(c)
	return res
}

/*
	デバイスID探し
 */
func searchDevice (c *gin.Context) bool {
	deviceID := c.PostForm("device_id")
	args := c.PostForm("args")
	function, _ := strconv.ParseUint(c.PostForm("func"), 0, 16)
	port, _ := strconv.Atoi(c.PostForm("port"))
	userName,_ := model.AuthorityCheck(c)

	var index []Information

	if len(portInfo)!= 0 {
		ret := model.ExistDevice(userName,deviceID)

		if !ret {
			c.JSON(http.StatusBadRequest, gin.H{
				"err": "デバイスIDが見つかりません",
			})
			return false
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
					return true
				}
			}
		}
	}
	portInfo = append(portInfo, Information{deviceID, args, function, port})

	c.JSON(http.StatusOK, gin.H{
		"success": ""})
	return true

}
