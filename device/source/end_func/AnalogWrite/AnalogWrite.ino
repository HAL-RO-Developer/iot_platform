// Created 2017/07/15	
// By Riku Hashimoto

// include
#include <DeviceControl.h>
#define Pin INPUT
 typedef struct{
    short port[2];   // ポート情報 [0]は今の入出力の状態、[2]はポート番号
    short value;   // データ
}c_d;


 typedef struct{
     short value;   // データ
     String result;  // 実行結果(OK/NG)
}r_d;

c_d context;
r_d  result;
void onceAWrite( c_d cdata,r_d *rdata);//プロトタイプ宣言しないとエラーを起こす

//定数定義
#define LED_Pin 5
#define PIN_Mode INPUT


//setup
void setup() {
  Serial.begin(115200); 
}

//loop
void loop() {
//必要情報(ポート番号等を構造体に格納)
context.port[0] = Pin;
context.port[1] = 5;
context.value = 255;
onceAWrite( context,&result );
//結果を表示
Serial.println("Result");
Serial.println(context.port[1] );
Serial.println(result.value );
Serial.println(result.result );


delay(1000); //シリアルを見やすくする
}

//onceAWrite
void onceAWrite( c_d cdata,r_d *rdata){
//INPUTになっていたらOUTPUTに
 if(cdata.port[0] != OUTPUT){
Digital::SetMode(cdata.port[1], OUTPUT);
 }
//出力する
Analog::Write(cdata.port[1],cdata.value);
rdata->value = cdata.value;
rdata->result = "OK";
}

