#ifndef POINT_H
#define POINT_H

class Point {
    double distance = 0;
    double strength = 0;
    double angle = 0;

public: 
    Point();
    void setDistance(double distance);
    void setStrength(double strength);
    void setAngle(double angle);

    double getDistance();
    double getStrength();
    double getAngle();
};

#endif