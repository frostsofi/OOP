//
// Created by frost on 24.04.2020.
//

#ifndef COGNITRON_V_PLANE_H
#define COGNITRON_V_PLANE_H

class V_plane
{
private:
    float *cells;
    int size_of_connection;
    int size_of_cells;
    float *weights_c;
    void initialize_weights();
    static int rand;

public:
    V_plane(int size_of_cells, int size_of_connection);
    float *get_weights();
    float *get_cells();
    int get_size_of_cells();
    double distance(int point, int center);

    ~V_plane();
};


#endif //COGNITRON_V_PLANE_H
