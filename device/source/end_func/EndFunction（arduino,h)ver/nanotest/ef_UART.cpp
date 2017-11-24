/* 
	ef_UART.cpp

	末端関数 UART

	Created 2017/11/24
	By Riku Hashimoto
*/

#include <arduino.h>
#include <SoftwareSerial.h>
#include "EndFunc.h"



/* UARTSetup */
SSHT UARTSetup( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
const SINT VALUE  = 0;
const SINT BAUDRATE = 1;     /* ボーレート */
	 SSHT rtn = RESULT_OK;
	 Serial.begin( cdata->Value[BAUDRATE] );
	 rdata->Result = rtn;
	 return rtn;
}

/* UARTRead */
SSHT UARTRead( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
const SINT VALUE  = 0;
const SINT BAUDRATE = 1;     /* ボーレート */
	SSHT rtn = RESULT_OK;
	rdata->Value = Serial.read();
	rdata->Result = rtn;
	return rtn;
}

/* UARTWrite */
SSHT UARTWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
  const SINT VALUE  = 0;
const SINT BAUDRATE = 1;     /* ボーレート */
	SSHT rtn = RESULT_OK;
	rdata->Value = Serial.write( cdata->Value[VALUE] );
	rdata->Result =rtn;
	return rtn;
}

/* SoftwareSerialSetup */
SSHT SoftwareSerialSetup( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
const SINT VALUE  = 0;
const SINT BAUDRATE = 1;     /* ボーレート */
	SoftwareSerial mySerial( cdata->Port.Pin1, cdata->Port.Pin2 );
	SSHT rtn = RESULT_OK;
	mySerial.begin( cdata->Value[BAUDRATE] );
	rdata->Result = rtn;
	return rtn;
}

/* Copyright HAL College of Technology & Design */

