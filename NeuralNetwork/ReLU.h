#include "ActivationFunction.h"

class ReLU : public ActivationFunction
{
public:
    double activate(double x) const override {
        return x > 0 ? x : 0;
    }
    double derivative(double x) const override {
        return x > 0 ? 1 : 0;
    }
};