package model

import (
	_ "github.com/go-sql-driver/mysql"
	"github.com/jinzhu/gorm"
)

var db = NewDBConn()

func NewDBConn() *gorm.DB {
	db, err := gorm.Open("mysql", "root:password@tcp(127.0.0.1:3306)/{dbname}?parseTime=true")
	if err != nil {
		panic(err)
	}
	return db
}

func GetDBConn() *gorm.DB {
	return db
}
