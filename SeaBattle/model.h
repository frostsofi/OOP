#ifndef SEABATTLE_GAME_STATE_H
#define SEABATTLE_GAME_STATE_H

#include "field.h"
#include "player.h"
#include <map>


using namespace std;

class game_model
{

private:
    multimap <int, int> cur_ship;
public:
    void make_move(player &, player &);
    bool ask_full_ship(int **,int,int,multimap<int, int>&, int **);
    void add_killed_ship(multimap <int, int> &);
    void check_full_ship(int **,int,int);
    int **update(multimap<int, int>, int **);
};

#endif //SEABATTLE_GAME_STATE_H
