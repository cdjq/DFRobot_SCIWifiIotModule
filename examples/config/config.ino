#include "DFRobot_SCIWifiModule.h"

DFRobot_SCIWifiModule wifi;

void setup(){
    Serial.begin(115200);
    while(wifi.begin() != 1){
        Serial.println("sci wifi module connect error!!");
        delay(1000);
    }
    // wifi.cleanConfig();
    // delay(100);
    wifi.configWfif("dfrobotOffice","dfrobot2011");
    delay(100);
    wifi.configMqtt1("iot.dfrobot.com.cn","0");
    delay(100);
    wifi.configMqtt2("Wkb6YPk4g","ZzbeLEkVgz");
    delay(100);
    wifi.configTopic("0","eMBesYsVg");
    delay(100);
    wifi.configTopic("1","yekskm8Vg");
    delay(100);
    wifi.configTopic("2","MfXiOZJGg");
    delay(100);
    wifi.endConfig();
    Serial.println("config end");

}

void loop(){

}