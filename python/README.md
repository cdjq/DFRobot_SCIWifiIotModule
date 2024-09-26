# DFRobot_SCIWifiModule
- [中文版](./README_CN.md)

TEL0180 is an SCI WiFi expansion module that can configure the network via I2C. After configuration, the sensors connected to the SCI module can report to the server.


![Product Image](./resources/images/TEL0180.png)


## Product Link (https://www.dfrobot.com.cn/)

    SKU: TEL0180

## Table of Contents

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

```python
  def config_wifi(self, name, pwd):
    '''!
      @fn config_wifi
      @brief Configure WiFi
      @param name WiFi name
      @param pwd WiFi password
    '''
  
  def config_mqtt1(self, iot, qos):
    '''!
      @fn config_mqtt1
      @brief MQTT configuration 1
      @param iot Configure IOT platform
      @param qos Configure QoS
    '''

  def config_mqtt2(self, name, pwd):
    '''!
      @fn config_mqtt2
      @brief MQTT configuration 2
      @param name MQTT username
      @param pwd MQTT password
    '''

  def config_topic(self, count, top):
    '''!
      @fn config_topic
      @brief Subscribe to a topic
      @param count Topic ID
      @param top Topic name
    '''

  def end_config(self):
    '''!
      @fn end_config
      @brief Data transmission completed
    '''

  def clean_config(self):
    '''!
      @fn clean_config
      @brief Delete all configurations
    '''
   
```

## Compatibility

* RaspberryPi  Version

| Board        | Work Well | Work Wrong | Untested | Remarks |
| ------------ | :-------: | :--------: | :------: | ------- |
| RaspberryPi4 |     √     |            |          |         |

* Python  Version

| Python  | Work Well | Work Wrong | Untested | Remarks |
| ------- | :-------: | :--------: | :------: | ------- |
| Python3 |     √     |            |          |         |


## History

- 2024/03/15 - Version 1.0.0

## 创作者

Written by TangJie(jie.tang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))





