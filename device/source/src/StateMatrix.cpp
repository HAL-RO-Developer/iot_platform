/*
    StateMatrix.cpp

    状態遷移マトリクス実体ＲＯＭテーブル

    Created 2017/09/11
    By Shogo Tanaka
*/

/* --- includeファイル --- */
#include "System.h"     /* システム共通データ定義ヘッダ */
#include "State.h"      /* 状態に関する定義ヘッダ       */

/* --- 副状態テーブル --- */
/* 副状態テーブル [主：セットアップ状態] */
const SUB_STATE_TABLE gSetupStateTable[] = {
	{ STATE_SETUP_AP, setupStateAp },		                /* ＡＰモード */
	{ STATE_SETUP_ACTION, setupStateAction },	            /* 動作モード */
    { null, null }                  			            /* ストッパ   */
};

/* 副状態テーブル [主：動作状態] */
const SUB_STATE_TABLE gActionStateTable[] = {
	{ STATE_ACTION_REGIST, actionStateRegist },	            /* 関数登録状態 */
    { STATE_ACTION_EXECUTE, actionStateExecute },           /* 関数実行状態 */
    { STATE_ACTION_SEND, actionStateSend },                 /* 結果送信状態 */
    { null , null }                 			            /* ストッパ     */
};

/* 副状態テーブル [主：エラー状態] */
const SUB_STATE_TABLE gErrorStateTable[] = {
	{ STATE_ERROR_CONNECT, errorStateConnect },	            /* WiFi接続エラー状態     */
    { STATE_ERROR_COMMUNICATE, errorStateCommunicate },     /* サーバー通信エラー状態 */
    { STATE_ERROR_OTHER, errorStateOther },                 /* その他各種エラー状態   */
    { null, null }                  			            /* ストッパ               */
};

/* --- 主状態テーブル --- */
const MAIN_STATE_TABLE gMainStateTable[] = {          
    { STATE_SETUP, gSetupStateTable },                      /* セットアップ状態 */
    { STATE_ACTION, gActionStateTable },                    /* 動作状態         */
    { STATE_ERROR, gErrorStateTable },                      /* エラー状態       */
    { null , null }			                                /* ストッパ         */
};

/* Copyright HAL College of Technology & Design */