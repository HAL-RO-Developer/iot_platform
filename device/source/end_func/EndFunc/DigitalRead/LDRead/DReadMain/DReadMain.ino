// simpleDWrite(テスト用)
// Created 2017/09/20
// By Riku Hashimoto

// include
#include "EndFunc.h"

CONTEXT_DATA context;
RESULT_DATA  result;

SSHT LDRead( CONTEXT_DATA* context, RESULT_DATA* result);

// 定数定義(テスト用)
#define OUTPUT_PIN   ( 16   )
#define PIN_MODE     ( OUTPUT  )

// setup
void setup( ){
  Serial.begin(9600);
}

// loop
void loop( ){
SSHT a;
// 必要情報(ポート番号等を構造体に格納)
context.Port.Mode = PIN_MODE;
context.Port.Pin1 = OUTPUT_PIN;
a = LDRead(&context, &result);
if(result.Value != -1){
   Serial.println(result.Value);
  }
}
