/* 
   UARTTestMain.ino
   
   UARTTest用メイン関数
   
   Created 2017/09/27
   By Hirotaka Nagaoka
*/
#include <DeviceControl.h>
#include "EndFunc.h"

/* 定数定義 */
#define BAUDRATE  ( 115200 )     // ボーレート
#define SEND_RX   (      4 )     // 受信側RX
#define SEND_TX   (      5 )     // 受信側TX
#define T_VALUE     (     40 )

CONTEXT_DATA context;
RESULT_DATA result;

void setup( ){
  SSHT SetupRtn = 0;
  SetupRtn = UARTSetup( &context, &result );
  if( SetupRtn == RESULT_OK ){
    UART::println( "UART SETUP OK." );
  }
}

void loop( ){
  SSHT SSSetupRtn = 0;
  SSHT ReadRtn = 0;
  SSHT WriteRtn = 0;
  SSHT Value[2] = { T_VALUE, BAUDRATE };
  
  context.port.pin1 = SEND_RX;  // RX
  context.port.pin2 = SEND_TX;  // TX
  context.value = Value;
  
  SSSetupRtn = SoftwareSerialSetup( &context, &result );
  ReadRtn = UARTRead( &context, &result );
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

