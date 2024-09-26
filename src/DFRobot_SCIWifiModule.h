/*!
 * @file  DFRobot_SCIWifiModule.h
 * @brief This is the library declaration for the SCI WiFi expansion module
 * @copyright	Copyright (c) 2024 DFRobot Co. Ltd (http://www.dfrobot.com)
 * @license   The MIT License (MIT)
 * @author    [TangJie](jie.tang@dfrobot.com)
 * @version   V1.0
 * @date      2024-03-15
 * @url       https://github.com/DFRobot/DFRobot_SCIWifiModule
 */
#ifndef _DFROBOT_SCIWIFIMODULE_H_
#define _DFROBOT_SCIWIFIMODULE_H_
#include "Arduino.h"
#include "Wire.h"


#define CMD_WIFICONFIG      0x00///<wifi configuration
#define CMD_IOTCONFIG       0x01///<IoT platform configuration
#define CMD_MQTTCONFIG      0x02///<mqtt configuration
#define CMD_TOPICCONFIG     0x03///<Topic configuration
#define CMD_SENDEND         0x04///<Transmission complete
#define CMD_RMOVEFILD       0x05 ///<Clear all configurations

class DFRobot_SCIWifiModule{

public:
    /**
     * @fn DFRobot_SCIWifiModule
     * @brief Constructor for the SCI WiFi module
     * @param pWire Pointer to the I2C `TwoWire` stream, which requires calling `begin` in the setup to initialize Arduino I2C configuration.
    */
    DFRobot_SCIWifiModule(TwoWire *pWire = &Wire);
    ~DFRobot_SCIWifiModule(){};
    /**
     * @fn begin
     * @brief Initialize the SCI WiFi module
     * @return Initialization status
     * @retval 0 Initialization failed
     * @retval 1 Initialization succeeded
    */
    uint8_t begin(void);
    /**
     * @fn configWifi
     * @brief Configure WiFi
     * @param name WiFi name
     * @param pwd WiFi password
    */
    void configWifi(String name, String pwd);
    /**
     * @fn configMqtt1
     * @brief MQTT configuration 1
     * @param iot Configure IoT platform
     * @param qos QoS configuration
    */
    void configMqtt1(String iot,String qos);
    /**
     * @fn configMqtt2
     * @brief MQTT configuration 2
     * @param name MQTT username
     * @param pwd MQTT user password
    */
    void configMqtt2(String name,String pwd);
    /**
     * @fn configTopic
     * @brief Subscribe to a topic
     * @param count Topic index
     * @param top Topic
    */
    void configTopic(String count,String top);
    /**
     * @fn delayConfig
     * @brief Delete all configurations
    */
    void cleanConfig(void);

    /**
     * @fn endConfig
     * @brief Data transmission complete
    */

    void endConfig(void);

private:
TwoWire *_pWire;
uint8_t writeReg(uint8_t reg, void *pBuf, size_t size);
uint8_t _addr = 0x16;

};











#endif
