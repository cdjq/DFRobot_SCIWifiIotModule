/*!
 * @file config.ino
 * @brief This is a demo for configuring the SCI WiFi module; running the demo will configure the SCI WiFi module.
 * @copyright   Copyright (c) 2024 DFRobot Co. Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [TangJie](jie.tang@dfrobot.com)
 * @version     V1.0
 * @date        2024-09-14
 * @url         https://github.com/DFRobot/DFRobot_SCIWifiModule
 */
#include "DFRobot_SCIWifiModule.h"

DFRobot_SCIWifiModule wifi;

void setup(){
    Serial.begin(115200);
    while(wifi.begin() != 1){
        Serial.println("sci wifi module connect error!!");
        delay(1000);
    }
    wifi.cleanConfig();
    delay(100);
    wifi.configWifi("dfrobotOffice","dfrobot2011");
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