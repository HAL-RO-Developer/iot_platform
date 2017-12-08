/*
    StateMatrix.cpp

    末端関数マトリクス実体ＲＯＭテーブル

    Created 2017/10/02
    By Shogo Tanaka
    Refactored 2017/12/01
    By Hirotaka Nagaoka
*/

#include "ArduinoLibrary.h"
#include "Function.h"
#include "constants.h"

PORT_MANAGER portManager[] =
{ 
    { DPORT1, DPIN1, NC, OUTPUT },
    { DPORT2, DPIN2, NC, OUTPUT },
    { DPORT3, DPIN3, NC, OUTPUT },
    { DPORT4, DPIN4, NC, OUTPUT },
    { APORT1, APIN1, APIN2, OUTPUT },
    { APORT2, APIN3, APIN4, OUTPUT },
    { IPORT1, SDA, SCL, NULL },
    { IPORT2, SDA, SCL, NULL },
    { NULL, NULL, NULL, NULL }
};

FUNCTION_TABLE functionTable[] =
{
    { FUNCTION_ONCE_DWRITE, onceDWrite},
    { FUNCTION_SIMPLE_DWRITE, simpleDWrite },
    { FUNCTION_BLINK_DWRITE, blinkDWrite },
    { FUNCTION_ONCE_DREAD, onceDRead },
    { FUNCTION_SIMPLE_DREAD, simpleDRead },
    { FUNCTION_ONCE_AWRITE, onceAWrite },
    { FUNCTION_SIMPLE_AWRITE, simpleAWrite },
    { FUNCTION_BLINK_AWRITE, blinkAWrite },
    { FUNCTION_ONCE_AREAD, onceARead },
    { FUNCTION_SIMPLE_AREAD, simpleARead },
    { FUNCTION_I2C_SETUP, I2CSetup },
    { FUNCTION_I2C_WRITE, I2CWrite },
    { FUNCTION_I2C_READ, I2CRead },
    { FUNCTION_I2C_REQUEST_ONE_BYTE, I2CSetup },
    { FUNCTION_UART_SETUP, UARTSetup },
    { FUNCTION_UART_WRITE, UARTWrite },
    { FUNCTION_UART_READ, UARTRead },
    { NULL, NULL }
};

/* Copyright HAL College of Technology & Design */
