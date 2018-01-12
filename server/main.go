package main

import "github.com/HAL-RO-Developer/iot_platform/server/router"

func main() {
	r := router.Getrouter()
	r.Run()
}
