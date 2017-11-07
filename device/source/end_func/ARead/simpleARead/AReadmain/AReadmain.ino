/*
 Created 2017/09/29
 By Riku Hashimoto
 */
// include
#include "EndFunc.h"
//定数定義
#define Sensor_Pin A0
#define PIN_Mode OUTPUT
CONTEXT_DATA context;
RESULT_DATA result;
SSHT simpleARead( CONTEXT_DATA *,RESULT_DATA *,SINT);
//setup
void setup() {

  Serial.begin(115200);
}

//loop
void loop() {
//必要情報(ポート番号等を構造体に格納)
context.port.mode = PIN_Mode;
context.port.pin1 = Sensor_Pin;
simpleARead( &context,&result,5000);
//結果を表示

Serial.println("_____");
Serial.print(result.value );
if(result.result == 0)Serial.println(" OK");
Serial.println("-----");
}

