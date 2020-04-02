//
// Created by frost on 13.03.2020.
//

#ifndef PARCEPTRON_NEURON_H
#define PARCEPTRON_NEURON_H

#include <iostream>
#include <vector>
#include <cmath>

class Neuron
{
private:
    std::vector<float> weights;
    float doSum(const std::vector<float> &);
    void correctWeights(std::vector<float> &inV, float delta);
public:
    Neuron(int numb_neurons);

    float makeFunc(const  std::vector<float> &);
    std::vector<float> getDelta(const float &deltaV, std::vector<float> &inV);
};


#endif //PARCEPTRON_NEURON_H
