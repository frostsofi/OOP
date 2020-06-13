#include <cmath>
#include <algorithm>
#include "Stage.h"

float Stage::threshold(float value)
{
    if (value >= 0)
        return value;
    else
        return 0.0;
}

float Stage::upper_threshold(float value)
{
    if (value >= 0)
    {
        return (value/(1 + value));
    }
    else
    {
        return 0.0;
    }
}

void Stage::pooling(float *array_source, float *array_final, float *weights,
                    int width1, int width2)
{
    int cur_i = 0;
    int cur_j = 0;
    int count = 0;

    while (cur_i < width1)
    {
        for (int i = cur_i*size_of_connection; i < cur_i*size_of_connection + size_of_connection + 1; i++)
        {
            for (int j = cur_j*size_of_connection; j < cur_j*size_of_connection + size_of_connection + 1; j++)
            {
                *(array_final + cur_i * width1 + cur_j) +=
                        *(weights + count)*(*(array_source + i * width2 + j));
                count++;
            }
        }

        *(array_final + cur_i * width1 + cur_j) = upper_threshold(*(array_final + cur_i * width1 + cur_j));
        count = 0;
        cur_j++;
        if (cur_j >= width1)
        {
            cur_j = 0;
            cur_i++;
        }
    }

}

void Stage::computation_c_layer()
{
    for (int i = 0; i < s_layer.size(); i++)
    {
        pooling(s_layer[i] ->get_cells(), c_layer[i] -> get_cells(),
        c_layer[i] ->get_weights(), c_layer[i] ->get_size_of_cells(), s_layer[i] ->get_size_of_cells());
    }
}

void Stage::computation_s_layer(std::vector<C_plane *> &c_layer_prev)
{
    for (auto &s_plane : s_layer)
    {
        int connect_i = 0;
        int connect_j = 0;

        while (connect_i != s_layer[0]->get_size_of_cells())
        {
            for (int i = 0; i < c_layer_prev.size(); i ++)
            {
                round_connection_region_s(c_layer_prev[i]->get_cells(), s_plane->get_cells(),
                                        s_plane->get_weights() -> weights_a[i],
                                        s_plane->get_size_of_cells(), connect_i, connect_j);
            }

            int size = v_layer[0]->get_size_of_cells();
            float *s_cells = s_plane->get_cells();
            float *v_cells = v_layer[0] ->get_cells();
            float weight_b = s_plane->get_weights()->weights_b;

             float value_threshold = threshold(((1 + (*(s_cells+connect_i*size+connect_j)))
                    /(1+tet*(weight_b)
                    *(*(v_cells+connect_i*size+connect_j))))-1);

            *(s_cells+connect_i*size+connect_j) = value_threshold*(tet/(1-tet));
            connect_j ++;

            if (connect_j >= v_layer[0]->get_size_of_cells())
            {
                connect_j = 0;
                connect_i ++;
            }
        }
    }
}

void Stage::computation_v_layer(std::vector<C_plane*> &c_layer_prev)
{
    int connect_i = 0;
    int connect_j = 0;

    while (connect_i != v_layer[0] -> get_size_of_cells())
    {
        for (int i = 0; i < c_layer_prev.size(); i ++)
        {
            round_connection_region_v(c_layer_prev[i] -> get_cells(), v_layer[0] -> get_cells(),
                                    v_layer[0] -> get_weights(),
                                    v_layer[0] -> get_size_of_cells(), connect_i, connect_j);
        }

        int size = v_layer[0] -> get_size_of_cells();

        *(v_layer[0] -> get_cells()+connect_i*size+connect_j) =
                std::sqrt(*(v_layer[0] -> get_cells() + connect_i * size + connect_j));

        connect_j++;
        if (connect_j >=  v_layer[0] -> get_size_of_cells())
        {
            connect_j = 0;
            connect_i++;
        }
    }
}

void Stage::round_connection_region_s(float* source_cells, float* final_cells, float *weights,
                                    int width, int connect_i, int connect_j)
{
    int count = 0;
    for (int i = connect_i - 1; i < connect_i + size_of_connection; i++)
    {
        for (int j = connect_j - 1; j < connect_j + size_of_connection; j++)
        {
            if (i >= 0 && j >= 0 && i < width  && j < width)
            {
                *(final_cells + connect_i * width + connect_j) +=
                        *(weights + count)*(*(source_cells + i * width + j));
            }
        }
    }
}

void Stage::round_connection_region_v(float* source_cells, float* final_cells, float *weights,
                                    int width, int connect_i, int connect_j)
{
    int count = 0;
    for (int i = connect_i - 1; i < connect_i + size_of_connection; i++)
    {
        for (int j = connect_j - 1; j < connect_j + size_of_connection; j++)
        {
            if (i >= 0 && j >= 0 && i < width  && j < width)
            {
                *(final_cells + connect_i * width + connect_j) +=
                        *(weights + count)*pow((*(source_cells + i * width + j)),2);
            }
        }
    }
}

