#ifndef COGNITRON_STAGE_H
#define COGNITRON_STAGE_H

#include <iostream>
#include <vector>
#include "S_plane.h"
#include "V_plane.h"
#include "C_plane.h"


class Stage
{
private:
    int size_of_connection;
    int size_of_column;

    std::vector<S_plane*> s_layer;
    std::vector<C_plane*> c_layer;
    std::vector<V_plane*> v_layer;

    void computation_c_layer();
    void computation_v_layer(std::vector<C_plane*> &);
    void computation_s_layer(std::vector<C_plane*> &);

    float threshold(float);
    float upper_threshold(float);
    void round_connection_region_v(float* source, float* final, float *weights, int width, int connect_i, int connect_j);
    void round_connection_region_s(float*, float*, float *, int, int, int);
    void pooling(float *source, float *final, float *w, int w1, int w2);

    std::vector<std::vector<int>> find_max_per_column();

    float tet;
    float speed_of_learning;

public:
    std::vector<std::pair<int, int>> get_locations_to_learn();

    Stage(int size_of_connection, int size_s, int size_c, int, float tet, float speed);
    std::vector<C_plane*> &get_c_layer();
    void set_c_layer(std::vector<C_plane*> &c_layers);

    void change_weights(std::vector<C_plane*> &c_layers);
    void learning(std::vector<C_plane *> &c_layers);
    void clear();

    ~Stage();
};


#endif //COGNITRON_STAGE_H
