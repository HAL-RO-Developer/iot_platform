/*
    FunctionDefine.h

    状態に関する定数およびIDの定義

    Created 2017/10/03
    By Shogo Tanaka
    Refactored 2017/12/01
    By Hirotaka Nagaoka
*/

#ifndef __FUNCTION_DEFINE_H__
#define __FUNCTION_DEFINE_H__

/*
    関数ID　2進数8桁（16進2桁)で構成
    +----+-----+-----+---------+
    |bit | 7 6 | 5 4 | 3 2 1 0 |
    +----+-----+-----+---------+
    |data| 0 0 | 0 0 | 0 0 0 0 |
    +----+-----+-----+---------+

    7~6bit  ポート
        00: IPORT
        01: DPORT
        10: APORT
        11: UART
    5~4bit  I/O
        00: Setup/Request　etc...
        01: OUTPUT
        10: INPUT
        11: INPUT-OUTPUT
    3~0bit  関数連番(0001~1111)

*/

#define FUNCTION_NOTHING                ( 0x00 )    /* 0000 0000 (  0) */
#define FUNCTION_ONCE_DWRITE            ( 0x51 )    /* 0101 0001 ( 81) */
#define FUNCTION_SIMPLE_DWRITE          ( 0x52 )    /* 0101 0010 ( 82) */
#define FUNCTION_BLINK_DWRITE           ( 0x53 )    /* 0101 0011 ( 83) */
#define FUNCTION_ONCE_DREAD             ( 0x61 )    /* 0110 0001 ( 97) */
#define FUNCTION_SIMPLE_DREAD           ( 0x62 )    /* 0110 0010 ( 98) */
#define FUNCTION_ONCE_AWRITE            ( 0x91 )    /* 1001 0001 (145) */
#define FUNCTION_SIMPLE_AWRITE          ( 0x92 )    /* 1001 0010 (146) */
#define FUNCTION_BLINK_AWRITE           ( 0x93 )    /* 1001 0011 (147) */
#define FUNCTION_ONCE_AREAD             ( 0xA1 )    /* 1010 0001 (161) */
#define FUNCTION_SIMPLE_AREAD           ( 0xA2 )    /* 1010 0010 (162) */
#define FUNCTION_I2C_SETUP              ( 0x01 )    /* 0000 0001 (  1) */
#define FUNCTION_I2C_WRITE              ( 0x11 )    /* 0001 0001 ( 17) */
#define FUNCTION_I2C_READ               ( 0x21 )    /* 0010 0001 ( 33) */
#define FUNCTION_I2C_REQUEST_ONE_BYTE   ( 0x02 )    /* 0000 0010 (  2) */
#define FUNCTION_UART_SETUP             ( 0xC1 )    /* 1100 0001 (193) */
#define FUNCTION_UART_WRITE             ( 0xD1 )    /* 1101 0001 (209) */
#define FUNCTION_UART_READ              ( 0xE1 )    /* 1110 0001 (225) */

#define JSON_SIZE                       (  256 )    /* JSONサイズ */

#define RAISE                           (    1 )
#define FALLDAOWN                       (   -1 )
#define BOTH                            (    0 )

#define RESULT_OK                       (    1 )    /* 成功 */
#define RESULT_NG                       (   -1 )    /* 失敗 */

#endif /* __FUNCTION_DEFINE_H__ */
