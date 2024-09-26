'''!
  @file  config.py
  @brief This is a demo for configuring the SCI WiFi module; running the demo will configure the SCI WiFi module.
  @copyright   Copyright (c) 2024 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license     The MIT License (MIT)
  @author      TangJie(jie.tang@dfrobot.com)
  @version     V1.0
  @date        2024-09-18
  @url         https://github.com/DFRobot/DFRobot_SCIWifiModule
'''
from __future__ import print_function
import sys
import os
sys.path.append("../")
import time
import RPi.GPIO as GPIO

from DFRobot_sci_wifi_module import *

wifi = DFRobot_SCIWifiModule(1)

def setup():
  time.sleep(0.1)
  wifi.clean_config()
  time.sleep(0.1)
  wifi.config_wifi("aaa","dddd")
  time.sleep(0.1)
  wifi.config_mqtt1("iot.dfrobot.com","0")
  time.sleep(0.1)
  wifi.config_mqtt2("Wkb6YPk4g","ZzbeLEkVgz")
  time.sleep(0.1)
  wifi.confing_topic("0","yekskm8Vg")
  time.sleep(0.1)
  wifi.confing_topic("1","MfXiOZJGg")
  time.sleep(0.1)
  wifi.confing_topic("2","eMBesYsVg")
  time.sleep(0.1)
  wifi.end_config()


def loop():
  time.sleep(0.5)

if __name__ == "__main__":
  setup()
  while True:
    loop()