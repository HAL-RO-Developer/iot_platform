/* 
   UARTTestMain.ino
   
   UARTTest用メイン関数
   
   Created 2017/09/27
   By Hirotaka Nagaoka
*/
#include <DeviceControl.h>
#include "Endfunc.h"

/* 定数定義 */
#define BAUDRATE  ( 115200 )    // ボーレート
#define SEND_RX   (      4 )   // 受信側RX
#define SEND_TX   (      5 )   // 受信側TX

CONTEXT_DATA context;
RESULT_DATA result;

SSHT UARTSetup( RESULT_DATA* );
SSHT SoftwareSerialSetup( CONTEXT_DATA*, RESULT_DATA* );
SSHT UARTRead( RESULT_DATA* );
SSHT UARTWrite( CONTEXT_DATA*, RESULT_DATA* );

void setup( ){
  SSHT SetupRtn = 0;
  SetupRtn = UARTSetup( &result );
  if( SetupRtn == RESULT_OK ){
    UART::println( "UART SETUP OK." );
  }
}

void loop( ){
  SSHT SSSetupRtn = 0;
  SSHT ReadRtn = 0;
  SSHT WriteRtn = 0;
  context.port[0] = SEND_RX;  // RX
  context.port[1] = SEND_TX;  // TX
  context.value = 45;         // 45byte
  SSSetupRtn = SoftwareSerialSetup( &context, &result );
  ReadRtn = UARTRead( &result );
  WriteRtn = UARTWrite( &context, &result );
  if( SSSetupRtn == RESULT_OK ){
    UART::println( "SERIAL SETUP OK." );
  }
  if( ReadRtn == RESULT_OK ){
    UART::println( "READ OK." );
  }
  if( WriteRtn == RESULT_OK ){
    UART::println( "WRITE OK." );
  }
}

/* Copyright HAL College of Technology & Design */

