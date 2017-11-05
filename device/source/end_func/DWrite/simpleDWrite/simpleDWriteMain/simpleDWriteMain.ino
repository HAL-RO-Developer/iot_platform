// simpleDWrite(テスト用)
// Created 2017/09/20
// By Hirotaka Nagaoka

// include
#include "EndFunc.h"

CONTEXT_DATA context;
RESULT_DATA  result;
SSHT simpleDWrite( CONTEXT_DATA*, RESULT_DATA*, SINT );

// 定数定義(テスト用)
#define LED_Pin   ( 13 )
#define PIN_Mode  ( INPUT )

#define MS_TIME   ( 5000 )  // 設定時間

// setup
void setup( ){
  Serial.begin( 115200 );
}

// loop
void loop( ){
SSHT Value = 1;

// 必要情報(ポート番号等を構造体に格納)
context.port.mode = PIN_Mode;
context.port.pin1 = LED_Pin;
context.value = &Value;
simpleDWrite( &context, &result, MS_TIME );

// 確認用
Serial.println( "_____" );
Serial.print( result.value );
if(result.result == 0){
  Serial.println( " OK" );
  Serial.println( "-----" );
  }
}
