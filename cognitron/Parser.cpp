#include <iostream>
#include <fstream>
#include "Parser.h"

Parser::Parser() {};

std::vector<Label*> Parser::labels;
std::vector<std::vector<Label*>> Parser::test_labels;

std::vector<Label*> Parser::getLabels()
{
    return labels;
}

uint32_t Parser::swap_endian(uint32_t val)
{
    val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
    return (val << 16) | (val >> 16);
}

void Parser::parseLabels(std::string nameLabels, std::string nameImages)
{
    std::ifstream in_labels(nameLabels, std::ios::binary);
    std::ifstream in_images(nameImages, std::ios::binary);

    uint32_t magic_number = 0;
    uint32_t number_of_items = 0;
    uint32_t number_of_rows = 0;
    uint32_t number_of_columns = 0;
    uint32_t number_of_images = 0;

    char label;

    std::vector<bool> processed_numbers(10);
    for (int i = 0; i < 10; i++)
    {
        processed_numbers[i] = false;
        test_labels.push_back(std::vector<Label*>());
    }

    if (in_labels.is_open())
    {
        in_labels.read(reinterpret_cast<char *>(&magic_number), 4);
        in_labels.read(reinterpret_cast<char *>(&number_of_items), 4);

        in_images.read(reinterpret_cast<char *>(&magic_number), 4);
        in_images.read(reinterpret_cast<char *>(&number_of_images), 4);
        in_images.read(reinterpret_cast<char *>(&number_of_rows), 4);
        in_images.read(reinterpret_cast<char *>(&number_of_columns), 4);

        number_of_items = swap_endian(number_of_items);
        number_of_rows = swap_endian(number_of_rows);
        number_of_columns = swap_endian(number_of_columns);

        int size_of_image = number_of_columns*number_of_rows;

        while(number_of_items)
        {
            auto *labelObj = new Label();

            char *vToRead = new char[size_of_image];
            in_labels.read(&label, 1);
            labelObj -> putLabel(label);

            in_images.read(vToRead, size_of_image);

            for (int  i = 0; i < size_of_image; i++)
            {
                if ((float)vToRead[i] != 0.0f)
                    labelObj->getImage()[i] = 1.0f;
            }

            labels.push_back(labelObj);

            --number_of_items;

            if (processed_numbers[labelObj -> getLabel()] == false)
            {
                test_labels[labelObj -> getLabel()].push_back(labelObj);

                if (test_labels[labelObj -> getLabel()].size() == 5000)
                    processed_numbers[labelObj -> getLabel()] = true;

            }

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

std::vector<std::vector<Label *>> Parser::get_test_labels()
{
    return test_labels;
}
