package model

import (
	"crypto/rand"
	"encoding/base64"

	"github.com/jinzhu/gorm"
)

/* デバイス情報 */
type Device struct {
	gorm.Model
	Name     string
	DeviceID string
	Mac      string
}

func CreateDevice(name string, deviceID string, mac string) error {
	device := Device{
		Name:     name,
		DeviceID: deviceID,
		Mac:      mac,
	}
	return DB.Create(&device).Error
}

func CreateDeviceID() string {
	len := 15
	random := make([]byte, len)
	rand.Read(random)

	deviceID := "sample"
	var res bool = true

	for res {
		deviceID = base64.URLEncoding.EncodeToString(random)
		res = existDeviceById(deviceID)
	}

	return deviceID
}

func existDeviceById(id string) bool {

	device := []Device{}
	DB.Find(&device, "device_id = ?", id)
	if len(device) != 0 {
		return true
	}

	return false
}

func ExistDevice(name string, id string) bool {

	device := []Device{}
	DB.Find(&device, "name = ? and device_id = ?", name, id)
	if len(device) != 0 {
		return true
	}

	return false
}
