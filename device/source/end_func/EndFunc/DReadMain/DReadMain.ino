// simpleDWrite(テスト用)
// Created 2017/12/1
// By Riku Hashimoto

// include
#include "EndFunc.h"

CONTEXT_DATA context;
RESULT_DATA  result;
SSHT DRead( CONTEXT_DATA *, RESULT_DATA * );
// 定数定義(テスト用)
#define OUTPUT_PIN   ( 4     )
#define PIN_MODE     ( OUTPUT  )
#define T_VALUE      ( 255   )
#define SERIAL_TIME  ( 115200 )
#define MS_TIME      ( 5000   )  // 設定時間

// setup
void setup( ){
  Serial.begin(9600);
}

// loop
void loop( ){
SSHT Value[1] = {1} ;

// 必要情報(ポート番号等を構造体に格納)
context.Port.Mode = PIN_MODE;
context.Port.Pin1 = OUTPUT_PIN;
context.Value = Value;
DRead(&context, &result);
if(result.Value != -1){
   Serial.println(result.Value);
  }
}
