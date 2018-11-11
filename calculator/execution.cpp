#include "execution.h"

void execution::make_new_parametrs(string &arg)
{
    int j, dot_pos = 1, end_numb = 0;
    float numb = 0;
    string parametr;
       for (j = 0; !(parametr.empty()) || (arg[j] != '\0'); j++)
       {
            if (arg[j] != ' ')
            {
                if (arg[j] >= '0' && arg[j] <= '9')
                {
                    numb = numb * 10 + (arg[j] - '0');
                    end_numb ++;
                }
                else
                   if (arg[j] == '.' || arg[j] == ',')
                      dot_pos = end_numb;
                   else
                       if (arg[j] >= 'A' && arg[j] <= 'z')
                      parametr.push_back(arg[j]);
            }
            else
            {
                if (parametr.empty())
                    throw exception();
                else
                   if (end_numb != 0)
                   {
                    numb /= std::pow(10, end_numb - dot_pos);
                    variables.insert(pair<string, float>(parametr, numb));
                    dot_pos = end_numb = numb = 0;
                    parametr.clear();
                    if (arg[j - 1] == '\0')
                        j =- 2;
                    }
            }
       }
}

void execution::clear_arg(string &arg)
{
    arg.clear();
}

void execution::devision(string &arg) {
    float a, b;
    a = myStack.top();
    myStack.pop();
    b = myStack.top();
    myStack.pop();
        if (a != 0)
            myStack.push(b / a);
        else
            throw exception();
}

void execution::multiple(string &arg) {
    float a, b;
    a = myStack.top();
    myStack.pop();
    b = myStack.top();
    myStack.pop();
    myStack.push(a * b);
}

void execution::plus(string &arg) {
    float a, b;
    a = myStack.top();
    myStack.pop();
    b = myStack.top();
    myStack.pop();
    myStack.push(a + b);
}

void execution::pop_from_stack(string &arg) {
        if (! myStack.empty())
            myStack.pop();
        else
            throw exception();
}

void execution::print_f(string &arg)
{
    cout << myStack.top() << endl;
}

void execution::push_on(string &arg) {
    int j, dot_pos = 1, end_numb;
    end_numb = 0;
    float numb = 0;
    string parametr;

    for(j = 0;   !(parametr.empty()) || arg[j] != '\0'; j++) {
        if (arg[j] != ' ' && arg[j] != '\0')
        {
            if (arg[j] >= '0' && arg[j] <= '9')
            {
                numb = numb * 10 + (arg[j] - '0');
                end_numb ++;
            }
            else
                if (arg[j] == '.' || arg[j] == ',')
                       dot_pos = end_numb;
                else
                    parametr.push_back(arg[j]);
        } else
            if (parametr.empty()) {
                 numb /= std::pow(10, end_numb - dot_pos);
                 myStack.push(numb);
                 numb = end_numb = 0;
            } else {
                auto it = variables.find(parametr);
                    if (it != variables.end()) {
                       myStack.push(variables[parametr]);
                       parametr.clear();
                } else
                    throw exception();
        }

    }

}

void execution::sqrt(string &arg) {
    float a;
        a = myStack.top();
        if (a < 0)
            throw exception();
        myStack.pop();
        myStack.push(std::sqrt((a)));


}

void execution::sub(string &arg) {
    float a,b;
    a = myStack.top();
    myStack.pop();
    b = myStack.top();
    myStack.pop();
    myStack.push(b - a);
}