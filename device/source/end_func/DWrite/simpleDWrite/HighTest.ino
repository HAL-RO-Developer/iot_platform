// HighTest.ino
// DegitalWrite
// 引数:なし
// 戻り値:なし
// Created 2017/07/12
// By Hirotaka Nagaoka

// includeファイル
// #include <DeviceControl.h>
#include <ArduinoJson.h>

// 定数定義
#define LED_PIN 16          // LED
#define LED_HIGH HIGH       // High
#define LED_LOW LOW         // Low
#define SET_OUTPUT OUTPUT   // Output
#define SET_INPUT INPUT     // Input

// Setup
void setup( ) {
  Serial.begin(115200);
  // Digital::SetMode( LED_PIN, SET_OUTPUT );
}

// loop
void loop( ) {
  String rtn = "{\"result\":\"NG\"}";
  rtn = digiWrite( LED_PIN, SET_INPUT, LED_HIGH );
  Serial.println(rtn);
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(rtn);
  if (!root.success()) {
    Serial.println("parseObject() failed");
    return;
  }
  String result = root["pin"];

  Serial.println(result);
}

