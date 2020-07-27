#ifndef SEABATTLE_FIELD_H
#define SEABATTLE_FIELD_H


#include <iostream>
#include <map>

#define all 10

enum mark {empty, deck, miss, crash, killed_ship};

using namespace std;
class field
{
private:
    map <string, int> ships;
    int **arr;

public:
    field();
    ~field();
    friend class random_player;
    friend class optimal_player;
    friend class real_player;
    void create_field();
    int ** get_field() {return arr;}

    bool put_ship(int, int, string &, char);
    bool check_no_ships(int,int,int, char);
};

#endif //SEABATTLE_FIELD_H
