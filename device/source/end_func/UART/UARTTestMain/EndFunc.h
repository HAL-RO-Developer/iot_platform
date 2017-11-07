/*
    EndFunc.h
    
    末端関数共通データ定義ヘッダ
    
    Created 2017/09/20
    By Hirotaka Nagaoka
*/

#ifndef __ENDFUNC_H__
#define __ENDFUNC_H__

/* --- typedef宣言 --- */
typedef char           SCHR;    /* signed   char型  */
typedef unsigned char  UCHR;    /* unsigned char型  */   
typedef short          SSHT;    /* signed   short型 */
typedef unsigned short USHT;    /* unsigned short型 */
typedef long           SLNG;    /* signed   long型  */
typedef unsigned long  ULNG;    /* unsigned long型  */
typedef int            SINT;    /* signed   int型   */     
typedef unsigned int   UINT;    /* unsigned int型   */ 

/* --- 定数定義 --- */
#define RESULT_OK  (   0 )
#define RESULT_NG  (  -1 )

/* --- 構造体宣言 --- */
typedef struct{
  USHT id;            /* ID情報 */
  USHT pin1;          /* PIN1 */
  USHT pin2;          /* PIN2 */
  USHT mode;          /* モード */
} PORT_MANAGER;

typedef struct{
    PORT_MANAGER port; /* ポート情報 */
    SSHT* value;       /* データ */
} CONTEXT_DATA;

typedef struct{
    SSHT value;        /* データ */
    SSHT result;       /* 実行結果(OK(0)/NG(1)) */
} RESULT_DATA;

/* --- プロトタイプ宣言 --- */
/* DigitalRead */
SSHT onceDRead( CONTEXT_DATA*, RESULT_DATA* );
SSHT simpleDRead( CONTEXT_DATA*, RESULT_DATA* );

/* DigitalWrite */
SSHT onceDWrite( CONTEXT_DATA*, RESULT_DATA* );
SSHT simpleDWrite( CONTEXT_DATA*, RESULT_DATA* );
SSHT blinkDWrite( CONTEXT_DATA*, RESULT_DATA* );

/* AnalogRead */
SSHT onceARead( CONTEXT_DATA*, RESULT_DATA* );
SSHT simpleARead( CONTEXT_DATA*, RESULT_DATA* );

/* AnalogWrite */
SSHT onceAWrite( CONTEXT_DATA*, RESULT_DATA* );
SSHT simpleAWrite( CONTEXT_DATA*, RESULT_DATA* );
SSHT blinkAWrite( CONTEXT_DATA*, RESULT_DATA* );

/* I2C */
SSHT I2CSetup( CONTEXT_DATA*, RESULT_DATA* );
SSHT I2CRequestonebyte( CONTEXT_DATA*, RESULT_DATA* );
SSHT I2CRead( CONTEXT_DATA*, RESULT_DATA* );
SSHT I2CWrite( CONTEXT_DATA*, RESULT_DATA* );

/* UART */
SSHT UARTSetup( CONTEXT_DATA*, RESULT_DATA* );
SSHT SoftwareSerialSetup( CONTEXT_DATA*, RESULT_DATA* );
SSHT UARTRead( CONTEXT_DATA*, RESULT_DATA* );
SSHT UARTWrite( CONTEXT_DATA*, RESULT_DATA* );

#endif  /* __ENDFUNC_H__ */ 

/* Copyright HAL College of Technology & Design */

