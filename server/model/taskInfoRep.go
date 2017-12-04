package model

import (
	"sync"
)

type TaskInfo struct {
	Err      string     `json:"err"`
	Success  string     `json:"success"`
	Port     []PortTask `json:"port"`
	DeviceID string     `json:"device_id"`
}

type PortTask struct {
	PortNo int      `json:"port_no"`
	Func   uint64   `json:"function"`
	Args   []string `json:"args"`
}

type GetDevice struct {
	Pin     string `json:"pin"`
	MacAddr string `json:"mac"`
}

type Message struct {
	DeviceID string `json:"device_id"`
	MacAddr  string `json:"mac"`
	PortNo   string `json:"port_no"`
	Func     string `json:"function"`
	Res      string `json:"res"`
}

var taskInfo = []TaskInfo{}
var message = []Message{}
var portInfoM = new(sync.Mutex)
var returnValueM = new(sync.Mutex)

func SetTaskInfo(device_id string, task []PortTask) {
	portInfoM.Lock()
	flg := true
	for _, value := range taskInfo {
		if value.DeviceID == device_id {
			flg = false
			value.Port = task
		}
	}
	if flg {
		taskInfo = append(taskInfo, TaskInfo{DeviceID: device_id, Port: task})
	}
	portInfoM.Unlock()
}

/*
	自身への命令取得
*/
func GetTaskInfo(device_id string) []PortTask {
	for _, value := range taskInfo {
		if value.DeviceID == device_id {
			return value.Port
		}
	}
	return nil
}

/*

 */
func GetValueInfo(device_id string) *Message {
	for _, value := range message {
		if value.DeviceID == device_id {
			return &value
		}
	}
	return nil
}
