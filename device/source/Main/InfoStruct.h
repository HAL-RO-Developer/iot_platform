/*
    InfoStruct.h

    構造体の定義

    Created 2017/09/22
    By Shogo Tanaka
*/

#ifndef __INFO_STRUCT_H__
#define __INFO_STRUCT_H__

#include "ArduinoLibrary.h"
#include "System.h"
#include "StatusLED.h"

/* --- 情報管理構造体 --- */

typedef struct{
    String ssid;        /* 接続ルーターSSID      */
    String pass;        /* 接続ルーターパスワード */
    String host;        /* 接続サーバーIPアドレス */
    String port;        /* 接続サーバーポート番号 */
    String pin;         /* PINコード(ワンタイムパス) */
    String device_id;   /* デバイスID            */
} WIFICONFIG;

/* 状態共通情報 */
typedef struct{
    WIFICONFIG config;
    String mac;
    StatusLED* led_r;
    StatusLED* led_g;
    SSHT data1;
    SSHT data2;
} INFO_COMMON;

#endif  /* __INFO_STRUCT_H__ */

/* Copyright HAL College of Technology & Design */
