/*
    StateControl.cpp

    状態遷移制御

    Created 2017/09/14
    By Shogo Tanaka
*/

/* --- includeファイル --- */
#include "System.h"     /* システム共通データ定義ヘッダ */
#include "State.h"      /* 状態に関する定義ヘッダ       */

/* --- extern宣言 --- */
extern MAIN_STATE_TABLE gMainStateTable[];                  /* 主状態テーブル */
extern SSHT ( *function( STATE_TABLE*, void* object ) );

/* --- プロトタイプ宣言 --- */
SUB_STATE_TABLE* getSubState( USHT mainState );
SSHT ( *getFunction( SUB_STATE_TABLE* subState, USHT id ))( STATE_TABLE* );

/* --- 関数メイン --- */
/*
    callFunction

    状態遷移関数Call

    該当する状態遷移先関数ポインタの検索および処理の実行

    引数:
    STATE_TABLE state       状態管理テーブル
    void*       object      データオブジェクト(仮データ)

    戻り値:
    SSHT        STATE_OK    正常終了
                STATE_NG    システムエラー
                STATE_PARAM 引数エラー

    Created 2017/09/14
    By Shogo Tanaka
*/
SSHT callFunction( STATE_TABLE* state, void* object )
{
    SUB_STATE_TABLE* table = NULL;
    SSHT ( *function )( STATE_TABLE*, void* ) = NULL;

    /* --- 引数チェック --- */
    if(( state == NULL ) || ( object == NULL )) {
	    return STATE_PARAM;
    }
    
    /* --- 副状態の取得 --- */
    table = getSubState( state->MainState );
    if( table = NULL ){
        /* 副状態取得失敗 */
        return STATE_NG;
    }

    /* --- 状態遷移先関数ポインタの取得 --- */
    function = getFunction( table, state->SubState );
    if( function == NULL ){
        /* 関数ポインタ取得失敗 */
        return STATE_NG;
    }

    /* --- 状態遷移先関数Call --- */
    return ( *function )( state, object );


}

/*
    getSubState

    副状態取得

    主状態に対応する副状態テーブルを取得。

    引数:
    USHT                mainState          主状態

    戻り値:
    SUB_STATE_TABLE*    other than  NULL   副状態関数テーブルの先頭アドレス
                                    NULL   システムエラー       

    Created 2017/09/14
    By Shogo Tanaka
*/
SUB_STATE_TABLE* getSubState( USHT mainState )
{
    USHT index = 0;
    SUB_STATE_TABLE* table = NULL;

    /* --- 引数チェック --- */
    if( MainState == NULL ){
	    return STATE_PARAM;
    }

    /* --- 検索ループ --- */
    for( index = 0; gMainStateTable[index].SubState != NULL; index++ ){
        if( mainState == gMainStateTable[index].MainState ){
            /* 副状態取得 */
            table = gMainStateTable[index].SubState;
            break;
        }
    }

    return table;
    
}

/*
    getFunction

    状態遷移先関数ポインタの取得

    副状態から該当する関数ポインタを検索。

    引数:
    SUB_STATE_TABLE*    subState           副状態テーブルの先頭アドレス
    USHT                id                 検索する副状態

    戻り値:
    USHT*               other than  NULL   状態遷移先関数ポインタ
                                    NULL   システムエラー       
                                       
    Created 2017/09/14
    By Shogo Tanaka
*/
SSHT ( *getFunction( SUB_STATE_TABLE* subState, USHT id ))( STATE_TABLE* )
{
    USHT index = 0;
    SSHT ( *function )( STATE_TABLE*, void* ) = NULL;

    /* --- 引数チェック --- */
    if( subState == NULL ){
	    return STATE_PARAM;
    }

    /* --- 検索ループ --- */
    for( index = 0; subState[index].Function != NULL; index++ ){
        if( subState[index].SubState == id ){
            /* 関数ポインタ取得 */
            function = subState[index].Function;
            break;
        }
    }

    return function;
    
}

/* Copyright HAL College of Technology & Design */