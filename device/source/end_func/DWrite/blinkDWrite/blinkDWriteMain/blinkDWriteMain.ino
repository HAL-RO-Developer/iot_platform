// blinkDWrite(テスト用)
// Created 2017/09/20
// By Hirotaka Nagaoka

// include
#include "EndFunc.h"

CONTEXT_DATA context;
RESULT_DATA  result;
SSHT blinkDWrite( CONTEXT_DATA*, RESULT_DATA*, SINT );

// 定数定義(テスト用)
#define LED_PIN   ( 13 )
#define PIN_MODE  ( INPUT )
#define VALUE     ( HIGH )
#define MS_TIME   ( 1000 )

// setup
void setup( ){
  Serial.begin( 115200 );
}

// loop
void loop( ){
SSHT Value = VALUE;

// 必要情報(ポート番号等を構造体に格納)
context.port.mode = PIN_MODE;
context.port.pin1 = LED_PIN;
context.value = &Value;
blinkDWrite( &context, &result, MS_TIME );

// 確認用
Serial.println( "_____" );
Serial.print( result.value );
if(result.result == 0){
  Serial.println( " OK" );
  Serial.println( "-----" );
  }
}
