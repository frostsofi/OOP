#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include <map>
#include "execution.h"
#include "Factory.h"

using  namespace std;

class calculator
{
private:
    execution myContext;

public:
    void sort(string &);
    void treatment();
};
#endif //CALCULATOR_CALCULATOR_H
