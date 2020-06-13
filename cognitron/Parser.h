//
// Created by frost on 10.03.2020.
//

#ifndef PARCEPTRON_PARSER_H
#define PARCEPTRON_PARSER_H

#include "Label.h"
#include "vector"
#include "string"

class Parser
{
private:
    Parser();
    static std::vector<Label*> labels;

    static std::vector<std::vector<Label*>> test_labels;

    static uint32_t swap_endian(uint32_t val);

public:
    static std::vector<Label*> getLabels();
    static void parseLabels(std::string, std::string);
    static std::vector<std::vector<Label *>> get_test_labels();

    ~Parser();
};


#endif //PARCEPTRON_PARSER_H