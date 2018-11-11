#include "Factory.h"
#include "execution.h"


class pluss: public command
{
public:
    void execute(execution &myContext, string &arg) override {
        myContext.plus(arg);
    }
    ~pluss() override = default;
};

class PlusCommandCreator: public commandCreator
{
public:
    command *create() override {
        return new pluss;
    }
    ~PlusCommandCreator() override = default;
};

namespace
{
    bool f()
    {
        string a = "+";
        commandFactory::getInstance().includeCommand(a, new PlusCommandCreator);
        return true;
    }

    bool fake = f();
}





