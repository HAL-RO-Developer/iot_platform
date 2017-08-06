/*
onceDRead.ino
アナログ入力を行う
Created 2017/8/5
 By Riku Hashimoto
*/


#include <DeviceControl.h>

String onceDRead(int Pin,int Pin_Mode){
  int Val;
 if(Pin_Mode != INPUT){
     Digital::SetMode(Pin, INPUT);
 }
Val = digitalRead(Pin);//アナログ値取得
  String ResultData = "OK";
  String PinData = String(Pin); //使用したポート
 String ValueData = String(Val);//取得値
 String Return = "{\"result\":\"" + ResultData +
                 "\",\"pin\":\"" +PinData +
                 "\",\"value\":\"" +ValueData + 
                 "\"}";
 taskkill();//タスクの終了(ダミー)                 
return Return;
}

String taskkill(){
  String taskend = "TaskEND";
 return taskend;
 }
 
