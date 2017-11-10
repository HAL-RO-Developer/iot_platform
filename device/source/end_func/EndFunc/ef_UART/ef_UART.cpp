/* 
   ef_UART.cpp
   
   末端関数 UART
   
   Created 2017/09/27
   By Hirotaka Nagaoka
*/

#include <DeviceControl.h>
#include "EndFunc.h"

#define VALUE		( 0 )
#define BAUDRATE  	( 1 )     /* ボーレート */

/* UARTSetup */
SSHT UARTSetup( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	 SSHT rtn = RESULT_OK;
	 UART::begin( cdata->value[BAUDRATE] );
	 rdata->result = rtn;
	 return rtn;
}

/* UARTRead */
SSHT UARTRead( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	SSHT rtn = RESULT_OK;
	rdata->value = UART::Read();
	rdata->result = rtn;
	return rtn;
}

/* UARTWrite */
SSHT UARTWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	SSHT rtn = RESULT_OK;
	rdata->value = UART::Write( cdata->value[VALUE] );
	rdata->result =rtn;
	return rtn;
}

/* SoftwareSerialSetup */
SSHT SoftwareSerialSetup( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	SoftwareSerial mySerial( cdata->port.pin1, cdata->port.pin2 );
	SSHT rtn = RESULT_OK;
	mySerial.begin( cdata->value[BAUDRATE] );
	rdata->result = rtn;
	return rtn;
}

/* Copyright HAL College of Technology & Design */

