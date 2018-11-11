//
// Created by frost on 03.11.2018.
//

#ifndef CALCULATOR_FACTORY_H_H
#define CALCULATOR_FACTORY_H_H

#include "base.h"
#include <exception>


class commandFactory {

public:
    std::map <std::string, commandCreator*> commands;

    static commandFactory &getInstance()
    {
        static commandFactory f;
        return f;
    }

    void includeCommand(string &, commandCreator *);
    ~commandFactory();
};

#endif //CALCULATOR_FACTORY_H_H
