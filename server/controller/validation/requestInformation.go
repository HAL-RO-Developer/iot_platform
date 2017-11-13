package validation

/* 関数情報 */
type Information struct {
	Err      string `json:"err"`
	Success  string `json:"success"`
	Port     Port   `json:"port"`
	DeviceID string
}

type Port struct {
	Id   int    `json:"port"`
	Func uint64 `json:"function"`
	Args int    `json:"args"`
}

const portID_MIN = 1
const portID_MAX = 4

/* 構造体定義 */
var portInfo = []Information{}

// var DeviceID[] string
