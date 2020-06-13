//
// Created by frost on 24.04.2020.
//

#include <malloc.h>
#include <cmath>
#include <random>
#include <time.h>
#include <iostream>
#include "V_plane.h"

int V_plane::rand = 1;

V_plane::V_plane(int size_of_cells, int size_of_connection)
{
    this->size_of_connection = size_of_connection;
    this->weights_c = (float*)malloc(size_of_connection*size_of_connection* sizeof(float));
    this->size_of_cells = size_of_cells;

    cells = (float*)malloc(size_of_cells*size_of_cells* sizeof(float));
    initialize_weights();

}

void V_plane::initialize_weights()
{
    std::mt19937 gen;
    gen.seed(static_cast<unsigned int>(time(nullptr)) + rand);
    rand++;

    int size = 0;
    if (size_of_connection % 2 != 0)
        size = (size_of_connection+1)/2;
    else
        size = size_of_connection/2;

    for (int i = 0; i < size_of_connection*size_of_connection; i++)
    {
        weights_c[i] =  ((gen() % 9 + 1) / 10.0f);
        weights_c[i] = static_cast<float>(std::pow(weights_c[i], distance(i, size)));
    }

}

double V_plane::distance(int point, int center)
{
    int x = point/size_of_connection;
    int y = point - x*size_of_connection;

    int center_x = center/size_of_connection;
    int center_y = center - center_x*size_of_connection;

    center_x -= x;
    center_y -= y;

    return std::sqrt(center_x*center_x + center_y*center_y);
}

float *V_plane::get_weights()
{
    return weights_c;
}

float *V_plane::get_cells()
{
    return cells;
}

V_plane::~V_plane()
{
    free(weights_c);
    free(cells);
}

int V_plane::get_size_of_cells()
{
    return size_of_cells;
}
