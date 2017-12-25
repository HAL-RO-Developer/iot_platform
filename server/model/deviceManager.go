package model

import (
	"math/rand"

	"time"

	"github.com/jinzhu/gorm"
)

/* デバイス情報 */
type Device struct {
	gorm.Model
	Name       string
	DeviceName string
	DeviceID   string
	Pin        string
	Mac        string
}

func CreateDevice(name string, deviceName string) (Device, error) {
	deviceID := CreateDeviceID()
	pin := CreateDevicePin()

	device := Device{
		Name:       name,
		DeviceID:   deviceID,
		DeviceName: deviceName,
		Mac:        "",
		Pin:        pin,
	}
	err := DB.Create(&device).Error
	return device, err
}

func GetDeviceByUserName(name string) []Device {
	var devices []Device
	DB.Where("name = ?", name).Find(&devices)
	return devices
}

func CreateDevicePin() string {
	var pin string
	for {
		pin = CreateUuid(4, []rune("0123456789"))
		if !ExistDeviceByPin(pin) {
			break
		}
	}
	return pin
}

func ExistDeviceByPin(pin string) bool {
	var device []Device
	DB.Where("pin = ?", pin).Find(&device)
	return len(device) > 0
}

func CreateDeviceID() string {
	var deviceID string
	for {
		deviceID = CreateUuid(32, []rune("ABCDEFGHRJKLNMOPQRSTUPWXYZabcdefghijklmnopqrstuvwxyz0123456789"))
		if !ExistDeviceById(deviceID) {
			break
		}
	}
	return deviceID
}

func CreateUuid(length int, letters []rune) string {
	rand.Seed(time.Now().UnixNano())
	b := make([]rune, length)
	for i := range b {
		b[i] = letters[rand.Intn(len(letters))]
	}
	return string(b)
}

func ExistDeviceById(id string) bool {

	device := []Device{}
	DB.Find(&device, "device_id = ?", id)
	if len(device) != 0 {
		return true
	}
	return false
}

func ExistDevice(name string, deviceid string) bool {

	device := []Device{}
	DB.Find(&device, "name = ? and device_id = ?", name, deviceid)
	if len(device) != 0 {
		return true
	}
	return false
}

func ExistDeviceByIam(deviceid string, macaddr string) bool {
	device := []Device{}
	DB.Find(&device, "device_id = ? and mac = ?", deviceid, macaddr)
	if len(device) != 0 {
		return true
	}
	return false
}

func UpdateDeviceMacById(pin string, mac string) (*Device, error) {
	device := Device{}
	err := DB.Where("pin = ?", pin).First(&device).Error
	if err != nil {
		panic(err)
		return nil, err
	}
	device.Mac = mac
	err = DB.Model(&device).Update(&device).Update("pin", "").Error
	return &device, err
}

func DeleteDeviceById(user string, deviceId string) bool {
	device := Device{}

	device.DeviceID = deviceId
	DB.Where("name = ? and device_id = ?", user, deviceId).First(&device)
	DB.Delete(&device)
	return true
}
