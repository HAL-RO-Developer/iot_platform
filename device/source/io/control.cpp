/*
    control.cpp

    制御関数

    Created 2017/11/15
    By Hirotaka Nagaoka
    Refactored 2017/12/01
    By Hirotaka Nagaoka
*/

#include "pre.h" /* 制御関数に関するヘッダファイル */

/* --- 関数の登録 --- */
SSHT regist( FunctionManager** fm, FUNCTION_INFO info, String json )
{  
    SCHR regData[JSON_SIZE];  /* 登録領域 */

    /* 文字列を文字配列にコピー */
    json.toCharArray( regData, json.length( ) + 1 );

    /* --- JSONの作成 --- */
    StaticJsonBuffer<JSON_BUFFER_SIZE> jsonParseBuffer;
    JsonObject& root = jsonParseBuffer.parseObject( regData );

    /* --- パースチェック --- */
    if( !root.success( ) )
    {
        /* json parse error */
        return REGIST_NG;
    }

		/* --- 関数情報取得 --- */
    JsonArray& port = root["port"];
    SSHT f_args[PORT_SIZE][FUNC_ARGS_MAX];

    for( SINT i = 0; i < port.size() ; i++ )
    {
      info.PortId = port[i]["port"]; 	/* ポートID */
      info.FuncId = port[i]["function"];	/* 関数ID */
      
			/* 関数の引数 */
      JsonArray& j_args = port[i]["args"];
      for( SINT j = 0; j < j_args.size(); j++ )
      {
        f_args[i][j] = j_args[j];
      }

      info.Args = &f_args[i][0];
			/* --- 関数登録 --- */
      fm[i]->regist( info );
    }
    return REGIST_OK; /* 成功 */
}

/* --- 関数の実行 --- */
SSHT run( FunctionManager* fm )
{   
    return  fm->run( );
}

/* --- 関数結果の送信 --- */
SSHT send( FunctionManager** fm )
{
  SCHR sndData[JSON_SIZE]; /* 送信領域 */
  String json = "";

  /* --- 送信可否チェック --- */
  if (/* 送信するかどうか */ false)
  {
    /* 送信しない */
    return SEND_OK; /* 成功 */
    }
    delay( SEND_DELAY );

    /* --- メインマイコンに送信 --- */
    for( SINT i = 0; i < PORT_SIZE; i++ )
    {
        json = fm[i]->createJson( );
        Serial.print( '$' );
        delay( SEND_DELAY );

        for( SINT i = 0; i < json.length( ); i++ )
        {
           Serial.print( json[i] );
           delay( SEND_DELAY );
        }

        if( i < ( PORT_SIZE - 1 ) )
        {
          Serial.print( "," );
        }
        Serial.print( '\0' );
        delay( SEND_DELAY );
    }
    Serial.println( );

    return SEND_OK; /* 成功 */
}

/* Copyright HAL College of Technology & Design */
