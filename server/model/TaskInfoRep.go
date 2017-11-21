package model

import "sync"

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
	DeviceID string `json:"device_id"`
	MacAddr  string `json:"mac"`
}

var taskInfo = []TaskInfo{}
var portInfoM = new(sync.Mutex)

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

func GetTaskInfo(device_id string) *TaskInfo {
	for _, value := range taskInfo {
		if value.DeviceID == device_id {
			return &value
		}
	}
	return nil
}
