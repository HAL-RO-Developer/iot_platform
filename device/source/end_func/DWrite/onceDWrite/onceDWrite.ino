/*
    onceDWrite.ino
    Created 2017/09/20
    By Hirotaka Nagaoka
*/

#include <DeviceControl.h>
#include "endfunc.h"

/* 定数定義 */
#define BAUDRATE ( 115200 )   // ボーレート
#define LED_PIN ( 10 )        // ポート指定
#define PIN_MODE ( INPUT )    // モード

CONTEXT_DATA context;
RESULT_DATA result;

// setup
void setup( ) {
  Serial.begin( BAUDRATE );   // ボーレート
}

// loop
void loop( ) {
  context.port[0] = PIN_MODE;
  context.port[1] = LED_PIN;
  context.value = HIGH;
  onceDWrite( &context, &result );
  // 確認用
  Serial.println( "Result" );
  Serial.println( context.port[1] );
  Serial.println( result.value );
  Serial.println( result.result );
  delay( 1000 );
}

short onceDWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
  short rtn = RESULT_OK;
  // モードチェック
  if( cdata->port[0] != OUTPUT ){
    Digital::SetMode( cdata->port[1], OUTPUT );
  }
  // 出力
  Digital::Write( cdata->port[1], cdata->value );
  rdata->value = cdata->value;
  rdata->result = rtn;
  return rtn;
}

