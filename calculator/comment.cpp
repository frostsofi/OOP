#include "Factory.h"

class comment: public command
{
public:
    void execute(execution &myContext, string &arg) override
    {
        myContext.clear_arg(arg);
    }

 ~comment() override = default;
};

class CommentCommandCreator: public commandCreator
{
public:
    command *create() override
    {
        return new comment;
    }

 ~CommentCommandCreator() override = default;
};

namespace
{
    bool f()
    {
        string a = "#";
        commandFactory::getInstance().includeCommand(a, new CommentCommandCreator);
        return true;
    }

    bool fake = f();
}

