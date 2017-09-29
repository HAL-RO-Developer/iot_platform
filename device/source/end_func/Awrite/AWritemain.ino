// Created 2017/09/20
// By Riku Hashimoto

// include
#include "EndFunc.h"

CONTEXT_DATA context;
RESULT_DATA  result;

short onceAWrite( CONTEXT_DATA *cdata,RESULT_DATA *rdata);//プロトタイプ宣言しないとエラーを起こす

//定数定義
#define LED_Pin 5
#define PIN_Mode INPUT


//setup
void setup() {
  Serial.begin(115200); 
}

//loop
void loop() {
//必要情報(ポート番号等を構造体に格納)
context.port[0] = PIN_Mode;
context.port[1] = LED_Pin;
context.value = 120;
onceAWrite( &context,&result );
//結果を表示
Serial.println("Result");
Serial.println(context.port[1] );
Serial.println(result.value );
Serial.println(result.result );
delay(1000); //シリアルを見やすくする
}


