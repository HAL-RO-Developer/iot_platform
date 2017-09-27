/*
    UARTsetup.ino
    Created 2017/09/25
    By Hirotaka Nagaoka
*/
#include <DeviceControl.h>
#include "Endfunc.h"

/* 定数定義 */
#define BAUDRATE   ( 115200 )   // ボーレート
#define SEND_RX    (      4 )   // 受信側RX
#define SEND_TX    (      5 )   // 受信側TX

CONTEXT_DATA context;
RESULT_DATA result;

void setup( ) {
  UARTsetup( );
}

void loop( ) {
  SSHT rtn = 0;
  context.port[0] = SEND_RX;  // RX
  context.port[1] = SEND_TX;  // TX
  rtn = UARTstart( &context, &result );
  if( rtn == RESULT_OK ){
    UART::println( "UART setup OK" );
  }
  
}

void UARTsetup( ){
  UART::begin( BAUDRATE );      // HardwareSerialSetup
  UART::println( "SETUP OK." );
}

SSHT UARTstart( CONTEXT_DATA* cdata, RESULT_DATA* rdata ){
  SoftwareSerial mySerial( cdata->port[0], cdata->port[1] );
  SSHT rtn = RESULT_OK;
  mySerial.begin( BAUDRATE );   // SoftwareSerialSetup
  rdata->result = rtn;
  return rtn;
}
