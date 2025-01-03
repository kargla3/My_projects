#include "DistanceSensor.h"

DistanceSensor::DistanceSensor(int RX, int TX, HardwareSerial &serial) : sensorSerial(serial)
{
    sensorSerial.begin(115200, SERIAL_8N1, RX, TX);
    // byte setBaudRate[] = {0x5A, 0x08, 0x06, 0x00, 0x08, 0x07, 0x00, 0x00};
    // sensorSerial.write(setBaudRate, sizeof(setBaudRate));
    // delay(100);
    // sensorSerial.updateBaudRate(460800);
    // delay(100);
    byte setFrameRate[] = {0x5A, 0x06, 0x03, 0xFA, 0x00, 0x00};
    sensorSerial.write(setFrameRate, sizeof(setFrameRate));
}

Point DistanceSensor::receiveData()
{
    Point point;
    //while(!sensorSerial.available());
    if (sensorSerial.available() >= 9)
    {
        uint8_t buffer[9];
        for (int i = 0; i < 9; i++)
        {
            do{
                buffer[i] = sensorSerial.read();
            } while(buffer[0] != 0x59);
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

void DistanceSensor::collectData(Motor motor, int numRecords)
{
    if (motor.getAngle() != 0)
    {
        float motorAngle = motor.getAngle();
        float stepPerRecord = 413.7 / numRecords;
        float tolerance = 0.9;
        if (fmod(motorAngle, stepPerRecord) < tolerance) {
            Point point = this->receiveData();
            point.setAngle(motor.getAngle());

            // Start bit + jakość
            uint8_t quality = static_cast<uint8_t>(std::round(std::min(point.getStrength(), 63.0))); // Skala 0–63
            uint8_t start_bit_quality = (0b11 << 6) | quality;

            // Kąt w jednostkach 1/64°
            uint16_t angle_q6 = static_cast<uint16_t>(std::round(point.getAngle() * 0.87019579 * 64)) % (360 * 64);

            // Odległość w jednostkach 1/4 mm
            uint16_t distance_q2 = static_cast<uint16_t>(std::round(point.getDistance() * 4));

            //String toAdd = " " + String(start_bit_quality) + " " + String(angle_q6) + " " + String(distance_q2);
            String toAdd = " " + String(point.getDistance());
            data += toAdd;
        }
    } 
    else
    {
        data = "";
        //data = "0xA5 0x81";
    }
}

String DistanceSensor::getData(){
    return data;
}