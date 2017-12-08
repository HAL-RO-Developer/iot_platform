/* 
	ef_DigitalWrite.cpp

	末端関数 DigitalWrite

	Created 2017/09/27
	By Hirotaka Nagaoka
	Refactored 2017/12/01
    By Hirotaka Nagaoka
*/

#include <DeviceControl.h>	/* DeviceControl.h */
#include "System.h"   		/* システム共通データ定義ヘッダ */
#include "Function.h" 		/* 末端関数共通ヘッダ		  */

/* onceDWrite */
SSHT onceDWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata )
{
	const SINT pt_value = 0;	/* 値のポート情報 */
	SSHT rtn = RESULT_OK;		/* 戻り値		  */

	/* --- モードチェック --- */
	if( cdata->Port.Mode != OUTPUT )
	{
		Digital::SetMode( cdata->Port.Pin1, OUTPUT );	/* OUTPUT */
	}
	
	/* --- 出力 --- */
	Digital::Write( cdata->Port.Pin1, cdata->Value[pt_value] );
	/* 出力結果を返却 */
	rdata->Value = cdata->Value[pt_value];
	rdata->Result = rtn;

	return rtn;
}

/* simpleDWrite */
SSHT simpleDWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	const SINT pt_value = 0;	/* 値のポート情報 */
	const SINT pt_time  = 1;	/* 時間のポート情報 */
	SSHT rtn = RESULT_OK;		/* 返却値 */

	/* --- モードチェック --- */
	if( cdata->Port.Mode != OUTPUT )
	{
		Digital::SetMode( cdata->Port.Pin1, OUTPUT );	/* OUTPUT */
	}
	
  static SINT Time = millis( );	/* 時間取得 */
  static SINT Flag = 0;			/* フラグ 	 */

  if( Flag == 0 )
  {
	Time = millis( );	/* 時間取得 */
	Flag = 1;			/* フラグを立てる */
  }

  /* --- 指定時間出力 --- */
  if( millis( ) - Time <= cdata->Value[pt_time] )
  {
	/* 指定値を出力 */
	Digital::Write( cdata->Port.Pin1, cdata->Value[pt_value] );
	/* 出力結果を返却 */
	rdata->Value = cdata->Value[pt_value];
	rdata->Result = rtn;
  }
  else
  {
	/* 反転出力 */
	Digital::Write( cdata->Port.Pin1, !( cdata->Value[pt_value] ) );
	Flag = 0;	/* フラグリセット */
	delay( 1000 );
	/* 出力結果を返却 */
	rdata->Value = !( cdata->Value[pt_value] );
	rdata->Result = rtn;
	}

	return rtn;
}

/* blinkDWrite */
SSHT blinkDWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata )
{
	const SINT pt_time = 0;	/* 時間のポート情報 */
	SSHT rtn = RESULT_OK;	/* 戻り値 */

	/* --- モードチェック --- */
	if( cdata->Port.Mode != OUTPUT )
	{
		Digital::SetMode( cdata->Port.Pin1, OUTPUT );	/* OUTPUT */
	}
	
	static SINT Time = millis( );	/* 時間取得 */

	/* --- 指定時間出力 --- */
	if( millis( ) - Time >= cdata->Value[pt_time] )
	{
		/* HIGHを出力 */
		Digital::Write( cdata->Port.Pin1, HIGH );
		/* 出力結果を返却 */
		rdata->Value = HIGH;
		rdata->Result = rtn;
	}
	
	if( millis( )-Time >= cdata->Value[pt_time] * 2 )
	{	
		/* LOWを出力 */
		Digital::Write( cdata->Port.Pin1, LOW );
		/* 出力結果を返却 */
		rdata->Value = LOW;
		rdata->Result = rtn;
		/* 時間取得 */
		Time = millis( );
	}
	return rtn;
}

/* Copyright HAL College of Technology & Design */
