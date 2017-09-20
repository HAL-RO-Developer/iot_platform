/*
    StateStruct.h

    状態に関する構造体の定義

    Created 2017/09/11
    By Shogo Tanaka
*/

#ifndef __STATE_STRUCT_H__
#define __STATE_STRUCT_H__

/* --- 状態テーブル --- */
typedef struct _STATE_TABLE{
    USHT MainState;     /* 主状態   */
    USHT SubState;      /* 副状態   */
    USHT PieceState;    /* 個別状態 */
} STATE_TABLE;

/* --- 副状態テーブル --- */
typedef struct _SUB_STATE_TABLE{
    USHT SubState;                                       /* 副状態 */
    SSHT (＊Function)( STATE_TABLE*, void* object );     /* 対応する関数ポインタ */
} SUB_STATE_TABLE;

/* --- 主状態テーブル --- */
typedef struct _MAIN_STATE_TABLE{
    USHT MainState;             /* 主状態 */
    SUB_STATE_TABLE* SubState;  /* 主状態に対応する副状態 */
} MAIN_STATE_TABLE;

/* --- 状態情報管理構造体 --- */

/* 入力データ関係 */
typedef struct _INPUT_DATA {
	SSHT data1;
} INPUT_DATA;

typedef struct _STATE_INFO_COMMON {
	INPUT_DATA input;
	SSHT data1;
	SSHT data2;
} STATE_INFO_COMMON;

/*
typedef struct _STATE_INFO_SETUP {
	STATE_INFO_COMMON common;
	SSHT sdata1;
	SSHT sdata2;
	SSHT sdata3;
} STATE_INFO_SETUP;

typedef struct _STATE_INFO_ACTION {
	STATE_INFO_COMMON common;
	SSHT adata1;
	SSHT adata2;
	SSHT adata3;
} STATE_INFO_ACTION;

typedef struct _STATE_INFO_ERROR {
	STATE_INFO_COMMON common;
	SSHT edata1;
	SSHT edata2;
	SSHT edata3;
} STATE_INFO_ERROR;
*/

/* 情報管理共用体 */
typedef union _STATE_INFO {
	STATE_INFO_SETUP StateInfoSetup;
	STATE_INFO_ACTION SateInfoAction;
	STATE_INFO_ERROR StateInfoError;
} STATE_INFO;

#endif  /* __STATE_STRUCT_H__ */ 

/* Copyright HAL College of Technology & Design */
