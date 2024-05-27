//
// Created by myychal on 2016-11-06.
//

#ifndef NEURALNETGA_NEURON_H
#define NEURALNETGA_NEURON_H
#include <iostream>
#include <cmath>
#include "ActivationFunction.h"
#include "Sigmoid.h"
#include "Tanh.h"
#include "ArcTan.h"
#include "ReLU.h"

class Neuron {
private:
    double Input;
    double Output;
    double Propagated_Error;
    ActivationFunction* activationFunc;
public:
    Neuron();

    double get_Input() const;

    void set_Input(double m_Input);

    double get_Output() const;

    void set_Output(double m_Output);

    double get_Propagated_Error() const;

    void set_Propagated_Error(double m_Propagated_Error);

    virtual ~Neuron();

    void AddToInput(double Value);

    void SigmoidActivationFunction();

    double Derivative();

    void AddToPropagatedError(double error);

    void Activate();

};


#endif //NEURALNETGA_NEURON_H
