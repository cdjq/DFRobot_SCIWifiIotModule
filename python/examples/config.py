
from __future__ import print_function
import sys
import os
sys.path.append("../")
import time
import RPi.GPIO as GPIO

from DFRobot_sci_wifi_module import *

wifi = DFRobot_SCIWifiModule(1)

def setup():
  wifi.config_wifi("aaa","dddd");
  time.sleep(0.1)
  wifi.config_mqtt1("iot.dfrobot.com","0");
  time.sleep(0.1)
  wifi.config_mqtt2("Wkb6YPk4g","ZzbeLEkVgz");
  time.sleep(0.1)
  wifi.confing_topic("0","yekskm8Vg");
  time.sleep(0.1)
  wifi.confing_topic("1","MfXiOZJGg");
  time.sleep(0.1)
  wifi.confing_topic("2","eMBesYsVg");
  time.sleep(0.1)
  wifi.end_config();


def loop():
  time.sleep(0.5)

if __name__ == "__main__":
  setup()
  while True:
    loop()