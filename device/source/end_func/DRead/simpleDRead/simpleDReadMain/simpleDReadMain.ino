// simpleDRead(テスト用)
// Created 2017/10/20
// By Hirotaka Nagaoka

// include
#include "EndFunc.h"

CONTEXT_DATA context;
RESULT_DATA  result;
SSHT simpleDRead( CONTEXT_DATA*, RESULT_DATA*, SINT );

// 定数定義(テスト用)
#define INPUT_PIN   ( 5      )
#define PIN_MODE    ( OUTPUT )
#define SERIAL_TIME ( 115200 )
#define MS_TIME     ( 5000   )

// setup
void setup( ){
  Serial.begin( SERIAL_TIME );
}

// loop
void loop( ){
// 必要情報(ポート番号等を構造体に格納)
context.port.mode = PIN_MODE;
context.port.pin1 = INPUT_PIN;
simpleDRead( &context, &result, MS_TIME );

// 確認用
Serial.println( "_____" );
Serial.print( result.value );
if( result.result == 0 ){
  Serial.println( " OK" );
  Serial.println( "-----" );
  }
}
