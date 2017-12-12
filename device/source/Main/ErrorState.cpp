/*
    ErrorState.cpp

    エラー状態関連プログラム

    Created 2017/09/21
    By Shogo Tanaka
*/

/* --- includeファイル --- */
#include "ArduinoLibrary.h"
#include "System.h"             /* システム共通データ定義ヘッダ */
#include "State.h"              /* 状態に関する定義ヘッダ       */
#include "StatusLED.h"
#include "constants.h"

SSHT errorStateConnect( STATE_TABLE* state, INFO_COMMON* common )
{
    switch(state->PieceState){
        case INIT:
            (common->led_g)->write( HIGH );
            (common->led_r)->startBlink( 250 );
            state->PieceState = EXECUTE;
            break;
        case EXECUTE:
            (common->led_r)->write();
            break;
        case FIN:
            break;
    }
    return STATE_OK;
}

SSHT errorStateCommunicate( STATE_TABLE* state, INFO_COMMON* common )
{
    switch(state->PieceState){
        case INIT:
            (common->led_g)->write( HIGH );
            (common->led_r)->startBlink( 500 );
            state->PieceState = EXECUTE;
            break;
        case EXECUTE:
            (common->led_r)->write();
            break;
        case FIN:
            break;
    }
    return STATE_OK;
}

SSHT errorStateOther( STATE_TABLE* state, INFO_COMMON* common )
{
    switch(state->PieceState){
        case INIT:
            (common->led_g)->write( HIGH );
            (common->led_r)->startBlink( 1000 );
            state->PieceState = EXECUTE;
            break;
        case EXECUTE:
            (common->led_r)->write();
            break;
        case FIN:
            break;
    }
    return STATE_OK;
}

/* Copyright HAL College of Technology & Design */
