//
// Created by frost on 01.05.2020.
//

#include <algorithm>
#include <time.h>
#include "Neocognitron.h"

int Neocognitron::make_iteration(float *inputImage, int size)
{
    std::vector<C_plane*> c_layers;
    C_plane *input;
    c_layers.push_back(input = new C_plane(size, 2, 0.1));
    input ->set_cells(inputImage);


    for (int i = 0; i < stages.size(); i++)
    {
       stages[i]->set_c_layer(c_layers);
        c_layers = stages[i]->get_c_layer();
    }

    float max = 0.0;

    for (int i = 0; i < 10; i++)
    {
        if (c_layers[i]->get_cells()[0] > max)
        {
           max = c_layers[i] -> get_cells()[0];
        }
    }

    for (int i = 0; i < 10; i++)
    {
        std::cout << "______________________________________"<< c_layers[i]->get_cells()[0] <<" - - " << i << std::endl;

        if (c_layers[i]->get_cells()[0] == max)
        {
           std::cout << "________________________________A N S W E R _______"<< max <<" - - " << i << std::endl;
        }
    }
}

void Neocognitron::learn(float *inputImage, int size, int learning_layer)
{
    std::vector<C_plane*> c_layers;
    C_plane *input;
    c_layers.push_back(input = new C_plane(size, 2, 0.1));
    input ->set_cells(inputImage);

    for (int i = 0; i < learning_layer; i++)
    {
        stages[i]->set_c_layer(c_layers);
        c_layers = stages[i]->get_c_layer();
    }

    stages[learning_layer]->learning(c_layers);
}

Neocognitron::Neocognitron()
{
    std::mt19937 gen;
    gen.seed(static_cast<unsigned int>(time(nullptr)));

    stages.push_back(new Stage(2, 28, 14, 5, 0.01f, 2.0f));
    stages.push_back(new Stage(2, 14, 7, 3, 0.01f, 2.0f));
    stages.push_back(new Stage(3, 7, 2, 2, 0.01f,  2.0f));
    stages.push_back(new Stage(2, 2, 1, 2, 0.01f, 2.0f));
}

Neocognitron::~Neocognitron()
{
    for (auto &stage : stages)
    {
        free(stage);
    }
}

void Neocognitron::clear()
{
    for (auto st : stages)
    {
        st->clear();
    }
}