Stage::Stage(int size_of_connection, int size_s_layer, int size_c_layer, int size_of_column,
float tet, float speed)
{
    for (int i = 0; i < 10; i++)
    {
        c_layer.push_back(new C_plane(size_c_layer, size_of_connection, i));
        s_layer.push_back(new S_plane(size_s_layer, size_of_connection));
    }

    v_layer.push_back(new V_plane(size_s_layer, size_of_connection));

    this->size_of_connection = size_of_connection-1;
    this->size_of_column = size_of_column;
    this->tet = tet;
    this->speed_of_learning = speed;

}

void Stage::set_c_layer(std::vector<C_plane*> &c_layers)
{
    computation_v_layer(c_layers);
    computation_s_layer(c_layers);
    computation_c_layer();
}

std::vector<std::vector<int>> Stage::find_max_per_column()
{

    int number_of_column = s_layer[0]->get_size_of_cells()/size_of_column;
    int number_of_columns = number_of_column*number_of_column;
    std::vector<std::vector<int>> maxes(number_of_columns);

    int size = s_layer[0]->get_size_of_cells();

    int connect_i = 0;
    int connect_j = 0;

   for (int i = 0; i < number_of_columns; i++)
   {
       float max = 0.0f;
       maxes[i];
        for (int k = 0; k < s_layer.size(); k++)
        {
            for (int x = connect_i*size_of_column; x < connect_i*size_of_column + size_of_column; x++)
            {
                for (int y = connect_j*size_of_column; y < connect_j*size_of_column + size_of_column; y++)
                {
                    if (*(s_layer[k]->get_cells()+x*size+y) > max)
                    {
                        max = *(s_layer[k]->get_cells()+x*size+y);

                        if(maxes[i].empty()) {
                            maxes[i].push_back(k);
                            maxes[i].push_back(x);
                            maxes[i].push_back(y);
                        }
                        else
                        {
                            maxes[i][0] = k;
                            maxes[i][1] = x;
                            maxes[i][2] = y;
                        }
                    }

                }
            }
        }
       connect_j++;
       if (connect_j*size_of_column >= size)
       {
           connect_j = 0;
           connect_i++;
       }
   }
    return maxes;
}

std::vector<std::pair<int, int>> Stage::get_locations_to_learn()
{
    std::vector<std::vector<int>> maxes = find_max_per_column();
    std::vector<std::pair<int, int>> maxes_planes;

    for (int k = 0; k < s_layer.size(); k++)
    {
        float max = 0.0;
        int max_x = 0;
        int max_y = 0;
        for (auto point : maxes)
        {
            if (point.empty())
                continue;

            if (point[0] == k)
            {
                if (*(s_layer[k]->get_cells() + s_layer[k]->get_size_of_cells()*point[1] + point[2]) > max)
                {
                    max = *(s_layer[k]->get_cells() + s_layer[k]->get_size_of_cells() * point[1] + point[2]);
                    max_x = point[1];
                    max_y = point[2];
                }
            }
        }

        maxes_planes.emplace_back(max_x, max_y);
    }

    return maxes_planes;
}


void Stage::learning(std::vector<C_plane*> &c_layers)
{

    computation_v_layer(c_layers);
    computation_s_layer(c_layers);
    computation_c_layer();
    change_weights(c_layers);
}

Stage::~Stage()
{
    for (int i = 0; i  < 10; i++)
    {
        free(c_layer[i]);
        free(s_layer[i]);
    }

    free(v_layer[0]);
}

std::vector<C_plane*> &Stage::get_c_layer()
{
    return c_layer;
}

void Stage::change_weights(std::vector<C_plane*> &c_layers)
{

    std::vector<std::pair<int, int>> locations = get_locations_to_learn();

    int size = s_layer[0]->get_size_of_cells();

    for (int k = 0; k < s_layer.size(); k++)
    {
        std::pair<int , int > location = locations[k];

        for (int ck = 0; ck < c_layers.size(); ck ++)
        {
            float *weights = s_layer[k]->get_weights()->weights_a[ck];

            int count = 0;
            for (int i = location.first - 1; i < location.first + size_of_connection; i ++)
            {
                for (int j = location.second - 1; j < location.second + size_of_connection; j ++)
                {
                    if (i >= 0 && j >= 0 && i <  size && j < size)
                    {
                        *(weights + count) +=
                                *(v_layer[0]->get_weights() + count)*(*(c_layers[ck]->get_cells() + i*size + j))*speed_of_learning;
                    }

                    count ++;
                }
            }
        }

        float *v_cells = v_layer[0]->get_cells();
        s_layer[k] -> get_weights()->weights_b += speed_of_learning*(*(v_cells + location.first*size + location.second));

    }
}

void Stage::clear()
{

    for (int i = 0; i < 10; i++)
    {
        for (int k = 0; k < s_layer[i]->get_size_of_cells()*s_layer[i]->get_size_of_cells(); k++)
        {
            s_layer[i]->get_cells()[k] = 0.0;
        }

        for (int m = 0; m < c_layer[i]->get_size_of_cells()*
                                    c_layer[i]->get_size_of_cells(); m++)
        {
            c_layer[i]->get_cells()[m] = 0.0;
        }
    }

    for (int l = 0; l < v_layer[0]->get_size_of_cells() * v_layer[0]->get_size_of_cells(); l++)
    {
        v_layer[0]->get_cells()[l] = 0.0;
    }
}
