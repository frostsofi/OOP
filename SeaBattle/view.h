//
// Created by frost on 30.11.2018.
//

#ifndef SEABATTLE_VIEW_H
#define SEABATTLE_VIEW_H

#include "player.h"

class view {
public:
    int **update(multimap<int, int>,int**);
    void watch_opponent(player &, multimap<int, int>);
    void watch_mine(player &, multimap<int, int>);
};
#endif //SEABATTLE_VIEW_H
