// onceDWrite(テスト用)
// Created 2017/09/20
// By Hirotaka Nagaoka

// include
#include "EndFunc.h"

CONTEXT_DATA context;
RESULT_DATA  result;

// 定数定義(テスト用)
#define OUTPUT_PIN   ( 13     )
#define PIN_MODE     ( INPUT  )
#define T_VALUE      ( HIGH   )
#define SERIAL_TIME  ( 115200 )

// setup
void setup( ){
  Serial.begin( SERIAL_TIME );
}

// loop
void loop( ){
SSHT Value[2] = { T_VALUE } ;

// 必要情報(ポート番号等を構造体に格納)
context.port.mode = PIN_MODE;
context.port.pin1 = OUTPUT_PIN;
context.value = Value;

onceDWrite( &context, &result );

// 確認用
Serial.println( "_____" );
Serial.print( result.value );
if( result.result == 0 ){
  Serial.println( " OK" );
  Serial.println( "-----" );
  }
}
