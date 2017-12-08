/*
    io.ino

    メイン関数(Nano用)

    Created 2017/11/15
    By Hirotaka Nagaoka
*/

#include "pre.h" /* 制御関数に関するヘッダファイル */
// #define DEBUG ( 1 )

/* --- 関数管理クラス --- */
FunctionManager  dport1( DPORT1 );
FunctionManager  dport2( DPORT2 );
FunctionManager  dport3( DPORT3 );
FunctionManager  dport4( DPORT4 );
FunctionManager  aport1( APORT1 );
FunctionManager  aport2( APORT2 );
FunctionManager  iport1( IPORT1 );
FunctionManager  iport2( IPORT2 );
FunctionManager* fm[PORT_SIZE] = { &dport1, &dport2, &dport3, &dport4, &aport1, &aport2, &iport1, &iport2 };
FUNCTION_INFO    info;

/* --- シリアル通信関連 --- */
SCHR rcvData[JSON_SIZE];    /* 受信領域 */

void setup( )
{
    /* --- シリアル通信設定 --- */
    Serial.begin( BAUDRATE );

    #if DEBUG
    SSHT test_args[1] = { 1000 };
    info.PortId = DPORT1;
    info.FuncId = FUNCTION_BLINK_DWRITE;
    info.Args = test_args;

    fm[0]->regist( info );
    #endif
} /* setup */

void loop( )
{
    String json;

    /* --- シリアル受信 --- */
    while( Serial.available() > 0 )
    {
        SCHR c;

        /* シリアル読込 */
        c = Serial.read( );

        if( c == '#' )
        {
            send( fm );
        }
        if( c == '\n' )
        {
            regist( fm, info, json );
            json = "";
        }
            json += c;
    }
    /* --- 関数実行 --- */
    for( int i = 0; i < PORT_SIZE; i++ )
    {
        /* 実行 */
        run( fm[i] );
    }
} /* loop */

/* Copyright HAL College of Technology & Design */
