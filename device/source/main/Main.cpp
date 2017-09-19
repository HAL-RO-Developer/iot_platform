/*
    Main.cpp

    システムメイン

    Created 2017/09/14
    By Shogo Tanaka
*/

/* --- includeファイル --- */
#include "System.h"     /* システム共通データ定義ヘッダ */
#include "State.h"      /* 状態に関する定義ヘッダ       */

setup(){
    STATE_TABLE stateTable;
    SSHT ret = SYSTEM_NG;
    SSHT data = 0;      /* T.B.D. */

    // init

    stateTable.MainState = STATE_SETUP;         /* 主状態 */
    stateTable.SubState = STATE_SETUP_ACTION;   /* 副状態 */
    stateTable.PieceState = NULL;   // T.B.D.

}

loop(){
    ret = callFunction( &stateTable, data );
    if( ret == SYSTEM_NG ){
        break;
    }
}


/* Copyright HAL College of Technology & Design */

