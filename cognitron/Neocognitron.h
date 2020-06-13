//
// Created by frost on 01.05.2020.
//

#ifndef COGNITRON_NEOCOGNITRON_H
#define COGNITRON_NEOCOGNITRON_H


#include <vector>
#include "Stage.h"

class Neocognitron
{
private:
    std::vector<Stage*> stages;
public:
    Neocognitron();
    int make_iteration(float *, int);
    ~Neocognitron();

    void clear();
    void learn(float *inputImage, int size, int number);
};


#endif //COGNITRON_NEOCOGNITRON_H
