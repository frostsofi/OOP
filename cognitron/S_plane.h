//
// Created by frost on 24.04.2020.
//

#ifndef COGNITRON_S_PLANE_H
#define COGNITRON_S_PLANE_H

struct Weights_s_plane
{
    std::vector<float *> weights_a;
    float weights_b;
};

class S_plane
{
private:
    float *cells;
    int size_of_connection;
    int size_of_cells;
    Weights_s_plane *weights_s;
    void initialize_weights();
    static int rand;

public:

    S_plane(int size_of_cells, int size_of_connection);
    Weights_s_plane *get_weights();
    float *get_cells();
    int get_size_of_cells();
    ~S_plane();
};




#endif //COGNITRON_S_PLANE_H
