//
// Created by frost on 21.03.2020.
//

#ifndef PARCEPTRON_NEF_PARSER_H
#define PARCEPTRON_NEF_PARSER_H
#include <iostream>
#include "Label.h"
#include <vector>

class Parser
{
private:
    static std::vector<Label*> labels;
    static void lineProcessing(std::string &, std::vector<float> &);

public:
    static std::vector<Label*> getLabels();
    static void parseLabels(std::string);
    ~Parser();
};


#endif //PARCEPTRON_NEF_PARSER_H
