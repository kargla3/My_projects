#include "ActivationFunction.h";
#include <cmath>

class Tanh : public ActivationFunction
{
public:
    double activate(double x) const override {
        return tanh(x);
    }
    double derivative(double x) const override {
        double fx = activate(x);
        return 1 - fx * fx;
    }
};