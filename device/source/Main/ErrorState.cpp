/*
    ArduinoLibrary.h

    Arduinoライブラリヘッダ

    Created 2017/09/21
    By Shogo Tanaka
*/

/* --- includeファイル --- */
#include "ArduinoLibrary.h"
#include "System.h"             /* システム共通データ定義ヘッダ */
#include "State.h"              /* 状態に関する定義ヘッダ       */
#include "constants.h"

//#define MSEC2CLOCK(ms)    (ms * 80000L)

Ticker tickerLED;
static int output = HIGH;

void flash();

SSHT errorStateConnect( STATE_TABLE* state, INFO_COMMON* common )
{
    digitalWrite( SLPR, HIGH );
    return STATE_OK;
}

SSHT errorStateCommunicate( STATE_TABLE* state, INFO_COMMON* common )
{
    digitalWrite( SLPR, HIGH );
    return STATE_OK;
}

SSHT errorStateOther( STATE_TABLE* state, INFO_COMMON* common )
{
    Serial.println("<<errorStateOther>>");
    switch(state->PieceState){
        case INIT:
            digitalWrite( SLPG, LOW );
            tickerLED.attach_ms(1000, flash);
            state->PieceState = EXECUTE;
            break;
        case EXECUTE:
            Serial.println(output);
            digitalWrite( SLPR, output );
            break;
        case FIN:
            break;
    }
    return STATE_OK;
}

void flash()
{
    output = !output;
}


/* Copyright HAL College of Technology & Design */
