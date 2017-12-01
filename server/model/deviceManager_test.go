package model

import (
	"fmt"
	"testing"
)

func TestUpdateDeviceMacById(t *testing.T) {
	DB.AutoMigrate(&User{})
	DB.AutoMigrate(&Device{})
	device, _ := CreateDevice("makki")
	fmt.Println(device)
	err := UpdateDeviceMacById(device.Pin, "makkidayo--")
	if err != nil {
		panic(err)
	}
}
