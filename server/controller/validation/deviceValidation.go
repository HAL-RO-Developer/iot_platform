package validation

import (
	"net/http"

	"github.com/HAL-RO-Developer/iot_platform/server/model"
	"github.com/gin-gonic/gin"
)

func PermissionMyDevice(c *gin.Context) (model.GetDevice, bool) {
	var req model.GetDevice
	err := c.BindJSON(&req)
	if err != nil {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": err,
		})
		return req, false
	}

	return req, true
}

/*
	デバイス側
*/
func SearchMyFunction(c *gin.Context) (model.Message, bool) {
	var req model.Message
	err := c.BindJSON(&req)
	if err != nil {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": "ここでえらー01",
		})
		return req, false
	}

	req.DeviceID = req.DeviceID
	req.MacAddr = req.MacAddr

	return req, true
}

func SearchMe(c *gin.Context) (model.Message, bool) {
	var res model.Message

	err := c.BindJSON(&res)
	if err != nil {
		return res, false
	}

	return res, true
}
