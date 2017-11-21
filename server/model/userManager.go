package model

import (
	"github.com/jinzhu/gorm"
)

var funcID = []uint64{0x00, 0x51, 0x52, 0x53, 0x61, 0x62, 0x91, 0x92, 0x93, 0xA1, 0xA2, 0x01, 0x11, 0x21, 0x02, 0xC1, 0xD1, 0xE1}

/* ユーザー情報 */
type User struct {
	gorm.Model
	Name     string
	Password string
}

/*
	ユーザー情報登録
*/
func CreateUser(name string, password string) error {
	user := User{
		Name:     name,
		Password: password,
	}
	return DB.Create(&user).Error
}

/*
	DBからユーザーネームを探す
*/
func ExistUserByName(name string) bool {

	users := []User{}
	DB.Find(&users, "name = ?", name)

	return (len(users) != 0)
}

/*

 */
func CheckLogin(name string, password string) bool {

	users := []User{}
	DB.Find(&users, "name = ?", name)
	if len(users) != 0 {
		if password == users[0].Password {
			return true
		}
	}
	return false
}
