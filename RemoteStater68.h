#include <ESP8266WiFi.h>
WiFiServer Server(80);

void SettingIP(int IP1, int IP2, int IP3, int IP4)
{
    IPAddress ip(IP1,IP2,IP3,IP4);
    IPAddress gateway(IP1,IP2,IP3,IP4);
    IPAddress subnet(255,255,255,0); 
    WiFi.softAPConfig(ip, gateway, subnet);
}  

void SettingWifi(String mySSID, String myPass){
    WiFi.softAP(mySSID,myPass);
    Server.begin(); 
}



void StaterBike(int PinStater, int tunggu, String perintah) {
 WiFiClient client = Server.available();
 if (!client)  {  return;  }
 String request = client.readStringUntil('\r');
   if (request.indexOf(perintah) != -1) {
    digitalWrite(PinStater,0);
    delay(tunggu); 
    digitalWrite(PinStater,1);
  }
 client.flush();
 client.print("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
 delay(5);
}

