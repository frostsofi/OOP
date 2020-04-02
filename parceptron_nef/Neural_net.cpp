#include <algorithm>
#include "Neural_net.h"
#include "Data.h"


Neural_net::Neural_net(int amount_layers, int amount_neurons[], int num_inputs)
{

    layers.push_back(new Layer(amount_neurons[0], num_inputs));

    for (int i = 1; i < amount_layers; i++)
        layers.push_back(new Layer(amount_neurons[i], amount_neurons[i-1]));
}

Neural_net::~Neural_net()
{
    for (auto layer : layers)
    {
        delete(layer);
    }
}

float Neural_net::makeIteration(Label &label)
{
    std::vector<float> v = label.getDataCopy();

    for (auto &layer : layers)
    {
        layer -> makeInVector(v);
        v = layer -> getInVector();
    }

    std::vector<float> &classes = label.getClass();
    float error = 0.0;
    int count = 0;
    for (int j = 0; j < 2; j++)
    {
        if (classes[j] < 0 && (classes[j] - Data::EMPTY < 0.0000001f &&
                classes[j] + Data::EMPTY > -0.0000001f))
        {
            continue;
        }
        else
        {
            ++count;
            error += classes[j] - v[j];
        }
    }
    return error/count;
}

void Neural_net::makeCorrection(float res, Label &label)
{
    std::reverse(layers.begin(),layers.end());

    std::vector<float> v = {res};

    for (int i = 0; i < layers.size() - 1; i++)
    {
        layers[i] -> makeFaultVector(v, layers[i+1] -> getInVector());
        v = layers[i] -> getDeltaVector();
    }

    layers[layers.size()-1] -> makeFaultVector(v, label.getDataCopy());
    std::reverse(layers.begin(),layers.end());
}
