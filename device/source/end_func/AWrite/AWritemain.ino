// Created 2017/09/20
// By Riku Hashimoto

// include
#include "endfunc.h"

/* 定数定義 */
 #define BAUDRATE ( 115200 )   // ボーレート
 #define LED_PIN ( 5 )        // ポート指定
 #define PIN_MODE ( INPUT )    // モード

CONTEXT_DATA context;
RESULT_DATA  result;

SSHT onceAWrite( CONTEXT_DATA *cdata,RESULT_DATA *rdata);//プロトタイプ宣言しないとエラーを起こす

//setup
void setup() {
  Serial.begin(BAUDRATE); 
}

//loop
void loop() {
//必要情報(ポート番号等を構造体に格納)
context.port[0] = PIN_MODE;
context.port[1] = LED_PIN;
context.value = 50;
onceAWrite( &context,&result );
//結果を表示
Serial.println("Result");
Serial.println(context.port[1] );
Serial.println(result.value );
Serial.println(result.result );
delay(1000); //シリアルを見やすくする
}


