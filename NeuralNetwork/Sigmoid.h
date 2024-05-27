#include "ActivationFunction.h"
#include <cmath>

class Sigmoid : public ActivationFunction
{
public:
	double activate(double x) const override
	{
		return 1.0 / (1.0 + exp(-1.0 * x));
	}
	double derivative(double x) const override
	{
		double fx = activate(x);
		return 1.0 * fx * (1 - fx);
	}
};