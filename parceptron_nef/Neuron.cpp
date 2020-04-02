#include <cmath>
#include <random>
#include <time.h>
#include "Neuron.h"

extern float h;

Neuron::Neuron(int size)
{
    std::mt19937 gen;
    gen.seed(static_cast<unsigned int>(time(nullptr)));

    float value;
    for (int i = 0; i < size; i++)
    {
        value = static_cast<float>(0.5f - ((gen() % 9 + 1) / 10.0));

        weights.push_back(value);
    }
}

float Neuron::doSum(const std::vector<float> &inV)
{
    float sum = 0.0;

    for (int i = 0; i < inV.size(); i++)
    {
        sum += weights[i]*inV[i];
    }
    return sum;
}

float Neuron::makeFunc(const std::vector<float> &inV)
{
    return 1 / (1 + std::exp(-doSum(inV)));
}

void Neuron::correctWeights(std::vector<float> &inV, float delta)
{
    for(int i = 0; i < weights.size(); i++)
    {

        weights[i] =  weights[i]+h*delta*inV[i]*makeFunc(inV)*(1-makeFunc(inV));
        // std::cout <<"weight is: " << weights[i] << std::endl;
    }
}

std::vector<float> Neuron::getDelta(const float &delta, std::vector<float> &inV)
{
    std::vector<float> deltaV;

    for (int i = 0; i < weights.size(); i++)
    {
        deltaV.push_back(delta*weights[i]);
    }

    correctWeights(inV, delta);
    return deltaV;
}