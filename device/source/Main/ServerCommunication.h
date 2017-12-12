#ifndef __SERVER_COMMUNICATION_H_
#define __SERVER_COMMUNICATION_H_

/* --- includeファイル --- */
#include "ArduinoLibrary.h"	
#include "System.h"
#include "InfoStruct.h"

#define SERVER_SUCCESS ( 1 )
#define SERVER_CONNECT_ERROR ( -1 )

/* --- HTTPステータスコード --- */
#define HTTP_STATUS_OK ( 200 )
#define HTTP_STATUS_FORBIDDEN ( 403 )
#define HTTP_STATUS_NOT_FOUND ( 404 )

class ServerCommunication{
	private:
		WiFiClient client;
		String host;
    String port;
		String url;
		SINT status;
	public:
		ServerCommunication(String host="");
		~ServerCommunication();
		SSHT connect(String host, String port);
		void request(String url, String json);
		SINT response(String json[]);
		void setUrl(String url);
		SINT getStatus();
};

#endif /* __SERVER_COMMUNICATION_H_ */
