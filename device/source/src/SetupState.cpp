/*
    ArduinoLibrary.h

    Arduinoライブラリヘッダ

    Created 2017/09/21
    By Shogo Tanaka
*/

/* --- includeファイル --- */
#include "ArduinoLibrary.h"
#include "System.h"             /* システム共通データ定義ヘッダ */
#include "State.h"              /* 状態に関する定義ヘッダ       */
#include "InfoStruct.h"         /* 情報管理構造体定義ヘッダ     */

/* --- グローバル変数 --- */
ESP8266WebServer server( 80 );
const   SCHR*   settings    = "/settings.txt";
const   SCHR*   ap_ssid     = "ESP8266";
const   SCHR*   ap_pass     = "password";

/* --- プロトタイプ宣言 --- */
void getWiFiConfig( INFO_COMMON* common );
void connectRouter( WIFICONFIG config );
void handleRootGet();
void handleRootPost();

/* --- 関数メイン --- */

/*
    setupStateAp

    セットアップ状態APモード時

    (概要)

    引数:
    STATE_TABLE     state       状態管理テーブル
    INFO_COMMON*    common      データオブジェクト(仮データ)

    戻り値:
    SSHT        STATE_OK    正常終了
                STATE_NG    システムエラー
                STATE_PARAM 引数エラー

    Created 2017/09/22
    By Shogo Tanaka
*/
SSHT setupStateAp( STATE_TABLE* state, INFO_COMMON* common )
{
    /* --- 引数チェック --- */
    if(( state == NULL ) || ( common == NULL )) {
	    return STATE_PARAM;
    }

    switch( state->PieceState ){
        case INIT: 
            /* --- SSIDおよびパスワード等の表示 --- */
            Serial.println();
            Serial.print( "SSID: " );
            Serial.println( ap_ssid );
            Serial.print( "PASS: " );
            Serial.println( ap_pass );
            Serial.print("AP IP address: ");
            Serial.println( WiFi.softAPIP() );
            state->PieceState = EXECUTE;
            break;
        case EXECUTE:
            server.on( "/", HTTP_GET, handleRootGet );
            server.on( "/", HTTP_POST, handleRootPost );
            server.begin();
            state->PieceState = FIN;
            break;
        case FIN:
            server.handleClient();
            state->SubState = STATE_SETUP_ACTION;
            state->PieceState = INIT;
            break;
    }
    
    return STATE_OK;
}

/*
    setupStateAction

    セットアップ状態動作モード時

    (概要)

    引数:
    STATE_TABLE     state       状態管理テーブル
    INFO_COMMON*    common      データオブジェクト(仮データ)

    戻り値:
    SSHT        STATE_OK    正常終了
                STATE_NG    システムエラー
                STATE_PARAM 引数エラー

    Created 2017/09/22
    By Shogo Tanaka
*/

SSHT setupStateAction( STATE_TABLE* state, INFO_COMMON* common )
{

    /* --- 引数チェック --- */
    if(( state == NULL ) || ( common == NULL )) {
	    return STATE_PARAM;
    }

    switch( state->PieceState ){
        case INIT: 
            state->PieceState = EXECUTE;
            break;
        case EXECUTE:
            getWiFiConfig( common );            /* WiFi接続情報の取得 */
            connectRouter( common->config );    /* ルーター接続 */
            state->PieceState = FIN;
            break;
        case FIN:
            state->MainState = STATE_ACTION;
            state->SubState = STATE_ACTION_REGIST;
            state->PieceState = INIT;
            break;
    }

    return STATE_OK;
}

void handleRootGet()
{
    string html = "";
    html += "<h1>WiFi Settings</h1>";
    html += "<form method='post'>";
    html += "  <input type='text' name='ssid' placeholder='SSID'><br>";
    html += "  <input type='password' name='pass' placeholder='PASS'><br>";
    html += "  <input type='text' name='host' placeholder='HOST'><br>";
    html += "  <input type='text' name='port' placeholder='PORT'><br>";
    html += "  <input type='submit'><br>";
    html += "</form>";
    server.send( 200, "text/html", html );
}

void handleRootPost()
{
    string  ssid = server.arg("ssid");
    string  pass = server.arg("pass");
    string  host = server.arg("host");
    string  port = server.arg("port");
    
    File    file = SPIFFS.open( settings, "w" );
    file.println( ssid );
    file.println( pass );
    file.println( host );
    file.println( port );
    file.close();
    
    string html = "";
    html += "<h1>WiFi Settings</h1>";
	html += "<p>Settings changed</p>";
	server.send( 200, "text/html", html );
}


void getWiFiConfig( INFO_COMMON* common )
{
    File   file = SPIFFS.open( settings, "r" );
    (common->config).ssid = file.readStringUntil( '\n' );
    (common->config).pass = file.readStringUntil( '\n' );
    (common->config).host = file.readStringUntil( '\n' );
    (common->config).port = file.readStringUntil( '\n' );
    file.close();
    
    (common->config).ssid.trim();
    (common->config).pass.trim();
    (common->config).host.trim();
    (common->config).port.trim();
}

void connectRouter( WIFICONFIG config )
{
    WiFi.begin( config.ssid.c_str(), config.pass.c_str() );
    WiFi.mode( WIFI_STA );

    while( WiFi.status() != WL_CONNECTED ){
        delay( 500 );
    }
}

/* Copyright HAL College of Technology & Design */
