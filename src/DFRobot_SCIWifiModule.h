/*!
 * @file  DFRobot_SCIWifiModule.h
 * @brief 这是SCI wifi 扩展模块的库的声明
 * @copyright	Copyright (c) 2021 DFRobot Co. Ltd (http://www.dfrobot.com)
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


#define CMD_WIFICONFIG      0x00///<wifi配置
#define CMD_IOTCONFIG       0x01///<iot平台配置
#define CMD_MQTTCONFIG      0x02///<mqtt配置
#define CMD_TOPICCONFIG     0x03///<主题配置
#define CMD_SENDEND         0x04///<传输完成
#define CMD_RMOVEFILD       0x05 ///<清楚全部配置

class DFRobot_SCIWifiModule{

public:
    /**
     * @fn DFRobot_SCIWifiModule
     * @brief sci wifi 模块构造函数
     * @param pWire I2C pointer to the TowWire stream, which requires calling begin in the demo to init Arduino I2C config.
    */
    DFRobot_SCIWifiModule(TwoWire *pWire = &Wire);
    ~DFRobot_SCIWifiModule(){};
    // /**
    //  * @fn befin
    //  * @brief 初始化 sci wifi 模块
    //  * @return 返回初始化状态
    //  * @retval 0 初始化失败
    //  * @retval 1 初始化成功
    // */
    // uint8_t begin(void);
    /**
     * @fn configWfif
     * @brief 配置WiFi
     * @param name wifi 名称
     * @param pwd wifi 密码
     * 
    */
    void configWfif(String name, String pwd);
    /**
     * @fn configMqtt1
     * @brief MQTT配置1
     * @param iot 配置IOT平台
     * @param qos qos 配置
    */
    void configMqtt1(String iot,String qos);
    /**
     * @fn configMqtt2
     * @brief MQTT配置2
     * @param name MQTT用户名称
     * @param pwd MQTT用户密码
    */
    void configMqtt2(String name,String pwd);
    /**
     * @fn configTopic
     * @brief 订阅主题
     * @param count 主题标号
     * @param top 主题
    */
    void configTopic(String count,String top);
    /**
     * @fn delayConfig
     * @brief 删除全部配置
    */
    void cleanConfig(void);

    /**
     * @fn endConfig
     * @brief 数据传输完成
    */

    void endConfig(void);

private:
TwoWire *_pWire;
uint8_t writeReg(uint8_t reg, void *pBuf, size_t size);
uint8_t _addr = 0x16;

};











#endif
