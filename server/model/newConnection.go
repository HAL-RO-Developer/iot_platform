package model

import (
	"crypto/sha256"
	"encoding/hex"

	_ "github.com/go-sql-driver/mysql"
	"github.com/jinzhu/gorm"
)

var DB = newConnection()

func newConnection() *gorm.DB {
	db, err := gorm.Open("mysql", "root:@/iotplatform?charset=utf8&parseTime=True&loc=Local")
	if err != nil {
		panic(err)
	}

	return db
}

func ToHash(pass string) string {
	converted := sha256.Sum256([]byte(pass))
	return hex.EncodeToString(converted[:])
}
