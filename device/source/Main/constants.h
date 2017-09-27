/* 
created 2017/07/12
by Tanaka
*/

/* PORT */
#define DPORT   ( 0x01 )        /* デジタルポート         */
#define APORT   ( 0x02 )        /* アナログポート         */
#define IPORT   ( 0x04 )        /* I2Cポート             */

/* PIN */
#define DPIN0   ( 0    )        /* デジタルピン0         */
#define DPIN1   ( 2    )        /* デジタルピン1         */
#define APIN0   ( 16   )        /* アナログピン0         */
#define APIN1   ( A0   )        /* アナログピン1         */
#define SDA     ( 4    )        /* SDA(I2C)             */
#define SCL     ( 5    )        /* SCL(I2C)             */
#define TX      ( 0    )        /* TX(Serial)           */
#define RX      ( 2    )        /* RX(Serial)           */

/* MODE */
#define MODE_AP     ( 0 )       /* APモード             */
#define MODE_DEVICE ( 1 )       /* デバイスモード        */

/* OTHER */
#define APSWT   ( 14   )        /* APモードスイッチ      */
#define SLPR    ( 13   )        /* ステータスランプ (赤) */
#define SLPG    ( 15   )        /* ステータスランプ (緑) */
