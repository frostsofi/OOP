//
// Created by frost on 13.03.2020.
//

#include "Layer.h"

Layer::Layer(int numb_neurons, int numb_weights)
{
    for (int i = 0; i < numb_neurons; i++)
    {
        neurons.push_back(new Neuron(numb_weights));
    }
}

Layer::~Layer()
{
    for (auto neuron : neurons)
    {
        delete(neuron);
    }
}

void Layer::makeInVector(const std::vector<float> &inV)
{
    myInV.clear();

    for (int i = 0; i < neurons.size(); i++)
    {
        myInV.push_back(neurons[i] -> makeFunc(inV));
    }
}

std::vector<float> Layer::getInVector()
{
    return myInV;
}

void Layer::makeFaultVector(std::vector<float> &deltaV, std::vector<float> inV)
{
    myDeltaV.clear();

    //for every neuron calculate every its weight on its delta
    //then we sum new delta-vector
    for (int i = 0; i < neurons.size(); i++)
    {
        const std::vector<float> &v = neurons[i] -> getDelta(deltaV[i], inV);
        if (myDeltaV.empty())
        {
            for (int j = 0; j < v.size(); j++)
            {
                myDeltaV.push_back(v[j]);
            }
            continue;
        }

        for (int j = 0; j < v.size(); j++)
        {
            myDeltaV[j] += v[j];
        }
    }
}

std::vector<float> Layer::getDeltaVector()
{
    return myDeltaV;
}