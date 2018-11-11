#include <string>
#include "Factory.h"
#include "execution.h"

using namespace std;

class dev: public command
{
public:

    void execute(execution &myContext, string &arg) {
        try {
            myContext.devision(arg);
        }
        catch (exception &ex)
        {
            cout << "devision by zero " << endl;
        }
    }

    ~dev() override = default;
};

class DevCommandCreator: public commandCreator
{
public:
    command *create()
    {
        return new dev;
    }
    ~DevCommandCreator() override = default;
};

namespace
{
    bool f()
    {
        string a = "/";
        commandFactory::getInstance().includeCommand(a, new DevCommandCreator);
        return true;
    }

    bool fake = f();
}



