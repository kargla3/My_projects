#include "Motor.h"

Motor::Motor(int step_PIN, int dir_PIN, int en_PIN) {
    this->step_PIN = step_PIN;
    this->dir_PIN = dir_PIN;
    this->en_PIN = en_PIN;
    pinMode(step_PIN, OUTPUT);
    pinMode(dir_PIN, OUTPUT);
    pinMode(en_PIN, OUTPUT);
}

double Motor::getAngle() {
    return angle;
}

void Motor::disable() {
    digitalWrite(en_PIN, HIGH);
}

void Motor::setDirection(bool dir) {
    if(dir)
        digitalWrite(dir_PIN, HIGH);
    else
        digitalWrite(dir_PIN, LOW);
}

void Motor::setVelocity(int velocity) {
    this->velocity = velocity;
}

void Motor::rotate() {
    digitalWrite(step_PIN, HIGH);
    delayMicroseconds(velocity);
    digitalWrite(step_PIN, LOW);
    delayMicroseconds(velocity);

    if(angle < angle_per_revolution) {
        angle += angle_per_step;
    } else {
        angle = 0;
    }
    
    if(angle == 0) full_revolution = true;
    else full_revolution = false;
}

bool Motor::checkRevolution() {
    return full_revolution;
}
