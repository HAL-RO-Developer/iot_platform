// includeファイル
#include <DeviceControl.h>

String digiWrite( int pin, int mode, int val ) {
  String resultStr = "OK";
  String pinStr = String(pin);
  String modeStr = String(mode);
  String valueStr = String(val);
  String rtn = "{\"result\":\"" +
                 resultStr +
                "\",\"pin\":\"" +
                pinStr +
                "\",\"mode\":\"" +
                modeStr +
                "\",\"value\":\"" +
                valueStr + 
                "\"}";
  if((mode != OUTPUT) || (flag == 0) ){
    Digital::SetMode( pin, OUTPUT );
  }
  Digital::Write( pin, val );
  return rtn;
}
