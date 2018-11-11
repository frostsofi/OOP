#include "Factory.h"

using namespace std;

class sub: public command
{
public:
    void execute(execution &myContext, string &arg) override {
        myContext.sub(arg);
    }
    ~sub() override = default;
};

class SubCommandCreator: public commandCreator
{
public:
    command *create() override {
        return new sub;
    }

    ~SubCommandCreator() override = default;

};

namespace
{
    bool f()
    {
        string a = "-";
        commandFactory::getInstance().includeCommand(a, new SubCommandCreator);
        return true;
    }

    bool fake = f();
}

