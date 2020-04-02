//
// Created by frost on 21.03.2020.
//

#ifndef PARCEPTRON_NEF_LABEL_H
#define PARCEPTRON_NEF_LABEL_H
#include <iostream>
#include <vector>

class Label
{
private:
    std::vector<float> data;
    std::vector<float> class_;

public:
    std::vector<float> &getClass();
    void putClass(std::vector<float>);
    void putData(std::vector<float>);
    std::vector<float> &getData();
    std::vector<float> getDataCopy();
};


#endif //PARCEPTRON_NEF_LABEL_H
