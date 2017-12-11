package main

import "github.com/HAL-RO-Developer/iot_platform/server/model"

func main() {
	db := model.DB
	db.DropTableIfExists(&model.User{})
	db.DropTableIfExists(&model.Device{})
}
