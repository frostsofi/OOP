#include "Factory.h"

class pop: public command
{
public:
    void execute(execution &myContext, string &arg) override {
        try {
            myContext.pop_from_stack(arg);
        }
        catch(exception &ex)
        {
            cout << "stack is empty, can't pop value" << endl;
        }
    }

    ~pop() override = default;
};

class PopCommandCreator: public commandCreator
{
public:
    command *create() override {
        return new pop;
    }
    ~PopCommandCreator() override = default;

};

namespace
{
    bool f()
    {
        string a = "POP";
        commandFactory::getInstance().includeCommand(a, new PopCommandCreator);
        return true;
    }

    bool fake = f();
}




