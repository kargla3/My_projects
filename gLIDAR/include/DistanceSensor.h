#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H

#include <Arduino.h>
#include <HardwareSerial.h>
#include "Point.h"
#include "Motor.h"

class DistanceSensor {
    HardwareSerial& sensorSerial;
    //String data = "0xA5 0x81";
    String data = "";
public:
    DistanceSensor(int RX, int TX, HardwareSerial& serial);
    Point receiveData();
    void collectData(Motor motor, int numRecords);
    String getData();
};

#endif