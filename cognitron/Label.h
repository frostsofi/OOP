//
// Created by frost on 10.03.2020.
//

#ifndef PARCEPTRON_LABELS_H
#define PARCEPTRON_LABELS_H

#include <cstdint>
#include <vector>

class Label
{
private:
    int label;
    float *image;

public:
    int getLabel();
    void putLabel(char);
    float *getImage();
    Label();
    ~Label();
};
#endif //PARCEPTRON_LABELS_H
