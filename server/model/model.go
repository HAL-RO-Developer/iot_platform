package model

import (
	_ "github.com/go-sql-driver/mysql"
	"github.com/jinzhu/gorm"
	"github.com/makki0205/web/env"
)

var db = NewDBConn()

func NewDBConn() *gorm.DB {
	db, err := gorm.Open(env.DatabaseDriver, env.DatabaseSource)
	if err != nil {
		panic(err)
	}
	return db
}

func GetDBConn() *gorm.DB {
	return db
}
