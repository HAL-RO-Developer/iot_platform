// HighTest.ino
// DegitalWrite
// 引数:なし
// 戻り値:なし
// Created 2017/07/12
// By Hirotaka Nagaoka

// includeファイル
#include <DeviceControl.h>
#include <ArduinoJson.h>

// 定数定義
#define BAUD ( 115200 )

typedef struct {
        port;
  short value;
} CONTEXT_DATA;

typedef struct {
  short value;
  short result;
} RESULT_DATA;

// Setup
void setup( ) {
  Serial.begin( BAUD );
}

// loop
void loop( ) {
  CONTEXT_DATA context;
  context.port = ####;
  context.value = HIGH;
 
  rtn = simpleDWrite( & );
  Serial.println( rtn );
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject( rtn );
  if (!root.success()) {
    Serial.println("parseObject() failed");
    return;
  }
  short r.result = root["pin"];

  Serial.println( r.result );
}

String simpleDWrite( CONTEXT_DATA* context, RESULT_DATA* result ) {
  short rtn=ng;
  if((mode != OUTPUT) || (flag == 0) ){
    Digital::SetMode( context->, OUTPUT );
  }
  Digital::Write( context->pin,context->value );
  rtn=ok
  result->result = rtn;
  result->value=999
  return rtn;
}


