#include <iostream>
#include "Parser.h"
#include "Neural_net.h"
#include "Normalizer.h"

float h = 0.002;

enum Layers_numeration
{
    number_layers = 3,
    num_first_layer = 0,
    num_second_layer = 1,
    num_third_layer = 2,

    num_inputs = 18,
};

int main()
{
    Normalizer::initialize_maxes();
    Normalizer::initialize_minis();

    Parser::parseLabels("C:\\Users\\frost\\CLionProjects\\parceptron_nef\\data\\data4.csv");

    int layers_num_neurons[number_layers];
    layers_num_neurons[num_first_layer] = 30;
    layers_num_neurons[num_second_layer] = 900;
    layers_num_neurons[num_third_layer] = 2;

    auto *net = new Neural_net(number_layers, layers_num_neurons, num_inputs);
    float signal = 0.0f;
    float cost_func = 0.0f;
    float sum = 0.0f;
    int count = 0;

    while(count != 44)
    {
            signal = net->makeIteration(*Parser::getLabels()[count]);
            std::cout << "error: " << signal << std::endl;

            count ++;
            sum += (signal * signal) / 2;
            cost_func = sum / count;
            std::cout << "efficient: " << cost_func << std::endl << std::endl;

            net->makeCorrection(signal, *Parser::getLabels()[count]);
    }


    std::cout << "-------------------------------------------------" << std::endl << "CHECK: " << std::endl;

    for (count = 44; count < 149; count++)
    {
        signal = net->makeIteration(*Parser::getLabels()[count]);
        if (std::abs(signal) < 0.1)
            std::cout <<"correct" << std::endl;
        else
            std::cout <<"not correct " << signal << std::endl;
        count++;
    }

    delete(net);

    return 0;
}
