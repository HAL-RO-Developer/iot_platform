/* 
	ef_I2C.ino
	
	末端関数 I2C
	
	Created 2017/10/27
	By Riku Hashimoto
	Refactored 2017/12/01
    By Hirotaka Nagaoka
*/

#include <DeviceControl.h>	/* DeviceControl.h */
#include "System.h"   		/* システム共通データ定義ヘッダ */
#include "Function.h" 		/* 末端関数共通ヘッダ		  */

/* I2CSetup */
SSHT I2CSetup( CONTEXT_DATA *cdata,RESULT_DATA *rdata )
{
	SSHT rtn = RESULT_OK;	/* 返却値 */

	/* 結果を返却 */
	rdata->Result = rtn;
	I2C::begin( cdata->Port.Pin1, cdata->Port.Pin2 );	/* マスターとして設定 */

	return rtn;
}

/* I2CWrite */
SSHT I2CWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata )
{
	const SINT pt_data = 0;	/* データのポート情報 */
	const SINT pt_id   = 1;	/* IDのポート情報 */

	SSHT rtn = RESULT_OK;	/* 結果 */

	/* 結果を返却 */
	rdata->Result = rtn;
	/*  */
	I2C::beginTransmission( cdata->Value[pt_id] );
	I2C::Write( cdata->Value[pt_data] );
	I2C::endTransmission( );

	return rtn;
}

/* I2CRead */
SSHT I2CRead( CONTEXT_DATA *cdata, RESULT_DATA *rdata )
{
	SSHT rtn = RESULT_OK;		  /* 結果 */

	/* 結果を返却 */
	rdata->Value = I2C::Read( );  /* データを受け取る */
	rdata->Result = rtn;

	return rtn;
}

/* I2CRequestonebyte */
SSHT I2CRequestonebyte( CONTEXT_DATA *cdata, RESULT_DATA *rdata )
{
	const SINT pt_id = 1;	/* IDのポート情報 */
	SSHT rtn = RESULT_OK;	/* 返却値 */

	I2C::reqFrom( cdata->Value[pt_id], 1 );	/* Slaveに1バイトの送信をリクエスト */

	/* 結果を返却 */
	rdata->Result = rtn;

	return rtn;
}

/* Copyright HAL College of Technology & Design */
