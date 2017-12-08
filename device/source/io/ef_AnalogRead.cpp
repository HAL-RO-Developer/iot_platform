/*
	ef_AnalogRead.cpp

	末端関数 AnalogRead

	Created 2017/10/07
	By Riku Hashimoto
	Refactored 2017/12/01
    By Hirotaka Nagaoka
*/

#include <DeviceControl.h>	/* DeviceControl.h */
#include "System.h"   		/* システム共通データ定義ヘッダ */
#include "Function.h" 		/* 末端関数共通ヘッダ		  */

/* onceARead */
SSHT onceARead( CONTEXT_DATA *cdata,RESULT_DATA *rdata )
{
	SSHT rtn = RESULT_OK;

	/* --- モードチェック --- */
	if( cdata->Port.Mode != INPUT )
	{
		Digital::SetMode( cdata->Port.Pin1, INPUT );	/* INPUT */
	}

	rdata->Value = Analog::Read( cdata->Port.Pin1 );	/* アナログ値取得 */
	rdata->Result = rtn;

	return rtn;
}

/* simpleARead */
SSHT simpleARead( CONTEXT_DATA *cdata, RESULT_DATA *rdata )
{
	const SINT pt_value = 0;	/* ポート情報:値 */
	const SINT pt_time 	= 1;	/* ポート情報:時間 */

	SSHT rtn = RESULT_OK;

	/* --- モードチェック --- */
	if ( cdata->Port.Mode != INPUT )
	{
		Digital::SetMode( cdata->Port.Pin1, INPUT );	/* INPUT */
	}

	static SINT Time = millis( );	/* 時間取得 */

	if ( millis( ) - Time >= cdata->Value[pt_time] )
	{
	rdata->Value = Analog::Read( cdata->Port.Pin1 );	/* アナログ値取得 */
		Time = millis( );
		rdata->Result = rtn;

		return rtn;
	}
}

/* Copyright HAL College of Technology & Design */
