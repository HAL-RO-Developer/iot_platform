package main

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

type Receive struct {
	Err     string `json:"err"`
	Success bool   `json:"success"`
	Port    []Port `json:"port"`
}
type Port struct {
	PortNo   int   `json:"port_no"`
	Function int   `json:"function"`
	Args     []int `json:"args"`
}

func main() {

	r := gin.Default()

	device := r.Group("/device")
	device.POST("/receive", func(c *gin.Context) {
		var ports []Port
		ports = append(ports, createPort(1, 82, []int{1, 5000}))
		ports = append(ports, createPort(2, 161, []int{}))
		ports = append(ports, createPort(3, 0, []int{}))
		ports = append(ports, createPort(1, 0, []int{}))
		rec := Receive{
			Err:     "",
			Success: true,
			Port:    ports,
		}
		c.JSON(http.StatusOK, rec)
	})
	r.Run(":3000")
}

func createPort(p, f int, a []int) Port {
	return Port{
		PortNo:   p,
		Function: f,
		Args:     a,
	}
}
