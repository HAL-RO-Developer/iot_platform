/*
    StateStruct.h

    状態に関する構造体の定義

    Created 2017/09/11
    By Shogo Tanaka
*/

#ifndef __STATE_STRUCT_H__
#define __STATE_STRUCT_H__

/* --- 状態テーブル --- */
typedef struct{
    USHT MainState;     /* 主状態   */
    USHT SubState;      /* 副状態   */
    USHT PieceState;    /* 個別状態 */
} STATE_TABLE;

/* --- 副状態テーブル --- */
typedef struct{
    USHT SubState;                                       /* 副状態 */
    SSHT (*Function)( STATE_TABLE*, INFO_COMMON* );     /* 対応する関数ポインタ */
} SUB_STATE_TABLE;

/* --- 主状態テーブル --- */
typedef struct{
    USHT MainState;             /* 主状態 */
    SUB_STATE_TABLE* SubState;  /* 主状態に対応する副状態 */
} MAIN_STATE_TABLE;

#endif  /* __STATE_STRUCT_H__ */ 

/* Copyright HAL College of Technology & Design */
