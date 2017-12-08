/* 
	ef_DigitalRead.cpp

	末端関数 DigitalRead

	Created 2017/09/27
	By Hirotaka Nagaoka
	Refactored 2017/12/01
    By Hirotaka Nagaoka
*/

#include <DeviceControl.h>	/* DeviceControl.h */
#include "System.h"   		/* システム共通データ定義ヘッダ */
#include "Function.h" 		/* 末端関数共通ヘッダ		  */

/* onceDRead */
SSHT onceDRead( CONTEXT_DATA *cdata, RESULT_DATA *rdata )
{
	SSHT rtn = RESULT_OK;	/* 戻り値 */

	/* --- モードチェック --- */
	if( cdata->Port.Mode != INPUT )
	{
		Digital::SetMode( cdata->Port.Pin1, INPUT );	/* INPUT */
	}

	/* 結果を返却 */
	rdata->Value = Digital::Read( cdata->Port.Pin1 ); 	/* 値取得 */
	rdata->Result = rtn;

	return rtn;
}

/* simpleDRead */
SSHT simpleDRead( CONTEXT_DATA *cdata, RESULT_DATA *rdata )
{
	const SINT pt_time = 1;	/* 時間のポート情報 */
	SSHT rtn = RESULT_OK;	/* 返却値 */

	/* --- モードチェック --- */
	if( cdata->Port.Mode != INPUT )
	{
	Digital::SetMode( cdata->Port.Pin1, INPUT );	/* INPUT */
	}
	
	static SINT Time = millis( );	/* 時間取得 */
	
	if( millis( ) - Time >= cdata->Value[pt_time] )
	{
		/* 結果を返却 */
		rdata->Value = Digital::Read( cdata->Port.Pin1 ); /* 値取得 */
		rdata->Result = rtn;

		return rtn; 
	}
}

/* Copyright HAL College of Technology & Design */
