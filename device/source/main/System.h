/*
    System.h

    システム共通データ定義ヘッダ

    Created 2017/09/11
    By Shogo Tanaka
*/

/* --- typedef宣言 --- */
typedef char           SCHR;		// signed   char型
typedef unsigned char  UCHR;		// unsigned char型		
typedef short          SSHT;		// signed   short型
typedef unsigned short USHT;		// unsigned short型
typedef long           SLNG;		// signed   long型
typedef unsigned long  ULNG;		// unsigned long型
typedef int            SINT;		// signed   int型			
typedef unsigned int   UINT;		// unsigned int型	

/* --- 定数定義 --- */
#define SYSTEM_OK       (    0 )	// 正常終了
#define SYSTEM_NG       (   -1 )	// システムエラー
#define SYSTEM_PARAM    (   -2 ) 	// 引数エラー		

#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#endif  /* __SYSTEM_H__ */

/* Copyright HAL College of Technology & Design */
