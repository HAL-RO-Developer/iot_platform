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
#include "InfoStruct.h"         /* 情報管理構造体定義ヘッダ     */

SSHT actionStateRegist( STATE_TABLE* state, INFO_COMMON* common )
{
    return STATE_OK;
}

SSHT actionStateExeceute( STATE_TABLE* state, INFO_COMMON* common )
{
    return STATE_OK;
}

SSHT actionStateSend( STATE_TABLE* state, INFO_COMMON* common )
{
    return STATE_OK;
}

/* Copyright HAL College of Technology & Design */
