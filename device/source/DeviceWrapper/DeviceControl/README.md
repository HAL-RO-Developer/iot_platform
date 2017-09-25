
# ライブラリの追加方法
1. [スケッチ]-[ライブラリをインクルード]-[.ZIP形式のライブラリをインストール...]から"DeviceControl.zip"を選択。
2. [スケッチ]-[ライブラリをインクルード]の中にDeviceControlが追加されるので選択すると、includeされる。

# DeviceControlライブラリの使用方法
例) 13番PINをHIGHにする。
```cpp
#include <DeviceControl.h>

void setup() {
  // put your setup code here, to run once:
  Digital::SetMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Digital::Write(13, HIGH);
}
```
