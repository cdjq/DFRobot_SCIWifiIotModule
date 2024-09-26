# DFRobot_SCIWifiModule
- [中文版](./README_CN.md)

TEL0180 is an SCI WiFi expansion module that can configure the network via I2C. After configuration, the sensors connected to the SCI module can report to the server.


![Product Image](./resources/images/TEL0180.png)


##  Product Link（https://www.dfrobot.com.cn/）

    SKU：TEL0180

## 目录

  * [Overview](#Overview)
  * [Installation](#Installation)
  * [Methods](#Methods)
  * [Compatibility](#Compatibility)
  * [History](#History)
  * [Authors](#Authors)

## Overview

* TEL0180 is an SCI WIFI expansion module.
* Network configuration can be done via I2C.
* SCI data can be obtained via I2C.

## Installation

Before using this library, please download the library file first, paste it into the \\Arduino\\libraries directory, then open the examples folder and run the demo within.

## Methods

```C++
  /**
     * @fn configWifi
     * @brief Configure WiFi
     * @param name WiFi name
     * @param pwd WiFi password
     * 
    */
    void configWifi(String name, String pwd);
    
    /**
     * @fn configMqtt1
     * @brief MQTT configuration 1
     * @param iot Configure IOT platform
     * @param qos Configure QoS
    */
    void configMqtt1(String iot,String qos);
    
    /**
     * @fn configMqtt2
     * @brief MQTT configuration 2
     * @param name MQTT username
     * @param pwd MQTT password
    */
    void configMqtt2(String name,String pwd);
    
    /**
     * @fn configTopic
     * @brief Subscribe to a topic
     * @param count Topic ID
     * @param top Topic name
    */
    void configTopic(String count,String top);
    
    /**
     * @fn cleanConfig
     * @brief Delete all configurations
    */
    void cleanConfig(void);

    /**
     * @fn endConfig
     * @brief Data transmission completed
    */

    void endConfig(void);
```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | :----:
Arduino Uno        |      √       |              |             |
Arduino MEGA2560   |      √       |              |             |
FireBeetle-ESP8266 |      √       |              |             |
FireBeetle-ESP32   |      √       |              |             |
Micro:bit          |      √       |              |             |


## History

- 2024/03/15 - Version 1.0.0

## Authors

Written by TangJie(jie.tang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))





