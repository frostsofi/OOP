//
// Created by frost on 03.11.2018.
//
#include "Factory.h"

commandFactory::~commandFactory()
{
    auto it = commands.begin();
    while (it != commands.end()) {
        delete it -> second;
        it ++;
    }
}

void commandFactory::includeCommand(string &name, commandCreator *Creator)
{
    auto it = commands.find(name);
    if (it != commands.end()) {
        if (it -> second == Creator)
            return;
        delete it -> second;
    }
    commands[name] = Creator;
}

