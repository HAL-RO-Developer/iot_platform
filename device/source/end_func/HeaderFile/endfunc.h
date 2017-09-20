/*
    endfunc.h
    末端関数共通データ定義ヘッダ
    Created 2017/09/20
    By Hirotaka Nagaoka
*/

#ifndef __ENDFUNC_H__
#define __ENDFUNC_H__

/* 構造体宣言 */
typedef struct{
  short port[2];  // ポート情報
  short value;    // データ
} CONTEXT_DATA;

typedef struct{
  short value;    // データ
  short result;   // OK(0)/NG(1)
} RESULT_DATA;

/* 定数定義 */
#define RESULT_OK	( 0 )
#define RESULT_NG	( -1 )

#endif