#ifndef SEABATTLE_PLAYER_H
#define SEABATTLE_PLAYER_H

//#include "game_process.h"
#include "field.h"

using namespace std;

class player{

public:
    virtual int**return_field() = 0;
    virtual void ship_installation() = 0;
    virtual int *attack() = 0;
    virtual ~player() = default;
    virtual int return_count_ships() = 0;
    virtual multimap<int, int> &return_my_turns() = 0;
    virtual void count_ships_plus() = 0;
};

class random_player : public player
{
private:
    field mine;
    int count_ships;
    multimap <int,int> my_turns;
public:
    random_player();
    int **return_field() override;
    int return_count_ships() override;
    multimap<int, int> &return_my_turns() override;
    void ship_installation() override;
    int *attack() override;
    void generate_place(string &,int);
    void count_ships_plus() override;
};

class optimal_player : public player
{
private:
    field mine;
    int count_ships;
    int last_killed_ship;
    int last_pos;
    int state;
    int coordinates_ship;
    multimap <int,int> my_turns;
public:
    optimal_player();
    void make_new_pos1();
    void make_new_pos2();
    void make_conclusion();
    void generate_place(string &,int);
    void generate_place_boats(string &);
    int **return_field() override;
    void ship_installation() override;
    int *attack() override;
    int return_count_ships() override;
    multimap<int, int> &return_my_turns() override;
    void count_ships_plus() override;
};

class real_player : public player
{
private:
    field mine;
    int count_ships;
    multimap <int,int> my_turns;
public:
    real_player();
    void generate_place(string &,int);
    int **return_field() override;
    void ship_installation() override;
    int *attack() override;
    int return_count_ships() override;
    multimap<int, int> &return_my_turns() override;
    void count_ships_plus() override;
};




#endif //SEABATTLE_PLAYER_H
