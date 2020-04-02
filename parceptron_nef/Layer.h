//
// Created by frost on 13.03.2020.
//

#ifndef PARCEPTRON_LAYER_H
#define PARCEPTRON_LAYER_H


#include <vector>
#include "Neuron.h"

class Layer
{
private:
    std::vector<float> myInV;
    std::vector<float> myDeltaV;
    std::vector<Neuron*> neurons;

public:

    Layer(int num_neurons, int numb_weights);

    //this method will return our inVector, which we will use to make calculation with neurons
    std::vector<float> getInVector();

    //this method will return our deltaVector, which we will use to make correct weights in our layer
    std::vector<float> getDeltaVector();

    //calculate fault out vector
    void makeFaultVector(std::vector<float> &, std::vector<float>);

    //calculate out vector to next layer
    void makeInVector(const std::vector<float> &);
    ~Layer();

};


#endif //PARCEPTRON_LAYER_H