/*
    FunctionPrototype.h
    
    末端関数プロトタイプ宣言
    
    Created 2017/09/20
    By Hirotaka Nagaoka
*/

#ifndef __FUNCTION_PROTOTYPE_H__
#define __FUNCTION_PROTOTYPE_H__

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
SSHT UARTSetup( CONTEXT_DATA*,RESULT_DATA* );
SSHT SoftwareSerialSetup( CONTEXT_DATA*, RESULT_DATA* );
SSHT UARTRead( CONTEXT_DATA*,RESULT_DATA* );
SSHT UARTWrite( CONTEXT_DATA*, RESULT_DATA* );

#endif  /* __FUNCTION_PROTOTYPE_H__ */ 

/* Copyright HAL College of Technology & Design */
