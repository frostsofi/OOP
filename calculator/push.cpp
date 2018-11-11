#include <string>
#include "Factory.h"
#include "execution.h"

using namespace std;

class push: public command
{
public:
    void execute(execution &myContext, string &arg) override {
        try {
            myContext.push_on(arg);
        }
        catch (exception &ex) {
            cout << "wrong arguments for push" << endl;
        }
    }

    ~push() override = default;
};


class PushCommandCreator: public commandCreator
{
public:
    command *create() override {
        return new push;
    }

    ~PushCommandCreator() override = default;
};

namespace
{
    bool f() {
        string a = "PUSH";
        commandFactory::getInstance().includeCommand(a, new PushCommandCreator);
        return true;
    }
    bool fake = f();

}




