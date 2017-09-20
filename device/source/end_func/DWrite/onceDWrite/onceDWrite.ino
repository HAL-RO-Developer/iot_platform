/*
    onceDWrite.ino
    Created 2017/09/20
    By Hirotaka Nagaoka
*/

#include <DeviceControl.h>

/* 定数定義 */
#define BAUDRATE ( 115200 )   // ボーレート
#define LED_PIN ( 10 )        // ポート指定
#define PIN_MODE ( INPUT )    // モード
#define RESULT_OK ( 0 )       // OK
#define RESULT_NG ( 1 )       // NG

/* 構造体宣言 */
// context
typedef struct{
  short port[2];  // ポート情報
  short value;    // データ
} CONTEXT_DATA;

// result
typedef struct{
  short value;    // データ
  short result;   // OK(0)/NG(1)
} RESULT_DATA;

/* プロトタイプ宣言 */
short onceDWrite( CONTEXT_DATA *c_data, RESULT_DATA *r_data );

CONTEXT_DATA context;
RESULT_DATA result;

// setup
void setup( ) {
  Serial.begin( BAUDRATE );   // ボーレート
}

// loop
void loop( ) {
  context.port[0] = PIN_MODE;
  context.port[1] = LED_PIN;
  context.value = HIGH;
  onceDWrite( &context, &result );
  // 確認用
  Serial.println( "Result" );
  Serial.println( context.port[1] );
  Serial.println( result.value );
  Serial.println( result.result );
  delay( 1000 );
}

short onceDWrite( CONTEXT_DATA *c_data, RESULT_DATA *r_data ){
  short check = RESULT_NG;
  // モードチェック
  if( c_data->port[0] != OUTPUT ){
    Digital::SetMode( c_data->port[1], OUTPUT );
  }
  // 出力
  Digital::Write( c_data->port[1], c_data->value );
  check = RESULT_OK;
  r_data->value = c_data->value;
  r_data->result = check;
  return check;
}

