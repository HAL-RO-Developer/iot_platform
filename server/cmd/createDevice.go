package main

import (
	"fmt"

	"github.com/HAL-RO-Developer/iot_platform/server/model"
)

func main() {
	device, err := model.CreateDevice("tanaka")
	if err != nil {
		panic(err)
	}
	fmt.Printf("Pin: %s", device.Pin)
}
