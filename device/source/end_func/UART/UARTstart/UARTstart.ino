/*
    UARTstart.ino
    Created 2017/09/25
    By Hirotaka Nagaoka
*/
#include <DeviceControl.h>
#include "Endfunc.h"

/* 定数定義 */
#define BAUDRATE ( 115200 )   // 　ボーレート

RESULT_DATA result;

SCHR input[256];  // 文字列格納用
SINT cnt = 0;     // 文字数のカウンタ

void setup() {
  UART::begin( BAUDRATE );     // ボーレート
  UART::println( "SETUP OK." );
}

void loop() {
  UARTstart( &result );
  // 確認用
  UART::println( "DATA:" );
  UART::println( result.value );
  UART::println( "RESULT:" );
  UART::println( result.result );
  delay( 1000 );
}

SSHT UARTstart( RESULT_DATA* rdata ){
  SSHT rtn = RESULT_NG;
  SINT data = 0;
  // データ受信確認
  if( UART::available() > 0 ){
    data = UART::Read( );
    // UART::Write( data );
    rtn = RESULT_OK;
  }
  rdata->value = data;
  rdata->result = rtn;
  return rtn;
}

