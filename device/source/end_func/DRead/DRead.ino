/*
 Created 2017/09/29
 By Riku Hashimoto
 */
// include
#include "EndFunc.h"

//定数定義
#define BTN_Pin 5
#define PIN_Mode OUTPUT

CONTEXT_DATA context;
RESULT_DATA result;
//setup
void setup() {

  Serial.begin(115200);
}

//loop
void loop() {
 //必要情報(ポート番号等を構造体に格納)
context.port[0] = PIN_Mode;
context.port[1] = BTN_Pin;
onceDRead( &context,&result );
Serial.println(result.value );
}

