//
// Created by frost on 10.03.2020.
//

#include <iostream>
#include "Label.h"

int Label::getLabel()
{
    return label;
}

void Label::putLabel(char label_)
{
    label = int(label_);
}

float *Label::getImage()
{
    return image;
}

Label::Label()
{
    image = (float*)malloc(28*28* sizeof(float));
}

Label::~Label()
{
    free(image);
}
