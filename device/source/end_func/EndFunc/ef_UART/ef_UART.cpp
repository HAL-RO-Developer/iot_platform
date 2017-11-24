/* 
   ef_UART.cpp
   
   末端関数 UART
   
   Created 2017/11/22
   By Riku Hashimoto
*/
#include <DeviceControl.h>
#include "EndFunc.h"



/* UARTSetup */
SSHT UARTSetup( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
const SINT BAUDRATE = 	1;/* ボーレート */
	 SSHT rtn = RESULT_OK;
	 UART::begin( cdata->value[BAUDRATE] );
	 rdata->result = rtn;
	 return rtn;
}

/* UARTRead */
SSHT UARTRead( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	const SINT VALUE		= 0; 
	SSHT rtn = RESULT_OK;
	rdata->value = UART::Read();
	rdata->result = rtn;
	return rtn;
}

/* UARTWrite */
SSHT UARTWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	const SINT VALUE		= 0; 
	SSHT rtn = RESULT_OK;
	rdata->value = UART::Write( cdata->value[VALUE] );
	rdata->result =rtn;
	return rtn;
}

/* SoftwareSerialSetup */
SSHT SoftwareSerialSetup( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	const SINT BAUDRATE = 	1;/* ボーレート */
	SoftwareSerial mySerial( cdata->port.pin1, cdata->port.pin2 );
	SSHT rtn = RESULT_OK;
	mySerial.begin( cdata->value[BAUDRATE] );
	rdata->result = rtn;
	return rtn;
}

/* Copyright HAL College of Technology & Design */

