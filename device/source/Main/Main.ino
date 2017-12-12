/*
    Main.ino

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
#include "StatusLED.h"
#include "constants.h"

const   SCHR*   settings    = "/settings.json";
const   SCHR*   ap_ssid     = "ESP8266";
const   SCHR*   ap_pass     = "password";

STATE_TABLE stateTable;
SSHT ret = STATE_NG;
INFO_COMMON common;

StatusLED led_r( SLPR );
StatusLED led_g( SLPG );

/* --- プロトタイプ宣言 --- */
void deviceInit();

void setup()
{
  
    memset( &stateTable, 0, sizeof( STATE_TABLE ) );
    memset( &common, 0, sizeof( INFO_COMMON ) );

    deviceInit();

    /* --- 初期状態設定 --- */

    /* 主状態 */
    stateTable.MainState = STATE_SETUP;         
    
    /* 副状態 */
    if( digitalRead( APSWT ) == HIGH ){
        stateTable.SubState = STATE_SETUP_ACTION;
    }else{
        stateTable.SubState = STATE_SETUP_AP;
    }
    
    /* 個別状態 */
    stateTable.PieceState = INIT;

    //demo
    //stateTable.SubState = STATE_ACTION_SERIAL;
    //stateTable.SubState = STATE_SETUP_AP;

    Serial.println();
}

void loop()
{
    ret = callFunction( &stateTable, &common );
    if( ret == STATE_NG ){
        stateTable.MainState = STATE_ERROR;     /* 主状態を【エラー】にする */
        stateTable.PieceState = INIT;
    }
}

/* --- 各種初期設定 --- */
void deviceInit()
{
    /* APスイッチ */
    pinMode( APSWT, INPUT );
    
    /* ステータスLED */
    led_r.write(LOW);
    led_g.write(LOW);
    common.led_r = &led_r;
    common.led_g = &led_g;

    /* MACアドレス取得 */
    byte mac_byte[6];
    WiFi.macAddress( mac_byte );
    for( int i = 0; i < 6; i++ ){
        common.mac += String( mac_byte[i], HEX );
    }

    /* シリアル通信 */
    Serial.begin( 115200 );
    /* I2C通信 */
    Wire.begin();
    /* ファイルシステム */
    SPIFFS.begin();
    
}

/* Copyright HAL College of Technology & Design */

