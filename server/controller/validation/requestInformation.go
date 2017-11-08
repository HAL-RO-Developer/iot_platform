package validation

/* 関数情報 */
type Information struct {
	DeviceID string
	Args     string
	Func     uint64
	Port     int
}

const portID_MIN = 1
const portID_MAX = 4

/* 構造体定義 */
var portInfo = []Information{}
