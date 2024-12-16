#include "DistanceSensor.h"

DistanceSensor::DistanceSensor(int RX, int TX, HardwareSerial &serial) : sensorSerial(serial)
{
    sensorSerial.begin(115200, SERIAL_8N1, RX, TX);
}

Point DistanceSensor::receiveData()
{
    Point point;
    if (sensorSerial.available() >= 9)
    {
        uint8_t buffer[9];
        for (int i = 0; i < 9; i++)
        {
            buffer[i] = sensorSerial.read();
        }

        if (buffer[0] == 0x59 && buffer[1] == 0x59)
        {
            double distance = buffer[2] + (buffer[3] << 8);
            double strength = buffer[4] + (buffer[5] << 8);
            uint8_t checksum = 0;

            for (int i = 0; i < 8; i++)
            {
                checksum += buffer[i];
            }

            if (checksum == buffer[8])
            {
                point.setDistance(distance);
                point.setStrength(strength);
                return point;
            }
            else
            {
                return point;
            }
        }
    }
    return point;
}

void DistanceSensor::collectData(Motor motor)
{
    if (motor.getAngle() != 0)
    {
        Point point = receiveData();
        point.setAngle(motor.getAngle());

        // Start bit + jakość
        uint8_t quality = static_cast<uint8_t>(std::round(std::min(point.getStrength(), 63.0))); // Skala 0–63
        uint8_t start_bit_quality = (0b11 << 6) | quality;

        // Kąt w jednostkach 1/64°
        uint16_t angle_q6 = static_cast<uint16_t>(std::round(point.getAngle() * 0.87 * 64)) % (360 * 64);

        // Odległość w jednostkach 1/4 mm
        uint16_t distance_q2 = static_cast<uint16_t>(std::round(point.getDistance() * 4));

        String toAdd = " " + String(start_bit_quality) + " " + String(angle_q6) + " " + String(distance_q2);
        data += toAdd;
    } 
    else
    {
        data = "0xA5 0x81";
    }
}

String DistanceSensor::getData(){
    return data;
}