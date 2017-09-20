/*
    Main.cpp

    システムメイン

    Created 2017/09/14
    By Shogo Tanaka
*/

/* --- includeファイル --- */
#include <string.h>   /* 初期化関連 */
#include "System.h"     /* システム共通データ定義ヘッダ */
#include "State.h"      /* 状態に関する定義ヘッダ       */

setup(){
    STATE_TABLE stateTable;
    SSHT ret = SYSTEM_NG;
    SSHT data = 0;      /* T.B.D. */
    STATE_INFO_COMMON common;
    // init

    memset( &stateTable, 0, sizeof( STATE_TABLE ) );
    memset( &common, 0, sizeof( STATE_INFO_COMMON ) );

    stateTable.MainState = STATE_SETUP;         /* 主状態 */
    stateTable.SubState = STATE_SETUP_ACTION;   /* 副状態 */
    stateTable.PieceState = INIT;               /* 個別状態 */

    // 入力系割り込み設定
    // WDT処理
    // HWリセット関連処理

}

loop(){
    ret = callFunction( &stateTable, data );
    if( ret == SYSTEM_NG ){
        stateTable.MainState = STATE_ERROR;     /* 主状態を【エラー】にする */
        stateTable.SubState = StATE_OTHER;
    }
}

// 入力系タイマー割り込み

/* Copyright HAL College of Technology & Design */
