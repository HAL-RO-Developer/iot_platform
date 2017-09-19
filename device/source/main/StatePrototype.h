/*
    StatePrototype.h

    状態に関する関数（状態遷移マトリクス）のプロトタイプ宣言

    Created 2017/09/11
    By Shogo Tanaka
*/

#ifndef __STATE_PROTOTYPE_H__
#define __STATE_PROTOTYPE_H__

/* --- includeファイル --- */
#include "System.h"         /* システム共通データ定義ヘッダ */

/* --- プロトタイプ宣言 --- */
/* 状態遷移関数コール */
SSHT callFunction( STATE_TABLE* state, void* object );

/* --- 副状態プロトタイプ宣言 --- */
/* セットアップ状態時 */
SSHT setupStateAp( STATE_TABLE* state, void* object );
SSHT setupStateAction( STATE_TABLE* state, void* object );

/* 動作状態時 */
SSHT actionStateRegist( STATE_TABLE* state, void* object );
SSHT actionStateExeceute( STATE_TABLE* state, void* object );
SSHT actionStateSend( STATE_TABLE* state, void* object );

/* エラー状態時 */
SSHT errorStateConnect( STATE_TABLE* state, void* object );
SSHT errorStateCommunicate( STATE_TABLE* state, void* object );
SSHT errorStateOther( STATE_TABLE* state, void* object );


#endif  /* __STATE_PROTOTYPE_H__ */ 