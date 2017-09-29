/*
    EndFunc.h
    
    末端関数共通データ定義ヘッダ
    
    Created 2017/09/20
    By Hirotaka Nagaoka
*/

#ifndef __ENDFUNC_H__
#define __ENDFUNC_H__

/* --- typedef宣言 --- */
typedef char           SCHR;		/* signed   char型  */
typedef unsigned char  UCHR;		/* unsigned char型  */		
typedef short          SSHT;		/* signed   short型 */
typedef unsigned short USHT;		/* unsigned short型 */
typedef long           SLNG;		/* signed   long型  */
typedef unsigned long  ULNG;		/* unsigned long型  */
typedef int            SINT;		/* signed   int型   */			
typedef unsigned int   UINT;		/* unsigned int型   */	

/* --- 構造体宣言 --- */
typedef struct{
  SSHT port[2];  /* ポート情報 */
  SSHT value;		 /* データ */
} CONTEXT_DATA;

typedef struct{
  SSHT value;      /* データ */
  SSHT result;   	 /* 実行結果(OK(0)/NG(1)) */
} RESULT_DATA;

/* --- 定数定義 --- */
#define RESULT_OK	(   0 )
#define RESULT_NG	(  -1 )

#endif	/* __ENDFUNC_H__ */ 

/* Copyright HAL College of Technology & Design */
