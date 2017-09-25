/*
SimpleDRead.ino
アナログ入力を行う(指定時間毎)
Created 2017/8/5
 By Riku Hashimoto
*/

// include
#include <DeviceControl.h>
#include <ArduinoJson.h>



 int gCount = 0;
 int gStartTime;
String SimpleDRead(int Pin,int Pin_Mode,int Time){
int Val;
if(gCount == 0){ 
   gStartTime = millis();
  gCount ++;
}
 if(Pin_Mode != INPUT){
     Digital::SetMode(Pin, INPUT);
  }
if(millis()-gStartTime >= Time) {
Val = Digital::Read(Pin);
  String ResultData = "OK";
  String PinData = String(Pin); //使用したポート
 String ValueData = String(Val);//取得値
 String Return = "{\"result\":\"" + ResultData +
                 "\",\"pin\":\"" +PinData +
                 "\",\"value\":\"" +ValueData + 
                 "\"}";               
   gCount = 0;  
 return Return;
}else{
  String ResultData = "OK";
  String PinData = String(Pin); //使用したポート
 String Return = "{\"result\":\"" + ResultData +
                 "\",\"pin\":\"" +PinData +
                 "\",\"value\":\"" 
                 "\"}";
  return Return;
}
}

