/*
    DeviceStruct.h

    構造体の定義

    Created 2017/10/02
    By Shogo Tanaka
    Refactored 2017/12/01
    By Hirotaka Nagaoka
*/

#ifndef __DEVICE_STRUCT_H__
#define __DEVICE_STRUCT_H__

#include "System.h"

/* ポート情報 */
typedef struct
{
    USHT    Id;     /* ID */
    USHT    Pin1;   /* ピン01 */
    USHT    Pin2;   /* ピン02 */
    USHT    Mode;   /* モード */
} PORT_MANAGER;

/* 引数 */
typedef struct
{
    PORT_MANAGER Port;  /* ポート情報管理 */
    SSHT*        Value; /* 値 */
} CONTEXT_DATA;

/* 返却 */
typedef struct
{
    SSHT Result;    /* 返却値 */
    SSHT Value;     /* 値 */
} RESULT_DATA;

/* 関数テーブル */
typedef struct
{
    USHT Id;    /* 関数ID */
    SSHT ( *Function )( CONTEXT_DATA*, RESULT_DATA* );  /* 引数 */
} FUNCTION_TABLE;

/* 関数情報 */
typedef struct
{
    USHT    PortId; /* ポートID */
    USHT    FuncId; /* 末端ID */
    SSHT*   Args;   /* 値 */
} FUNCTION_INFO;

#endif /* __DEVICE_STRUCT_H__ */
