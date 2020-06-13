#include <iostream>
#include "Stage.h"
#include "Neocognitron.h"
#include "Parser.h"

int main()
{

    Parser::parseLabels("C:\\Users\\frost\\CLionProjects\\cognitron\\data\\train_labels.idx1-ubyte",
                        "C:\\Users\\frost\\CLionProjects\\cognitron\\data\\train_images.idx3-ubyte");

    auto *neo = new Neocognitron();

    std::vector<std::vector<Label*>> testLabels = Parser::get_test_labels();


    for (int layer = 0; layer < 4; layer++)
    {

            for (int j = 0; j < 100; j ++)
            {
                for (int i = 0; i < 10; i ++)
                {
                    neo->learn((testLabels[i])[j]->getImage(), 28, layer);
                    std::cout << "EXAMPLE GONE " << i << " " << j << std::endl;
                    neo->clear();
                }
            }
    }

    for (int i = 0; i < 5000; i++)
    {
        if (neo -> make_iteration(Parser::getLabels()[i]->getImage(), 28) != -1)
              std::cout << "R E A L _____L A B E L_______________" << Parser::getLabels()[i]->getLabel() << std::endl;
        else
            std::cout << "zerro" << std::endl;
        neo->clear();
    }

    free(neo);

    return 0;
}