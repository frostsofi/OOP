#include "Factory.h"

class mult: public command
{
public:
    void execute(execution &myContext, string &arg) override {
        myContext.multiple(arg);
    }
    ~mult() override = default;
};

class MultCommandCreator: public commandCreator
{
public:
    command *create() override {
        return new mult;
    }
    ~MultCommandCreator() override = default;
};

namespace
{
    bool f()
    {
        string a = "*";
        commandFactory::getInstance().includeCommand(a, new MultCommandCreator);
        return true;
    }

    bool fake = f();
}