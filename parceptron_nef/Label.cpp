//
// Created by frost on 21.03.2020.
//

#include "Label.h"

std::vector<float> &Label::getClass()
{
    return class_;
}

void Label::putData(std::vector<float> data_)
{
    for (int i = 0; i < data_.size(); i++)
    {
        data.push_back(data_[i]);
    }
}

void Label::putClass(std::vector<float> class__)
{
    for (int i = 0; i < class__.size(); i++)
    {
        class_.push_back(class__[i]);
    }
}

std::vector<float> &Label::getData()
{
    return data;
}

std::vector<float> Label::getDataCopy()
{
    return data;
}