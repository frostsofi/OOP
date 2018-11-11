//
// Created by frost on 03.11.2018.
//

#ifndef CALCULATOR_EXECUTION_H
#define CALCULATOR_EXECUTION_H

#include <stack>
#include <map>
#include <iostream>
#include <cmath>


using namespace std;

class execution
{
    friend class calculator;

private:
    stack <float> myStack;
    map <string, float> variables;
public:

    void clear_arg(string &arg);

    void make_new_parametrs(string &);

    void devision(string &);

    void multiple(string &);

    void plus(string &);

    void pop_from_stack(string &);

    void print_f(string &);

    void push_on(string &);

    void sqrt(string &);

    void sub(string &);
};

#endif //CALCULATOR_EXECUTION_H
