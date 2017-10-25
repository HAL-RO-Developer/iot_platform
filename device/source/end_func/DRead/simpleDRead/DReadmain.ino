/*
 Created 2017/09/29
 By Riku Hashimoto
 */
// include
#include "EndFunc.h"

//定数定義
#define BTN_Pin 4
#define PIN_Mode OUTPUT

CONTEXT_DATA context;
RESULT_DATA result;
//setup
void setup() {

  Serial.begin(115200);
}

//loop
void loop() {
 SSHT Value = 200;
//必要情報(ポート番号等を構造体に格納)
context.port.mode = PIN_Mode;
context.port.pin1 = BTN_Pin;
simpleDRead( &context,&result,1000 );
//結果を表示

Serial.println("_____");
Serial.print(result.value );
if(result.result == 0)Serial.println(" OK");
Serial.println("-----");
delay(500); //シリアルを見やすくする
}

