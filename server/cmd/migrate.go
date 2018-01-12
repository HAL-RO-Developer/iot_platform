package main

import "github.com/HAL-RO-Developer/iot_platform/server/model"

func main() {
	model.DB.AutoMigrate(&model.User{})
	model.DB.AutoMigrate(&model.Device{})
}
