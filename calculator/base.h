//
// Created by frost on 03.11.2018.
//

#ifndef CALCULATOR_BASE_H
#define CALCULATOR_BASE_H

#include "execution.h"

class command {
public:
    virtual void execute(execution &myContext, string &arg)= 0;
    virtual ~command() = default;
};

class commandCreator {
public:
    virtual command *create() = 0;
    virtual ~commandCreator() = default;

};


#endif //CALCULATOR_BASE_H
