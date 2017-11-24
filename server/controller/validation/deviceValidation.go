package validation

import (
	"net/http"

	"github.com/HAL-RO-Developer/iot_platform/server/model"
	"github.com/gin-gonic/gin"
)

type Message struct {
	DeviceID string `json:device_id`
	MacAddr  string `json:mac`
	PortNo   int    `json:"port_no"`
	Func     uint64 `json:"function"`
	Res      int    `json:"res"`
}

func PermissionMyDevice(c *gin.Context) (string, bool) {
	var req model.GetDevice
	err := c.BindJSON(&req)
	if err != nil {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": err,
		})
		return "", false
	}

	return req.DeviceID, true
}

// TODO なんとかしろ
func SearchMyFunction(c *gin.Context) (*SetFunc, bool) {
	var req model.GetDevice
	err := c.BindJSON(&req)
	if err != nil {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": err,
		})
		return nil, false
	}

	return &SetFunc{
		DeviceID: req.DeviceID,
		MacAddr:  req.MacAddr,
		Port:     []model.PortTask{},
	}, true
}

func SearchMe(c *gin.Context) (*Message, bool) {
	var req Message
	err := c.BindJSON(&req)
	if err != nil {
		c.JSON(http.StatusBadRequest, gin.H{
			"err": err,
		})
		return nil, false
	}

	return &req, true
}
