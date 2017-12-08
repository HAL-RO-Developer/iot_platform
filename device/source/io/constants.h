/*
    constants.h

    デバイスピンアサイン

    Created 2017/07/12
    By Shogo Tanaka
    Refactored 2017/12/01
    By Hirotaka Nagaoka
*/

#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

/* PORT */
#define DPORT1  ( 1 )           /* デジタルポート         */
#define DPORT2  ( 2 )           /* デジタルポート         */
#define DPORT3  ( 3 )           /* デジタルポート         */
#define DPORT4  ( 4 )           /* デジタルポート         */
#define APORT1  ( 5 )           /* アナログポート         */
#define APORT2  ( 6 )           /* アナログポート         */
#define IPORT1  ( 7 )           /* I2Cポート             */
#define IPORT2  ( 8 )           /* I2Cポート             */

/* PIN */
#define DPIN1   ( 7    )        /* デジタルピン1         */
#define DPIN2   ( 6    )        /* デジタルピン2         */
#define DPIN3   ( 5    )        /* デジタルピン3         */
#define DPIN4   ( 4    )        /* デジタルピン4         */
#define APIN1   ( 15   )        /* アナログピン1         */
#define APIN2   ( 8    )        /* アナログピン2         */
#define APIN3   ( 9    )        /* アナログピン3         */
#define APIN4   ( 16   )        /* アナログピン4         */
#define SDA     ( 18   )        /* SDA(I2C)             */
#define SCL     ( 19   )        /* SCL(I2C)             */
#define NC      ( -1   )        /* Non-Connect          */

#endif /* __CONSTANTS_H__ */

/* Copyright HAL College of Technology & Design */
