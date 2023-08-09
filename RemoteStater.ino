#include "RemoteStater68.h"

void setup() {
  pinMode(14,OUTPUT); //Pin yang dihubungkan ke Relay
  digitalWrite(14,1); // Relay = OFF
  SettingIP(10,10,10,10); //IP address = 10.10.10.10
  SettingWifi("SEPEDAKU","1234567890"); // SettingWifi(SSID,PASSWORD) 
}

void loop() {
  StaterBike(14,2000,"/stater"); //StaterBike(Pin,Delay,Perintah); 
}


