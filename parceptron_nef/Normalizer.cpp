//
// Created by frost on 22.03.2020.
//

#include <iostream>
#include "Normalizer.h"
#include "Data.h"

std::vector<float> Normalizer::maxes;
std::vector<float> Normalizer::minis;

void Normalizer::initialize_maxes()
{
    maxes.push_back(4013.5f);
    maxes.push_back(15.88f);
    maxes.push_back(465.7f);
    maxes.push_back(458.6f);
    maxes.push_back(121.68f);
    maxes.push_back(465.7f);
    maxes.push_back(458.5f);
    maxes.push_back(123.62f);
    maxes.push_back(110.2f);
    maxes.push_back(105.6f);
    maxes.push_back(846.82f);
    maxes.push_back(302.62f);
    maxes.push_back(398.4f);
    maxes.push_back(6943.1f);
    maxes.push_back(492.8f);
    maxes.push_back(9.3f);
    maxes.push_back(101);
    maxes.push_back(99.98f);
    maxes.push_back(108);
    maxes.push_back(385.42f);

}

void Normalizer::initialize_minis()
{
    minis.push_back(3494.8f);
    minis.push_back(7.94f);
    minis.push_back(138.87f);
    minis.push_back(115.4f);
    minis.push_back(73.31f);
    minis.push_back(136);
    minis.push_back(114);
    minis.push_back(72.58f);
    minis.push_back(14);
    minis.push_back(18.2f);
    minis.push_back(138.98f);
    minis.push_back(0.86f);
    minis.push_back(0.1f);
    minis.push_back(1131);
    minis.push_back(13.9f);
    minis.push_back(0.1f);
    minis.push_back(75);
    minis.push_back(74.41f);
    minis.push_back(1.71f);
    minis.push_back(21);

}

void Normalizer::normalize(std::vector<float> &data, std::vector<float> &classes) {
    for (int i = 0; i < 18; i ++)
    {
        if ((data[i] < 0 && (data[i] - Data::EMPTY < 0.0000001f &&
                                data[i] + Data::EMPTY > -0.0000001f)))
            continue;

        data[i] = ((data[i] - minis[i]) / (maxes[i] - minis[i]));
    }

    if (!((classes[0] < 0 && (classes[0] - Data::EMPTY < 0.0000001f &&
                           classes[0] + Data::EMPTY > -0.0000001f))))
        classes[0] = ((classes[0] - minis[18]) / (maxes[18] - minis[18]));

    if (!((classes[1] < 0 && (classes[1] - Data::EMPTY < 0.0000001f &&
                           classes[1] + Data::EMPTY > -0.0000001f))))
        classes[1] = ((classes[1] - minis[19]) / (maxes[19] - minis[19]));

}