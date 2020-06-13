//
// Created by frost on 24.04.2020.
//

#include <malloc.h>
#include <random>
#include <time.h>
#include <iostream>
#include "S_plane.h"

int S_plane::rand = 0;

void S_plane::initialize_weights()
{

    for (int k = 0; k < 10; k++)
    {
        float *weights_a = weights_s->weights_a[k];
        for (int i = 0; i < size_of_connection*size_of_connection; i ++)
        {
            weights_a[i] = 0.1e-7;
        }
    }

    weights_s -> weights_b = 0.1e-7;
}

S_plane::S_plane(int size_of_cells, int size_of_connection)
{
    this->size_of_connection = size_of_connection;
    this->weights_s = new Weights_s_plane;

    weights_s->weights_a.reserve(10);
     for (int i = 0; i < 10; i++)
    {
        weights_s->weights_a.push_back(new float[size_of_connection*size_of_connection]);
    }

    this->size_of_cells = size_of_cells;

    cells = (float*)malloc(size_of_cells*size_of_cells* sizeof(float));

    for (int i = 0; i < size_of_cells*size_of_cells; i++)
        this -> cells[i] = 0.0;

    initialize_weights();
}

Weights_s_plane *S_plane::get_weights()
{
    return weights_s;
}

float *S_plane::get_cells()
{
    return cells;
}

int S_plane::get_size_of_cells()
{
    return size_of_cells;
}

S_plane::~S_plane()
{
    for (int k = 0; k < 10; k++)
    {
        free(weights_s->weights_a[k]);
    }

    free(weights_s);
    free(cells);
}
