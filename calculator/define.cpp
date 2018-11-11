#include "Factory.h"

using namespace std;

class define: public command
{
public:
    void execute(execution &myContext, string &arg) {
        try {
            myContext.make_new_parametrs(arg);
        }
        catch (exception &ex)
        {
            cout << "wrong arguments for define" << endl;
        }
    }
    ~define() override = default;
};

class DefineCommandCreator: public commandCreator
{
public:
    command *create() {
        return new define;
    }
    ~DefineCommandCreator() override = default;
};


namespace
{
    bool f()
    {
        string a = "DEFINE";
        commandFactory::getInstance().includeCommand(a, new DefineCommandCreator);
        return true;
    }

    bool fake = f();
}



