#include "calculator.h"

void calculator::sort(string &myLine) {
    int i = 0, j = 0;
    command *cur;
    string command;
    string argument;

    for (i = 0; myLine[i] != ' ' && myLine[i] != '\0'; i++)
        command.push_back(myLine[i]);

    for (j = i + 1; myLine[j] != '\0'; j++)
        argument.push_back(myLine[j]);

    try {
        if (commandFactory::getInstance().commands.find(command) != commandFactory::getInstance().commands.end()) {
            cur =  commandFactory::getInstance().commands[command]->create();
            cur -> execute(myContext, argument);
            delete cur;
        }
        else
            throw exception();
    }
    catch(exception &ex)
    {
        cout << "command not found " << endl;
    }
}

void calculator::treatment()
{
    string myLine;
    while (getline(cin, myLine, '\n'))
    {
        sort(myLine);
        myLine.clear();
    }
}


