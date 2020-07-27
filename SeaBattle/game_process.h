#ifndef SEABATTLE_GAME_PROCESS_H
#define SEABATTLE_GAME_PROCESS_H
#include "parcer/optionparser-1.7/src/optionparser.h"

#include <iostream>
#include <map>
#include <string>
#include "player.h"
#include "model.h"
#include "view.h"

using namespace std;

class game_process
{
private:
    game_model status;
    view screen;
public:
    game_process(option::Option*);
    void game(player &first, player &second);
    bool game_end(player &, player &);
    player *return_type(char);
};

#endif //SEABATTLE_GAME_PROCESS_H
