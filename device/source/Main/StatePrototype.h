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
#include "State.h"          /* 状態に関する定義ヘッダ       */

/* --- プロトタイプ宣言 --- */
/* 状態遷移関数コール */
SSHT callFunction( STATE_TABLE* state, INFO_COMMON* common );

/* --- 副状態プロトタイプ宣言 --- */
/* セットアップ状態時 */
SSHT setupStateAp( STATE_TABLE* state, INFO_COMMON* common );
SSHT setupStateAction( STATE_TABLE* state, INFO_COMMON* common );

/* 動作状態時 */
SSHT actionStateRegist( STATE_TABLE* state, INFO_COMMON* common );
SSHT actionStateExecute( STATE_TABLE* state, INFO_COMMON* common );
SSHT actionStateSend( STATE_TABLE* state, INFO_COMMON* common );

/* エラー状態時 */
SSHT errorStateConnect( STATE_TABLE* state, INFO_COMMON* common );
SSHT errorStateCommunicate( STATE_TABLE* state, INFO_COMMON* common );
SSHT errorStateOther( STATE_TABLE* state, INFO_COMMON* common );

#endif  /* __STATE_PROTOTYPE_H__ */
