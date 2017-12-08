/*
    FunctionManager.h

    末端関数管理クラス

    Created 2017/10/29
    By Shogo Tanaka
    Refactored 2017/12/01
    By Hirotaka Nagaoka
*/

#ifndef __FUNCTION_MANAGER_H__
#define __FUNCTION_MANAGER_H__

#include "ArduinoLibrary.h"
#include "System.h"     /* システム共通データ定義ヘッダ */
#include "Function.h"
#include "constants.h"

class FunctionManager
{

private:
    /* member */
    USHT          FuncId;
    USHT*         Args;
    CONTEXT_DATA  Context;
    RESULT_DATA   Result;
    PORT_MANAGER  Port;
    SSHT          ( *Function )( CONTEXT_DATA*, RESULT_DATA* );
public:
    /* constructor */
    FunctionManager( SSHT portId );
    /* destructor */
    ~FunctionManager( );
    /* methode*/
    SSHT          regist( FUNCTION_INFO info );
    SSHT          run( );
    SSHT          drop( );
    PORT_MANAGER  getPort( );
    RESULT_DATA   getResult( );
    String        createJson( );
private:
    SSHT          search( );
};

#endif /* __FUNCTION_MANAGER_H__ */

/* Copyright HAL College of Technology & Design */
