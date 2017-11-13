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
SSHT value[2] = {0,5000};

//setup
void setup() {

  Serial.begin(9600);
}

//loop
void loop() {
//必要情報(ポート番号等を構造体に格納)
context.port.mode = PIN_Mode;
context.port.pin1 = Sensor_Pin;
 context.value = value;
simpleARead( &context,&result);
//結果を表示

Serial.println("_____");
Serial.print(result.value );
if(result.result == 0)Serial.println(" OK");
Serial.println("-----");
delay(1000);
}

