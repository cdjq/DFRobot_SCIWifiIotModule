# DFRobot_SCIWifiModule
- [English Version](./README_CN.md)

TEL0180 是SCI的WiFi扩展模块，能够通过I2C进行网络配置，配置完成后可以将SCI模块上连接传感器上报到服务器


![产品效果图片](./resources/images/TEL0180.png)


## 产品链接（https://www.dfrobot.com.cn/）

    SKU：TEL0180

## 目录

  * [概述](#概述)
  * [库安装](#库安装)
  * [方法](#方法)
  * [兼容性](#兼容性)
  * [历史](#历史)
  * [创作者](#创作者)

## 概述

* TEL0180 是一个SCI WIFI扩展模块
* 可以通过I2C配置网络
* 可以通过I2C获取SCI数据

## 库安装

使用此库前，请首先下载库文件，将其粘贴到\Arduino\libraries目录中，然后打开examples文件夹并在该文件夹中运行演示。

## 方法

```python
  def config_wifi(self,name,pwd):
    '''!
      @fn config_wifi
      @brief 配置WiFi
      @param name wifi 名称
      @param pwd wifi 密码
    '''
  
  def config_mqtt1(self,iot,qos):
    '''!
      @fn config_mqtt1
      @brief MQTT配置1
      @param iot 配置IOT平台
      @param qos qos 配置
    '''

  def config_mqtt2(self,name,pwd):
    '''!
      @fn config_mqtt2
      @brief MQTT配置2
      @param name MQTT用户名称
      @param pwd MQTT用户密码
    '''

  def confing_topic(self,count,top):
    '''!
      @fn confing_topic
      @brief 订阅主题
      @param count 主题标号
      @param top 主题
    '''

  def end_config(self):
    '''!
      @fn end_config
      @brief 数据传输完成
    '''

  def clean_config(self):
    '''!
      @fn clean_config
      @brief 删除全部配置
    '''
   
```

## 兼容性

* RaspberryPi 版本

| Board        | Work Well | Work Wrong | Untested | Remarks |
| ------------ | :-------: | :--------: | :------: | ------- |
| RaspberryPi2 |           |            |    √     |         |
| RaspberryPi3 |           |            |    √     |         |
| RaspberryPi4 |     √     |            |          |         |

* Python 版本

| Python  | Work Well | Work Wrong | Untested | Remarks |
| ------- | :-------: | :--------: | :------: | ------- |
| Python2 |     √     |            |          |         |
| Python3 |     √     |            |          |         |


## 历史

- 2024/03/15 - 1.0.0 版本

## 创作者

Written by TangJie(jie.tang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))





