//
// Created by frost on 21.03.2020.
//

#include <fstream>
#include "parser.h"
#include "Data.h"
#include "Normalizer.h"

std::vector<Label*> Parser::labels;
constexpr float Data::EMPTY;

std::vector<Label*> Parser::getLabels()
{
    return labels;
}

void Parser::parseLabels(std::string nameLabels)
{

    std::ifstream in_labels(nameLabels);
    std::vector<float> data(18);
    std::vector<float> class_(2);
    std::string str;

    while(!in_labels.eof())
    {
        Label *l = new Label();

        in_labels >> str;

        lineProcessing(str, data);
        lineProcessing(str, class_);

        Normalizer::normalize(data, class_);
        l -> putClass(class_);
        l -> putData(data);
        labels.push_back(l);
    }

}

void Parser::lineProcessing(std::string &str, std::vector<float> &v)
{
    std::string::size_type  sz;

    for (int i = 0; i < v.size(); i++)
    {
        if (str.front() == ',')
        {
            v[i] = Data::EMPTY;
            str.erase(0, 1);
        }
        else
        {
            v[i] = std::stof(str, &sz);
            str.erase(0, sz + 1);
        }
    }
}

Parser::~Parser()
{
    for (auto label : labels)
    {
        delete(label);
    }
}
