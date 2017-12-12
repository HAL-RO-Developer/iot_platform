/*
    ActionState.cpp

    動作状態関連プログラム

    Created 2017/09/21
    By Shogo Tanaka
*/

/* --- includeファイル --- */
#include <string.h>
#include "ArduinoLibrary.h"
#include "System.h"                 /* システム共通データ定義ヘッダ */
#include "State.h"                  /* 状態に関する定義ヘッダ       */
#include "InfoStruct.h"             /* 情報管理構造体定義ヘッダ     */
#include "ServerCommunication.h"    /* サーバー通信クラス */

/* --- 定数定義 --- */
#define DATA_REQUEST ( '#' )       /* マイコン間データ受信リクエストコード */

/* --- グローバル変数 --- */
extern "C"{
  extern const   SCHR*   settings;
}

/* サーバー通信クラス */
ServerCommunication sc;

/* IOマイコン送受信データ */
String sndData = ""; 
String rcvData = "";

/* プロトタイプ宣言 */
BOOL registDeviceId( INFO_COMMON* common, String jsonString );
BOOL getJsonValue( String jsonString, String key, String* value );
BOOL updateJson( String* jsonString, String key, String value );

SSHT actionStateReceive( STATE_TABLE* state, INFO_COMMON* common )
{ 
    String reqData;
    String resData;
    
    /* --- サーバーに接続 --- */
    if( sc.connect( (common->config).host, (common->config).port ) == SERVER_CONNECT_ERROR ){
        state->SubState = STATE_ERROR_COMMUNICATE;
        return STATE_NG;
    }

    /* --- リクエストJSONの作成 --- */
    reqData = "{";
    reqData += "\"device_id\":\"" + (common->config).device_id + "\",";
    reqData += "\"mac\":\"" + common->mac + "\",";
    reqData += "\"port\":[";
    if( !rcvData.equals("") ){
      reqData += ",";
      reqData += rcvData;
    }
    reqData += "]}";
    
#if DEBUG    
    Serial.println(reqData);
#endif   
    /* --- POSTリクエスト --- */
    sc.request("/device/receive", reqData);
    
    /* --- POSTレスポンス --- */
    int status = sc.response(&sndData);
    switch( status ){
        case HTTP_STATUS_OK:
            /* リクエスト成功 */
            state->SubState = STATE_ACTION_EXECUTE;
            break;
#if IAM
        case HTTP_STATUS_FORBIDDEN:
            /* 未認証 */
            state->SubState = STATE_ACTION_IAM;
            break;
#endif
        default:
            /* リクエスト失敗 */
            state->SubState = STATE_ERROR_COMMUNICATE;
            return STATE_NG;
            break;
    }

    return STATE_OK;

}

SSHT actionStateExecute( STATE_TABLE* state, INFO_COMMON* common )
{
    /* IOマイコンに受信データを送信 */
    Serial.println( sndData );
    state->SubState = STATE_ACTION_SERIAL;

    return STATE_OK;
}

SSHT actionStateIam( STATE_TABLE* state, INFO_COMMON* common ){
    String reqData;
    String resData;
    
    /* --- サーバーに接続 --- */
    if( sc.connect( (common->config).host, (common->config).port ) == SERVER_CONNECT_ERROR ){
        state->SubState = STATE_ERROR_COMMUNICATE;
        return STATE_NG;
    }

    /* --- リクエストJSONの作成 --- */
    reqData = "{";
    reqData += "\"pin\":\"" + (common->config).pin + "\",";
    reqData += "\"mac\":\"" + common->mac + "\"";
    reqData += "}";
    
    /* --- POSTリクエスト --- */
    sc.request("/device/iam", reqData);
    delay(3000);

    /* --- POSTレスポンス --- */
    int status = sc.response(&resData);
    switch( status ){
        case HTTP_STATUS_OK:
            /* 認証成功 */
            if( !registDeviceId(common,resData) ){
                state->SubState = STATE_ERROR_OTHER;
                return STATE_NG;       
            }
            state->SubState = STATE_ACTION_RECEIVE;
            break;
        default:
            /* 認証失敗 */
            state->SubState = STATE_ERROR_OTHER;
            return STATE_NG;
            break;
    }  

    // Serial.println(resData);
   
}

SSHT actionStateSerial( STATE_TABLE* state, INFO_COMMON* common )
{
    static BOOL flg = false;
    static BOOL pflg = false;
    SCHR c;
    /* --- IOマイコンから実行結果を受信 --- */
    if( !flg ){
      flg = true;
      rcvData = "";
      Serial.print( DATA_REQUEST );  
      delay(10);
    }
    
    if( Serial.available() > 0 ){
        c = Serial.read();
        if( c == '\n' ){
          flg = false;
          pflg = false;
          state->SubState = STATE_ACTION_RECEIVE;
          //Serial.println(rcvData);
          return STATE_OK;
        }
        if( c == '\0' ){ pflg = false; }
        if( pflg ){ rcvData += c; }
        if( c == '$' ){ pflg = true; }
        delay(10); 
    }
    return STATE_OK;
}

BOOL registDeviceId( INFO_COMMON* common, String jsonString )
{
    String device_id;
    getJsonValue( jsonString, "device_id", &device_id );
    
    (common->config).device_id = device_id;
   
    File   fd = SPIFFS.open( settings, "r" );
    String config = fd.readString();
    fd.close();
    updateJson( &config, "device_id", device_id );
    
    fd = SPIFFS.open( settings, "w" );
    fd.print(config);
    fd.close();
    return true;
}

BOOL getJsonValue( String jsonString, String key, String* value )
{
    SCHR json[256];
    jsonString.toCharArray( json, jsonString.length() + 1 );
    DynamicJsonBuffer jb;
    JsonObject& root = jb.parseObject( json );
    if( !root.success() ){ return false; }
    const SCHR* buffer = root[key];
    *value =  String( buffer );
} 

BOOL updateJson( String* jsonString, String key, String value )
{
    SCHR json[256];
    jsonString->toCharArray( json, jsonString->length() + 1 );
    DynamicJsonBuffer jb;
    JsonObject& root = jb.parseObject( json );
    if( !root.success() ){ return false; }
    root[key] = value;
    char buffer[256];
    root.printTo( buffer, 256 );
    *jsonString = String( buffer );
}               

/* Copyright HAL College of Technology & Design */

