/*
    SetupState.cpp

    セットアップ状態関連プログラム

    Created 2017/09/21
    By Shogo Tanaka
*/

/* --- includeファイル --- */
#include "ArduinoLibrary.h"
#include "System.h"             /* システム共通データ定義ヘッダ */
#include "State.h"              /* 状態に関する定義ヘッダ       */
#include "ServerCommunication.h"
#include "StatusLED.h"
#include "constants.h"

/* 定数定義 */
#define TIMEOUT ( 30000 )

/* --- グローバル変数 --- */
extern "C"{
  extern const   SCHR*   settings;
  extern const   SCHR*   ap_ssid;
  extern const   SCHR*   ap_pass;
}
ESP8266WebServer server( 80 );
IPAddress ip( 192, 168, 4, 1 );
IPAddress subnet( 255, 255, 255, 0 );

/* --- プロトタイプ宣言 --- */
void getWiFiConfig( INFO_COMMON* common );
SINT connectRouter( INFO_COMMON* common );
void handleRootGet();
void handleRootPost();

/* --- 関数メイン --- */

/*
    setupStateAp

    セットアップ状態APモード時

    (概要)

    引数:
    STATE_TABLE     state       状態管理テーブル
    INFO_COMMON*    common      データオブジェクト

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
            (common->led_r)->write(HIGH);
            (common->led_g)->startBlink(1000);
            getWiFiConfig( common );
            WiFi.mode(WIFI_AP);
            WiFi.softAPConfig(ip, ip, subnet); 
            WiFi.softAP( ap_ssid, ap_pass );
            Serial.println();     
            Serial.println(WiFi.softAPIP());  
            state->PieceState = EXECUTE;
            break;
        case EXECUTE:
            server.on( "/", HTTP_GET, handleRootGet );
            server.on( "/", HTTP_POST, handleRootPost );
            server.begin();
            state->PieceState = FIN;
            break;
        case FIN:
            (common->led_g)->write();
            server.handleClient();
            delay(1);
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
    INFO_COMMON*    common      データオブジェクト

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
            WiFi.mode(WIFI_STA);
            state->PieceState = EXECUTE;
            break;
        case EXECUTE:
            /* WiFi接続情報の取得 */
            getWiFiConfig( common );            
            /* ルーター接続 */
            if( connectRouter( common ) > TIMEOUT ){
                /* ルーター接続タイムアウト */
                state->SubState = STATE_ERROR_CONNECT;
                return STATE_NG;
            }            
            state->PieceState = FIN;
            break;
        case FIN:
            state->MainState = STATE_ACTION;
            if( (common->config).device_id.equals("") ){
              state->SubState = STATE_ACTION_IAM;
            }else{
              state->SubState = STATE_ACTION_RECEIVE;
            }
            
            state->PieceState = INIT;
            break;
    }

    return STATE_OK;
}

void handleRootGet()
{
    String html = "";
    html += "<h1>WiFi Settings</h1>";
    html += "<form method='post'>";
    html += "  SSID : <input type='text' name='ssid' placeholder='SSID'><br>";
    html += "  PASS : <input type='password' name='pass' placeholder='PASS'><br>";
    html += "  HOST : <input type='text' name='host' placeholder='HOST'><br>";
    html += "  PORT : <input type='text' name='port' placeholder='PORT'><br>";
    html += "  PIN  : <input type='text' name='pin' placeholder='PIN'><br>";
    html += "  <input type='submit'><br>";
    html += "</form>";
    
    server.send( 200, "text/html", html );
}

void handleRootPost()
{
    String  ssid = server.arg("ssid");
    String  pass = server.arg("pass");
    String  host = server.arg("host");
    String  port = server.arg("port");
    String  pin  = server.arg("pin");

    /* JSON作成 */
    String json = "{";
    json += "\"ssid\":\"" + ssid + "\",";
    json += "\"pass\":\"" + pass + "\",";
    json += "\"host\":\"" + host + "\",";
    json += "\"port\":\"" + port + "\",";
    json += "\"pin\":\""  + pin  + "\",";
    json += "\"device_id\":\"\"}";

    File    fd = SPIFFS.open( settings, "w" );
    fd.println( json );
    fd.close();
    
    String html = "";
    html += "<h1>WiFi Settings</h1>";
      html += "<p>Settings changed</p>";
      html += "<table>";
      html += "  <tr><td>SSID</td><td>" + ssid + "</td></tr>";
      html += "  <tr><td>PASS</td><td>[Not display]</td></tr>";
      html += "  <tr><td>HOST</td><td>" + host + "</td></tr>";
      html += "  <tr><td>PORT</td><td>" + port + "</td></tr>";
      html += "  <tr><td>PIN</td><td>" + pin + "</td></tr>";
      html += "</table>";
	  server.send( 200, "text/html", html );
}

void getWiFiConfig( INFO_COMMON* common )
{
    SCHR json[256];
    
    File   fd = SPIFFS.open( settings, "r" );
    String jsonString = fd.readString();
    fd.close();

    Serial.println(jsonString);
    jsonString.toCharArray( json, jsonString.length() + 1 );

    DynamicJsonBuffer jb;
    JsonObject& root = jb.parseObject( json );

    const SCHR* ssid = root["ssid"];
    const SCHR* pass = root["pass"];
    const SCHR* host = root["host"];
    const SCHR* port = root["port"];
    const SCHR* pin  = root["pin"];
    const SCHR* device_id = root["device_id"];

    (common->config).ssid = String( ssid );
    (common->config).pass = String( pass );
    (common->config).host = String( host );
    (common->config).port = String( port );
    (common->config).pin  = String( pin );
    (common->config).device_id = String( device_id );

#if DEBUG 
    Serial.println("SSID:" + (common->config).ssid);
    Serial.println("PASS:" + (common->config).pass);
    Serial.println("HOST:" + (common->config).host);
    Serial.println("PORT:" + (common->config).port);
    Serial.println("PIN :" + (common->config).pin);
    Serial.println("DEV :" + (common->config).device_id);
#endif    
}

SINT connectRouter( INFO_COMMON* common )
{
     
    WiFi.begin( (common->config).ssid.c_str(), (common->config).pass.c_str() );
    WiFi.mode( WIFI_STA );

    SINT time;
    int start = millis();
    (common->led_r)->write(HIGH);
    (common->led_g)->startBlink(100);
    while( WiFi.status() != WL_CONNECTED ){
        int current = millis();
        if( ( time = current - start ) >= TIMEOUT ){
            break;
        }
        (common->led_g)->write();
        delay( 100 );
    }
    (common->led_g)->stopBlink();
    (common->led_g)->write( LOW );

    return time;
}

/* Copyright HAL College of Technology & Design */
