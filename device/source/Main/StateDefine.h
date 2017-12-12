/*
    StateDefine.h

    状態に関する定数およびIDの定義

    Created 2017/09/11
    By Shogo Tanaka
*/

#ifndef __STATE_DEFINE_H__
#define __STATE_DEFINE_H__

/* --- 定数定義 --- */
#define STATE_OK                  (    0 )	/* 正常終了 */
#define STATE_NG                  (    1 )	/* システムエラー */
#define STATE_PARAM               (    2 ) 	/* 引数エラー */

/* --- 主状態管理 --- */
#define STATE_SETUP               ( 0x01 )    /* セットアップ状態 */
#define STATE_ACTION              ( 0x02 )    /* 動作状態 */
#define STATE_ERROR               ( 0x04 )    /* エラー状態 */

/* --- 副状態管理 --- */
/* セットアップ状態 */
#define STATE_SETUP_AP            ( 0x11 )    /* APモード状態 */
#define STATE_SETUP_ACTION        ( 0x12 )    /* 動作モード状態 */
/* 動作状態 */
#define STATE_ACTION_RECEIVE      ( 0x21 )    /* 関数受信状態 */
#define STATE_ACTION_EXECUTE      ( 0x22 )    /* 関数実行状態 */
#define STATE_ACTION_IAM          ( 0x24 )    /* 関数通信認証状態 */
#define STATE_ACTION_SERIAL       ( 0x28 )    /* 結果受信状態 */
/* エラー状態 */
#define STATE_ERROR_CONNECT       ( 0x31 )    /* WiFi接続エラー状態 */
#define STATE_ERROR_COMMUNICATE   ( 0x32 )    /* サーバー通信エラー状態 */
#define STATE_ERROR_OTHER         ( 0x34 )    /* その他各種エラー状態 */

/* --- 個別状態管理 --- */
#define INIT                      ( 0x01 )    /* 初期処理 */
#define EXECUTE                   ( 0x02 )    /* 実行処理 */
#define FIN                       ( 0x04 )    /* 終了処理 */

#endif  /* __STATE_STRUCT_H__ */ 

/* Copyright HAL College of Technology & Design */
