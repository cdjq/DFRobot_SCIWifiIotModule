# -*- coding:utf-8 -*-
'''!
  @file DFRobot_sci_wifi_module.py
  @brief 这是一个sci wifi 扩展模块的库
  @copyright   Copyright (c) 2021 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license     The MIT License (MIT)
  @author      TangJie(jie.tang@dfrobot.com)
  @version     V1.0
  @date        2024-03-15
  @url https://github.com/DFRobot/DFRobot_SCIWifiModule
'''


import time
import smbus
import os
import math
import RPi.GPIO as GPIO
import math

CMD_WIFICONFIG      =0x00 #wifi配置
CMD_IOTCONFIG       =0x01 #iot平台配置
CMD_MQTTCONFIG      =0x02 #mqtt配置
CMD_TOPICCONFIG     =0x03 #主题配置
CMD_SENDEND         =0x04 #传输完成
CMD_RMOVEFILD       =0x05  #清楚全部配置

class DFRobot_SCIWifiModule():
    
  def __init__(self,bus):
    self._addr = 0x16
    self.i2cbus = smbus.SMBus(bus=1)

  def config_wifi(self,name,pwd):
    '''!
      @fn config_wifi
      @brief 配置WiFi
      @param name wifi 名称
      @param pwd wifi 密码
    '''
    sendData = name + ":" + pwd
    self._write_reg(CMD_WIFICONFIG,sendData)
    time.sleep(0.1)
  
  def config_mqtt1(self,iot,qos):
    '''!
      @fn config_mqtt1
      @brief MQTT配置1
      @param iot 配置IOT平台
      @param qos qos 配置
    '''
    sendData = iot + ":" + qos
    self._write_reg(CMD_IOTCONFIG,sendData)
    time.sleep(0.1)

  def config_mqtt2(self,name,pwd):
    '''!
      @fn config_mqtt2
      @brief MQTT配置2
      @param name MQTT用户名称
      @param pwd MQTT用户密码
    '''
    sendData = name + ":" + pwd
    self._write_reg(CMD_MQTTCONFIG,sendData)
    time.sleep(0.1)

  def confing_topic(self,count,top):
    '''!
      @fn confing_topic
      @brief 订阅主题
      @param count 主题标号
      @param top 主题
    '''
    sendData = count + ":" + top
    self._write_reg(CMD_TOPICCONFIG,sendData)
    time.sleep(0.1)

  def end_config(self):
    '''!
      @fn end_config
      @brief 数据传输完成
    '''
    self.write_byte(CMD_SENDEND,0)
    time.sleep(0.1)

  def clean_config(self):
    '''!
      @fn clean_config
      @brief 删除全部配置
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
