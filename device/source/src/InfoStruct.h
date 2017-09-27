/*
    Struct.h

    構造体の定義

    Created 2017/09/22
    By Shogo Tanaka
*/

#ifndef __INFO_STRUCT_H__
#define __INFO_STRUCT_H__

#include "ArduinoLibrary.h"

/* --- 情報管理構造体 --- */

typedef struct{
    string ssid;    /* 接続ルーターSSID      */
    string pass;    /* 接続ルーターパスワード */
    string host;    /* 接続サーバーIPアドレス */
    string port;    /* 接続サーバーポート番号 */
} WIFICONFIG;

/* 入力データ関係 */
typedef struct{
	SSHT data1;
} INPUT_INFO;


/* 状態共通情報 */
typedef struct{
    WIFICONFIG config;
    INPUT_INFO input;
	SSHT data1;
	SSHT data2;
} INFO_COMMON;

#endif  /* __INFO_STRUCT_H__ */

/* Copyright HAL College of Technology & Design */
