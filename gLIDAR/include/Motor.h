#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

//TFLUNA disc diameter = 52 mm
//Motor disc diameter = 45.25 mm


class Motor {
    int velocity = 500;
    double angle = 0;
    const double angle_per_revolution = 413.7;
    const double angle_per_step = 0.9;
    int step_PIN;
    int dir_PIN;
    int en_PIN;
    bool full_revolution = false;
public:
    Motor(int step_PIN, int dir_PIN, int en_PIN);
    double getAngle();
    void setDirection(bool dir);
    void setVelocity(int velocity);
    void rotate();
    bool checkRevolution();
};

#endif
