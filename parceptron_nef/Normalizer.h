//
// Created by frost on 22.03.2020.
//

#ifndef PARCEPTRON_NEF_NORMALIZER_H
#define PARCEPTRON_NEF_NORMALIZER_H


#include <vector>

class Normalizer
{
private:
    static std::vector<float> maxes;
    static std::vector<float> minis;

public:
    static void initialize_maxes();
    static void initialize_minis();
    static void normalize(std::vector<float> &data, std::vector<float> &classes);
};


#endif //PARCEPTRON_NEF_NORMALIZER_H
