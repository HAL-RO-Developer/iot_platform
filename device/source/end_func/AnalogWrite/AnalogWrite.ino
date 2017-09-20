// Created 2017/07/15	
// By Riku Hashimoto

// include
#include <DeviceControl.h>
 typedef struct{
    short port[2];   // ポート情報 [0]は今の入出力の状態、[2]はポート番号
    short value;   // データ
}CONTEXT_DATA;


 typedef struct{
     short value;   // データ
     short result;  // 実行結果(OK/NG)
}RESULT_DATA;
CONTEXT_DATA context;
RESULT_DATA  result;

short onceAWrite( CONTEXT_DATA *cdata,RESULT_DATA *rdata);//プロトタイプ宣言しないとエラーを起こす

//定数定義
#define LED_Pin 5
#define PIN_Mode INPUT
#define RESULT_OK 1
#define RESULT_NG 0

//setup
void setup() {
  Serial.begin(115200); 
}

//loop
void loop() {
//必要情報(ポート番号等を構造体に格納)
context.port[0] = PIN_Mode;
context.port[1] = LED_Pin;
context.value = 255;
onceAWrite( &context,&result );
//結果を表示
Serial.println("Result");
Serial.println(context.port[1] );
Serial.println(result.value );
Serial.println(result.result );


delay(1000); //シリアルを見やすくする
}

//onceAWrite
short onceAWrite( CONTEXT_DATA *cdata,RESULT_DATA *rdata){
  short rtn = RESULT_OK;
//INPUTになっていたらOUTPUTに
 if(cdata->port[0] != OUTPUT){
Digital::SetMode(cdata->port[1], OUTPUT);
 }
//出力する
Analog::Write(cdata->port[1],cdata->value);
rdata->value = cdata->value;
rdata->result = rtn;
return rtn;
}

