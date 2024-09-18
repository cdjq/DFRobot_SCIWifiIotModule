# -*- coding:utf-8 -*-
'''!
  @file DFRobot_sci_wifi_module.py
  @brief This is a library for the SCI WiFi expansion module
  @copyright   Copyright (c) 2021 DFRobot Co. Ltd (http://www.dfrobot.com)
  @license     The MIT License (MIT)
  @author      TangJie (jie.tang@dfrobot.com)
  @version     V1.0
  @date        2024-03-15
  @url         https://github.com/DFRobot/DFRobot_SCIWifiModule
'''


import time
import smbus
import os
import math
import RPi.GPIO as GPIO
import math

CMD_WIFICONFIG      =0x00 #wifi configuration
CMD_IOTCONFIG       =0x01 #IoT platform configuration
CMD_MQTTCONFIG      =0x02 #mqtt configuration
CMD_TOPICCONFIG     =0x03 #Topic configuration
CMD_SENDEND         =0x04 #Transmission complete
CMD_RMOVEFILD       =0x05 #Clear all configurations

class DFRobot_SCIWifiModule():
    
  def __init__(self,bus):
    self._addr = 0x16
    self.i2cbus = smbus.SMBus(bus=1)

  def config_wifi(self,name,pwd):
    '''!
      @fn config_wifi
      @brief Configure WiFi
      @param name WiFi name
      @param pwd WiFi password
    '''
    sendData = name + ":" + pwd
    self._write_reg(CMD_WIFICONFIG,sendData)
    time.sleep(0.1)
  
  def config_mqtt1(self,iot,qos):
    '''!
      @fn config_mqtt1
      @brief MQTT Configuration 1
      @param iot Configure IoT platform
      @param qos QoS configuration
    '''
    sendData = iot + ":" + qos
    self._write_reg(CMD_IOTCONFIG,sendData)
    time.sleep(0.1)

  def config_mqtt2(self,name,pwd):
    '''!
      @fn config_mqtt2
      @brief MQTT Configuration 2
      @param name MQTT username
      @param pwd MQTT user password
    '''
    sendData = name + ":" + pwd
    self._write_reg(CMD_MQTTCONFIG,sendData)
    time.sleep(0.1)

  def confing_topic(self,count,top):
    '''!
      @fn config_topic
      @brief Subscribe to a topic
      @param count Topic index
      @param top Topic
    '''
    sendData = count + ":" + top
    self._write_reg(CMD_TOPICCONFIG,sendData)
    time.sleep(0.1)

  def end_config(self):
    '''!
      @fn end_config
      @brief Data transmission complete
    '''
    self.write_byte(CMD_SENDEND,0)
    time.sleep(0.1)

  def clean_config(self):
    '''!
      @fn clean_config
      @brief Delete all configurations
    '''
    self.write_byte(CMD_RMOVEFILD,0)
    time.sleep(0.1)
  

  def _write_reg(self, reg_addr ,string):
    '''!
      @brief write the data from the register
      @param reg_addr register address
      @param data Data written to register 
    '''
    try:
      data = [ord(c) for c in string]
      self.i2cbus.write_i2c_block_data(self._addr, reg_addr, data)
      return 1
    except:
      return 0
    
  def write_byte(self, register, value):
    try:
      self.i2cbus.write_byte_data(self._addr, register, value)
      return 1
    except:
      return 0
