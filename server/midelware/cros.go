package middleware

import (
	"github.com/itsjamie/gin-cors"
	"time"
)

var CorsConfig = cors.Config{
	Origins:         "*",
	Methods:         "GET, PUT, POST, DELETE, OPTIONS",
	RequestHeaders:  "Origin, Authorization, Content-Type",
	ExposedHeaders:  "",
	MaxAge:          50 * time.Second,
	Credentials:     true,
	ValidateHeaders: false,
}
