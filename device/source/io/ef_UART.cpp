/* 
	ef_UART.cpp

	末端関数 UART

	Created 2017/09/27
	By Hirotaka Nagaoka
	Refactored 2017/12/01
    By Hirotaka Nagaoka
*/

#include <DeviceControl.h>	/* DeviceControl.h */
#include "System.h"   		/* システム共通データ定義ヘッダ */
#include "Function.h" 		/* 末端関数共通ヘッダ		  */

/* UARTSetup */
SSHT UARTSetup( CONTEXT_DATA *cdata, RESULT_DATA *rdata )
{
	const SINT pt_baudrate = 1;	/* ボーレートのポート情報 */
	SSHT rtn = RESULT_OK;		/* 返却値 */

	/* ボーレート設定 */
	UART::begin( cdata->Value[pt_baudrate] );
	/* 結果返却 */
	rdata->Result = rtn;

	return rtn;
}

/* UARTRead */
SSHT UARTRead( CONTEXT_DATA *cdata, RESULT_DATA *rdata )
{
	SSHT rtn = RESULT_OK;	/* 返却値 */

	/* 結果返却 */
	rdata->Value = UART::Read( );
	rdata->Result = rtn;

	return rtn;
}

/* UARTWrite */
SSHT UARTWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata )
{
	const SINT pt_value = 0;	/* 値のポート情報 */
	SSHT rtn = RESULT_OK;		/* 返却値 */

	/* 結果返却 */
	rdata->Value = UART::Write( cdata->Value[pt_value] );
	rdata->Result = rtn;

	return rtn;
}

/* SoftwareSerialSetup */
SSHT SoftwareSerialSetup( CONTEXT_DATA *cdata, RESULT_DATA *rdata )
{
	/* ポート指定 */
	SoftwareSerial mySerial( cdata->Port.Pin1, cdata->Port.Pin2 );
	
	const SINT pt_baudrate = 1;	/* ボーレートのポート情報 */
	SSHT rtn = RESULT_OK;		/* 返却値 */

	/* 指定ポートのボーレートを設定 */
	mySerial.begin( cdata->Value[pt_baudrate] );
	/* 結果返却 */
	rdata->Result = rtn;

	return rtn;
}

/* Copyright HAL College of Technology & Design */
