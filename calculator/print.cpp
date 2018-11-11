#include "Factory.h"

using namespace std;

class print: public command
{
public:
    void execute(execution &myContext, string &arg) override {

        myContext.print_f(arg);

    }
    ~print() override = default;
};

class PrintCommandCreator: public commandCreator
{
public:
    command *create() override {
        return new print;
    }
    ~PrintCommandCreator() override = default;
};

namespace
{
    bool f()
    {
        string a = "PRINT";
        commandFactory::getInstance().includeCommand(a, new PrintCommandCreator);
        return true;
    }

    bool fake = f();
}




