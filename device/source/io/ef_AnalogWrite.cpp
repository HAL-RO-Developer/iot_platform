/*
	ef_AnalogWrite.cpp

	末端関数 AnalogWrite

	Created 2017/10/07
	By Riku Hashimoto
	Refactored 2017/12/01
    By Hirotaka Nagaoka
*/

#include <DeviceControl.h>	/* DeviceControl.h */
#include "System.h"   		/* システム共通データ定義ヘッダ */
#include "Function.h" 		/* 末端関数共通ヘッダ		  */

/* simpleAWrite */
SSHT simpleAWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata )
{
	const SINT pt_value = 0;	/* 値のポート情報 */
	const SINT pt_time  = 1;	/* 時間のポート情報 */
	SSHT rtn = RESULT_OK;		/* 返却値 */

	/* --- モードチェック --- */
	if ( cdata->Port.Mode != OUTPUT )
	{
		Digital::SetMode( cdata->Port.Pin1, OUTPUT );	/* OUTPUT */
	}

	static SINT Time = millis();	/* 時間取得 */

	/* --- 指定時間出力 --- */
	if ( millis( ) - Time <= cdata->Value[pt_value] )
	{
		/* 指定値を出力 */
		Analog::Write( cdata->Port.Pin1, cdata->Value[pt_value] );
		/* 出力結果を返却 */
		rdata->Value = cdata->Value[pt_value];
		rdata->Result = rtn;
	}
	else
	{	/*  */
		Analog::Write( cdata->Port.Pin1, LOW );
		/* 出力結果を返却 */
		rdata->Value = LOW;
		rdata->Result = rtn;
	}

	return rtn;
}

/* onceAWrite */
SSHT onceAWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata )
{
	const SINT pt_value = 0;
	SSHT rtn = RESULT_OK;

	/* --- モードチェック --- */
	if ( cdata->Port.Mode != OUTPUT ) {
		Digital::SetMode( cdata->Port.Pin1, OUTPUT );
	}

	Analog::Write( cdata->Port.Pin1, cdata->Value[pt_value] );
	/* 出力結果を返却 */
	rdata->Value = cdata->Value[pt_value];
	rdata->Result = rtn;

	return rtn;
}

/* blinkAWrite */
SSHT blinkAWrite( CONTEXT_DATA *cdata,RESULT_DATA *rdata )
{
	const SINT pt_value = 0;
	const SINT pt_time = 1;
	SSHT rtn = RESULT_OK;

	/* --- モードチェック --- */
	if( cdata->Port.Mode != OUTPUT )
	{
		Digital::SetMode( cdata->Port.Pin1, OUTPUT );
	}

	/* 時間取得 */
	static SINT Time = millis( );

	if( millis( )-Time >= cdata->Value[pt_time] )
	{
		Analog::Write( cdata->Port.Pin1, cdata->Value[pt_value] );
		/* 出力結果を返却 */
		rdata->Value = HIGH;
		rdata->Result = rtn;
	}
	if( millis( )-Time >= cdata->Value[pt_time] * 2 )
	{
		Analog::Write( cdata->Port.Pin1, 0 );
		/* 出力結果を返却 */
		rdata->Value = LOW;
		rdata->Result = rtn;
		Time = millis( );
	}

	return rtn;
}

/* Copyright HAL College of Technology & Design */
