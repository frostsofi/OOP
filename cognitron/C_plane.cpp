#include <malloc.h>
#include <cmath>
#include <iostream>
#include <time.h>
#include "C_plane.h"

C_plane::C_plane(int size_of_cells, int size_of_connection, float add_to_d)
{
    this->add_to_d = add_to_d;

    this->size_of_connection = size_of_connection;
    this->weights_d = (float*)malloc(size_of_connection*size_of_connection* sizeof(float));
    this->size_of_cells = size_of_cells;

    this -> cells = (float*)malloc(size_of_cells*size_of_cells* sizeof(float));

    for (int i = 0; i < size_of_cells*size_of_cells; i++)
        this -> cells[i] = 0;

    initialize_weights();
}

float *C_plane::get_weights()
{
    return weights_d;
}

float *C_plane::get_cells()
{
    return cells;
}

int C_plane::get_size_of_cells()
{
    return size_of_cells;
}

C_plane::~C_plane()
{
    free(weights_d);
    free(cells);
}

int C_plane::rand = 5;

void C_plane::initialize_weights()
{
    std::mt19937 gen;
    gen.seed(static_cast<unsigned int>(time(nullptr) + rand));
    rand++;

    int size = 0;
    if (size_of_connection % 2 != 0)
        size = (size_of_connection+1)/2;
    else
        size = size_of_connection/2;

    for (int i = 0; i < size_of_connection*size_of_connection; i++)
    {
        weights_d[i] =  ((gen() % 9 + 1) / 10.0f);
        weights_d[i] = static_cast<float>(std::pow(weights_d[i], distance(i, size)));
    }
}

double C_plane::distance(int point, int center)
{
    int x = point/size_of_connection;
    int y = point - x*size_of_connection;

    int center_x = center/size_of_connection;
    int center_y = center - center_x*size_of_connection;

    center_x -= x;
    center_y -= y;

    return std::sqrt(center_x*center_x + center_y*center_y);
}

void C_plane::set_cells(float *cells)
{
    this->cells = cells;
}
