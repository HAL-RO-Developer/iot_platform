// includeファイル
#include <ArduinoJson.h>
#include <DeviceControl.h>

// 定数定義
#define LED_PIN 16          // LED
#define LED_HIGH HIGH       // High
#define LED_LOW LOW         // Low
#define SET_OUTPUT OUTPUT   // Output
#define SET_INPUT INPUT     // Input

unsigned long startTime;

void setup() {
  // 開始時間
  startTime = millis();
  // ボーレート初期化
  Serial.begin( 115200 );
  Digital::SetMode( LED_PIN, OUTPUT );
}

void loop() {
  String rtn = "{\"result\":\"NG\"}";
  String timertn = "{\"result\":\"NG\"}";
  unsigned long nowTime;
  unsigned long elapsedTime;
  // JSON用に固定バッファを確保
  StaticJsonBuffer<200> jsonBuffer;
  // 現在時間
  nowTime = millis();
  //  経過時間
  elapsedTime = nowTime - startTime;
  // Serial.println(elapsedTime);

  timertn = timerResult( elapsedTime );
  JsonObject& root = jsonBuffer.parseObject( timertn );

  // 経過時間5000ms
  if( elapsedTime > 5000 ){
    rtn = digiWrite( LED_PIN, SET_OUTPUT, LED_HIGH );
    taskkill();
    String ok = root["OK"];
    Serial.println(ok);
    String timer = root["time"];
    Serial.println(timer);
  }else{
    rtn = digiWrite( LED_PIN, SET_OUTPUT, LED_LOW );
    String ng = root["NG"];
    Serial.println(ng);
  }
  // JsonObjectはJSONBufferに格納、パースされた結果を参照保持する
  // データを参照する場合はこのJsonObjectを見に行く
  // メモリはスコープから出た際に開放
  // JsonObject& root2 = jsonBuffer.parseObject(rtn);
  // パースが成功したか確認
  if (!root.success()) {
    Serial.println("parseObject() failed");
    return;
  }

  // String result = root2[ "result" ];
  // Serial.println(result);
}

// digiWrite
String digiWrite( int pin, int mode, int val ){
  String resultStr = "OK";
  String pinStr = String(pin);
  String modeStr = String(mode);
  String valueStr = String(val);
  String rtn = "{\"result\":\"" +
                 resultStr +
                "\",\"pin\":\"" +
                pinStr +
                "\",\"mode\":\"" +
                modeStr +
                "\",\"value\":\"" +
                valueStr +
                "\"}";
  if( mode != OUTPUT ){
    Digital::SetMode( pin, OUTPUT );
  }
  Digital::Write( pin, val );
  return rtn;
}

// timerResult
String timerResult(int timeValue){
  String resultOK = "OK";
  String resultNG = "NG";
  String timeStr = String(timeValue);
  String rtn = "{\"OK\":\"" +
                resultOK +
                "\",\"NG\":\"" +
                resultNG +
                "\",\"time\":\"" +
                timeStr +
                "\"}";
  return rtn;
}

// dummy
void taskkill(){
  Serial.println("task END OK");
}
