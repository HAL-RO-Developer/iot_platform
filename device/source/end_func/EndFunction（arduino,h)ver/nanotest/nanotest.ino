// arduino nano(テスト用)
// Created 2017/11/23
// By Riku Hashimoto

// include
#include "EndFunc.h"

CONTEXT_DATA context;
RESULT_DATA  result;
// 定数定義(テスト用)
#define OUTPUT_PIN   ( 13   )
#define PIN_MODE     ( INPUT  )
//#define T_VALUE      ( HIGH   )
#define T_VALUE      ( 255   )
#define SERIAL_TIME  ( 115200 )
#define MS_TIME      ( 2000   )  // 設定時間

// setup
void setup( ){
  Serial.begin(9600);
}

// loop
void loop( ){
SSHT Value[2] = { T_VALUE, MS_TIME } ;

// 必要情報(ポート番号等を構造体に格納)
context.Port.Mode = PIN_MODE;
context.Port.Pin1 = OUTPUT_PIN;
context.Value = Value;

blinkAWrite(&context, &result);
/*if(result.Value == !(T_VALUE)){ //simpleDWriteが終了したら1秒待つ
  delay(1000);
  }*/
}
