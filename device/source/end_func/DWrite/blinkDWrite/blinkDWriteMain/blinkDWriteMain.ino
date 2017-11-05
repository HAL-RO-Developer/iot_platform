// blinkDWrite(テスト用)
// Created 2017/09/20
// By Hirotaka Nagaoka

// include
#include "EndFunc.h"

CONTEXT_DATA context;
RESULT_DATA  result;
SSHT blinkDWrite( CONTEXT_DATA*, RESULT_DATA*, SINT );

// 定数定義(テスト用)
#define OUTPUT_PIN   ( 13     )
#define PIN_MODE     ( INPUT  )
#define VALUE        ( HIGH   )
#define SERIAL_TIME  ( 115200 )
#define MS_TIME      ( 1000   )

// setup
void setup( ){
  Serial.begin( SERIAL_TIME );
}

// loop
void loop( ){
SSHT Value = VALUE;

// 必要情報(ポート番号等を構造体に格納)
context.port.mode = PIN_MODE;
context.port.pin1 = OUTPUT_PIN;
context.value = &Value;
blinkDWrite( &context, &result, MS_TIME );

// 確認用
Serial.println( "_____" );
Serial.print( result.value );
if( result.result == 0 ){
  Serial.println( " OK" );
  Serial.println( "-----" );
  }
}
