/*!
 * @file  DFRobot_SCIWifiModule.cpp
 * @brief 这是SCI wifi 扩展模块的库的实现
 * @copyright	Copyright (c) 2021 DFRobot Co. Ltd (http://www.dfrobot.com)
 * @license   The MIT License (MIT)
 * @author    [TangJie](jie.tang@dfrobot.com)
 * @version   V1.0
 * @date      2024-03-15
 * @url       https://github.com/DFRobot/DFRobot_SCIWifiModule
 */
#include "DFRobot_SCIWifiModule.h"

 DFRobot_SCIWifiModule::DFRobot_SCIWifiModule(TwoWire *pWire){
    _pWire = pWire;
    _pWire->begin();
 }

 uint8_t DFRobot_SCIWifiModule::begin(void){
    
    _pWire->beginTransmission(_addr);
    if(_pWire->endTransmission() != 0)
        return 0;
    return 1;
 }


 void DFRobot_SCIWifiModule::configWfif(String name, String pwd){
    String sendData = name + ":" + pwd;
    writeReg(CMD_WIFICONFIG,(uint8_t*)sendData.c_str(),strlen(sendData.c_str()));
 }

void DFRobot_SCIWifiModule::configMqtt1(String iot,String qos){
    String sendData = iot + ":" + qos;
    writeReg(CMD_IOTCONFIG,(uint8_t*)sendData.c_str(),strlen(sendData.c_str()));
 }

void DFRobot_SCIWifiModule::configMqtt2(String name,String pwd){
    String sendData = name + ":" + pwd;
    writeReg(CMD_MQTTCONFIG,(uint8_t*)sendData.c_str(),strlen(sendData.c_str()));
  }

void DFRobot_SCIWifiModule::configTopic(String count,String top){
    String sendData = count + ":" + top;
    writeReg(CMD_TOPICCONFIG,(uint8_t*)sendData.c_str(),strlen(sendData.c_str()));
}

void DFRobot_SCIWifiModule::cleanConfig(void){
    _pWire->beginTransmission(_addr);
    _pWire->write(CMD_RMOVEFILD);
    _pWire->endTransmission();

}

void DFRobot_SCIWifiModule::endConfig(void){
    _pWire->beginTransmission(_addr);
    _pWire->write(CMD_SENDEND);
    _pWire->endTransmission();
  }

uint8_t DFRobot_SCIWifiModule::writeReg(uint8_t reg, void *pBuf, size_t size)
{
  uint8_t *_pBuf = (uint8_t*)pBuf;
    _pWire->beginTransmission(_addr);
    _pWire->write(reg);
    for(size_t i = 0; i < size; i++){
      _pWire->write(_pBuf[i]);
    }
    _pWire->endTransmission();
  delay(50);
  return 0;
}