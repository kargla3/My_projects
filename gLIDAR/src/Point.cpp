#include "Point.h"

Point::Point() {}

void Point::setAngle(double angle) {
    this->angle = angle;
}

void Point::setDistance(double distance) {
    this->distance = distance;
}

void Point::setStrength(double strength) {
    this->strength = strength;
}

int Point::getDistance() {
    return distance;
}

double Point::getStrength() {
    return strength;
}

double Point::getAngle() {
    return angle;
}