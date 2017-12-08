/*
    pre.h

    制御関数に関するヘッダファイル

    Created 2017/11/15
    By Hirotaka Nagaoka
    Refactored 2017/12/01
    By Hirotaka Nagaoka
*/

#ifndef __PRE_H__
#define __PRE_H__

#include "ArduinoLibrary.h"     /* Arduinoライブラリヘッダ       */
#include "System.h"             /* システム共通データ定義ヘッダ   */
#include "Function.h"           /* 末端関数に関するヘッダファイル */
#include "FunctionManager.h"    /* 末端関数管理クラス            */
#include "constants.h"          /* デバイスピンアサイン          */

#define BAUDRATE         ( 115200 )  /* ボーレート      */

#define JSON_BUFFER_SIZE (   1000 )  /* JSONバッファ    */
#define JSON_SIZE        (    256 )  /* JSON領域サイズ  */
#define PORT_SIZE        (      8 )  /* ポート領域サイズ */
#define FUNC_ARGS_MAX    (      8 )  /*  */

#define REGIST_OK        (      1 )  /* 登録成功        */
#define REGIST_NG        (     -1 )  /* 登録失敗        */

#define SEND_OK          (      1 )  /* 送信成功        */
#define SEND_NG          (     -1 )  /* 送信失敗        */
#define SEND_DELAY       (      8 )  /* 送信時間(8秒)   */

SSHT regist( FunctionManager** fm, FUNCTION_INFO info, String json );   /* 登録 */
SSHT run( FunctionManager* fm );                                        /* 実行 */
SSHT send( FunctionManager** fm );                                      /* 送信 */

#endif /* __PRE_H__ */

/* Copyright HAL College of Technology & Design */
