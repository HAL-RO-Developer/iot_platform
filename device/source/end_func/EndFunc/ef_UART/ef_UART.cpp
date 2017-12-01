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
	 UART::begin( cdata->Value[BAUDRATE] );
	 rdata->Result = rtn;
	 return rtn;
}

/* UARTRead */
SSHT UARTRead( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	const SINT VALUE		= 0; 
	SSHT rtn = RESULT_OK;
	rdata->Value = UART::Read();
	rdata->Result = rtn;
	return rtn;
}

/* UARTWrite */
SSHT UARTWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	const SINT VALUE		= 0; 
	SSHT rtn = RESULT_OK;
	rdata->Value = UART::Write( cdata->Value[VALUE] );
	rdata->Result =rtn;
	return rtn;
}

/* SoftwareSerialSetup */
SSHT SoftwareSerialSetup( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	const SINT BAUDRATE = 	1;/* ボーレート */
	SoftwareSerial mySerial( cdata->Port.Pin1, cdata->Port.Pin2 );
	SSHT rtn = RESULT_OK;
	mySerial.begin( cdata->Value[BAUDRATE] );
	rdata->Result = rtn;
	return rtn;
}

/* Copyright HAL College of Technology & Design */

