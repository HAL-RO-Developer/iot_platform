/*
    FunctionManager.cpp

    末端関数管理クラス

    Created 2017/10/29
    By Shogo Tanaka
    Refactored 2017/12/01
    By Hirotaka Nagaoka
*/
#include "FunctionManager.h"

extern "C"
{
    extern PORT_MANAGER portManager[];
    extern FUNCTION_TABLE functionTable[];
}

/* ポートID選択 */
FunctionManager::FunctionManager( SSHT portId ):
Function( NULL )
{
    for( SINT i = 0; portManager[i].Id != NULL; i++ )
    {
        if( portId == portManager[i].Id )
        {
            Port = portManager[i];
            break;
        }
    }

    Context.Port = Port;
}

FunctionManager::~FunctionManager( )
{}

/* 関数登録 */
SSHT FunctionManager::regist( FUNCTION_INFO info )
{
    FuncId = info.FuncId;
    if( search() == RESULT_NG ){
        return RESULT_NG;
    }
    
    Context.Value = info.Args;
    return RESULT_OK;
}

/* 関数実行 */
SSHT FunctionManager::run( )
{
    SSHT rtn = RESULT_NG;
    if( Function != NULL ){
        rtn = ( *Function )( &Context, &Result );        
    }
    return rtn;
}

/*  */
SSHT FunctionManager::drop( )
{
    FuncId = FUNCTION_NOTHING;
    Function = NULL;

    return RESULT_OK;
}

/*  */
PORT_MANAGER FunctionManager::getPort( )
{
    return Port;
}

/* 関数検索 */
SSHT FunctionManager::search( )
{
    for( SINT i = 0; functionTable[i].Id != NULL; i++ ){
        if( FuncId == functionTable[i].Id )
        {       
            Function = functionTable[i].Function;
            return RESULT_OK;
        }
    }

    return RESULT_NG;

}

/*  */
RESULT_DATA FunctionManager::getResult( )
{
    return Result;
}

/* Json作成 */
String FunctionManager::createJson( )
{
    SCHR json[JSON_SIZE];

    sprintf( json, "{\"port\":%d,\"result\":%d,\"value\":%d}", Port.Id, Result.Result, Result.Value );
    return String( json );
}

/* Copyright HAL College of Technology & Design */
