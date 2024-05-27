#include "ActivationFunction.h"
#include <cmath>

class ArcTan : public ActivationFunction
{
public:
    double activate(double x) const override {
        return atan(x);
    }
    double derivative(double x) const override {
        return 1.0 / (x * x + 1);
    }
};