#include "ServerCommunication.h"

ServerCommunication::ServerCommunication(String host):
	host(host)
{

}

ServerCommunication::~ServerCommunication()
{}

SSHT ServerCommunication::connect(String host, String port )
{
	this->host = host;
  this->port = port;
	if( !client.connect(host.c_str(), port.toInt()) ){
		return SERVER_CONNECT_ERROR;
	}
	
	return SERVER_SUCCESS;
}

void ServerCommunication::request(String url, String json)
{
    if( !client.connected() ){
      connect( host, port );
    }
  
	  this->url = url;
	  String body = json;
  	/* HTTP REQUEST */
  	client.println("POST "+ url +" HTTP/1.1");
    /* HTTP HEADER */
    client.println("Host:" + host);
    client.println("Accept: application/json");
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(body.length());
    client.println();
    /* HTTP BODY */
    client.print(body);
 
    delay(10);
}

SINT ServerCommunication::response(String* json)
{
	String response = client.readString();
	int statusPos = response.indexOf("HTTP/1.1 ") + 9;
	String statusString = response.substring(statusPos, statusPos + 3);
	status = statusString.toInt();

  /* body位置検索 */
	int bodyPos =  response.indexOf("\r\n\r\n") + 4;
	*json = response.substring(bodyPos);

  if(client.connected()){
    client.stop();
  }
	
	return status;

}

void ServerCommunication::setUrl(String url)
{
	this->url = url;
}

SINT ServerCommunication::getStatus()
{
	return status;
}
