package env

import (
	"gopkg.in/yaml.v2"
	"io/ioutil"
)

var DatabaseDriver, DatabaseSource = getDBConfig()

func getDBConfig() (string, string) {
	var buf, err = ioutil.ReadFile("dbconfig.yml")
	if err != nil {
		panic(err)
	}
	m := make(map[interface{}]interface{})
	err = yaml.Unmarshal(buf, &m)
	if err != nil {
		panic(err)
	}
	driver := m["development"].(map[interface{}]interface{})["dialect"].(string)
	source := m["development"].(map[interface{}]interface{})["datasource"].(string)
	return driver, source
}
