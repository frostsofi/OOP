#ifndef COGNITRON_C_PLANE_H
#define COGNITRON_C_PLANE_H

#include <random>

class  C_plane
{
private:
    static int rand;
    float *cells;
    int size_of_connection;
    int size_of_cells;
    float *weights_d;
    void initialize_weights();
    float add_to_d;

public:
    C_plane(int size_of_cells, int size_of_connection, float);
    float *get_weights();
    float *get_cells();
    void set_cells(float *);
    int get_size_of_cells();
    double distance(int point, int center);

    ~C_plane();
};


#endif //COGNITRON_Ñ_PLANE_H
