#include "Factory.h"
#include <cmath>

using namespace std;

class Sqrt : public command {
public:
    void execute(execution &myContext, string &arg) override {
        try {
            myContext.sqrt(arg);
        }
        catch (exception &ex)
        {
            cout << "can't extract a root from a negative number" << endl;
        }
    }

    ~Sqrt() override = default;
};

class SqrtCommandCreator: public commandCreator
{
public:
    command *create() override {
        return new Sqrt;
    }

    ~SqrtCommandCreator() override = default;
};

namespace
{
    bool f()
    {
        string a = "SQRT";
        commandFactory::getInstance().includeCommand(a, new SqrtCommandCreator);
        return true;
    }

    bool fake = f();
}
