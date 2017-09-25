/*
    Main.cpp

    システムメイン

    Created 2017/09/14
    By Shogo Tanaka
*/

/* --- includeファイル --- */
#include <string.h>             /* 初期化関連 */
#include "ArduinoLibrary.h"
#include "System.h"             /* システム共通データ定義ヘッダ */
#include "State.h"              /* 状態に関する定義ヘッダ       */
#include "InfoStruct.h"         /* 情報管理構造体定義ヘッダ     */
#include "constants.h"

STATE_TABLE stateTable;
SSHT ret = STATE_NG;
INFO_COMMON common;

/* --- プロトタイプ宣言 --- */
void a_init();

void setup(){
    //WIFICONFIG config;

    // init

    memset( &stateTable, 0, sizeof( STATE_TABLE ) );
    memset( &common, 0, sizeof( INFO_COMMON ) );

    a_init();

    /* --- 初期状態設定 --- */

    /* 主状態 */
    stateTable.MainState = STATE_SETUP;         
    
    /* 副状態 */
    if( digitalRead( APSWT ) ){
        stateTable.SubState = STATE_SETUP_ACTION;
    }else{
        stateTable.SubState = STATE_SETUP_AP;
    }

    /* 個別状態 */
    stateTable.PieceState = INIT;               

    // 入力系割り込み設定
    // WDT処理
    // HWリセット関連処理  

}

void loop(){
    ret = callFunction( &stateTable, &common );
    if( ret == SYSTEM_NG ){
        stateTable.MainState = STATE_ERROR;     /* 主状態を【エラー】にする */
        stateTable.SubState = STATE_ERROR_OTHER;
    }
}

// 入力系タイマー割り込み

// 各種初期設定
void a_init(){
    pinMode( APSWT, INPUT );
    pinMode( SLPR, OUTPUT );
    pinMode( SLPG, OUTPUT );
    SPIFFS.begin();
    Serial.begin( 115200 );

    Wire.begin();
}

/* Copyright HAL College of Technology & Design */
