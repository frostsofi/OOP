#ifndef PARCEPTRON_NEURAL_NET_H
#define PARCEPTRON_NEURAL_NET_H

#include <iostream>
#include <vector>
#include "Layer.h"
#include "Label.h"

class Neural_net
{
private:
    std::vector<Layer*> layers;

public:
    Neural_net(int, int[], int);
    ~Neural_net();

    float makeIteration(Label &);
    void makeCorrection(float, Label &label);

};


#endif