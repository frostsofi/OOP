#include "model.h"

void game_model::make_move(player &me, player &opponent) {
    int *arr;
    int turn = 0, result = 0;
    arr = me.attack();
    int **arr_2 = update(me.return_my_turns(),opponent.return_field());

    while (turn != 1) {

            if (arr_2[arr[0]][arr[1]] == miss || arr_2[arr[0]][arr[1]] == crash || arr_2[arr[0]][arr[1]] == killed_ship)
                arr = me.attack();

            if (arr_2[arr[0]][arr[1]] == deck) {
                if (ask_full_ship(arr_2, arr[0], arr[1], me.return_my_turns(), opponent.return_field())) {
                    result = killed_ship;
                    me.count_ships_plus();
                }
                else
                    result = crash;
                turn ++;
            }

        if (arr_2[arr[0]][arr[1]] == empty) {
            result = miss;
            turn ++;
        }
    }

    if (result != killed_ship)
       me.return_my_turns().insert(pair<int,int>(result, arr[0]*10 + arr[1]));
    delete(arr_2);
    delete(arr);
}

int **game_model::update(multimap<int, int> turns, int **arr)
{
    int **arr_copy;
    arr_copy = new int*[10];
    for (int count = 0; count < 10; count++)
        arr_copy[count] = new int[10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            arr_copy[i][j] = arr[i][j];
    }
    auto cur = turns.begin();

    while  (cur != turns.end())
    {
        arr_copy[cur -> second/10][cur -> second%10] = cur -> first;
        cur++;
    }
    return arr_copy;
}

bool game_model::ask_full_ship(int **arr, int y, int x, multimap <int, int> &turns, int **arr_op)
{
    int size_ship = 1;
    int check_x = x + 1;
    int check_y = y + 1;

    while (check_x != 10 && arr[y][check_x] == crash){
        size_ship++;
        check_x ++;
     }
       check_x = x - 1;

    while (check_x != -1 && arr[y][check_x] == crash){
        size_ship++;
        check_x--;
    }

        while (check_y != 10 && arr[check_y][x] == crash) {
            size_ship ++;
            check_y ++;
        }

    check_y = y - 1;

        while (check_y != -1 && arr[check_y][x] == crash) {
            size_ship ++;
            check_y --;
    }

    check_full_ship(arr_op, y, x);
    if (size_ship < cur_ship.size() + 1) {
        cur_ship.clear();
        return false;
    }
    turns.insert(pair<int,int>(killed_ship, y*10 + x));
    add_killed_ship(turns);
    cur_ship.clear();
    return true;
}

void game_model::add_killed_ship(multimap <int, int> &turns)
{
    auto cur = cur_ship.begin();
    auto cur2 = turns.find(crash);
    while (cur != cur_ship.end())
    {cur2 = turns.find(crash);
        while (cur2 != turns.end() && cur2 -> first != killed_ship)
        {
            if (cur2 -> second/10 == cur -> first && cur2 -> second%10 == cur -> second)
                turns.insert(pair<int,int>(killed_ship, cur2 -> second));
            cur2++;
        }
        cur++;
    }
}

void game_model::check_full_ship(int **arr, int y, int x)
{
    int check_x = x + 1;
    int check_y = y + 1;

    while (check_x != 10 && arr[y][check_x] == deck)
    {
        cur_ship.insert(pair<int,int> (y, check_x));
        check_x ++;
    }

    check_x = x - 1;

    while (check_x != -1 && arr[y][check_x] == deck)
    {
        cur_ship.insert(pair<int, int> (y, check_x));
        check_x--;
    }

        while (check_y != 10 && arr[check_y][x] == deck)
        {
            cur_ship.insert(pair<int, int>(check_y, x));
            check_y ++;
        }

    check_y = y - 1;

        while (check_y != -1 && arr[check_y][x] == deck)
        {
            cur_ship.insert(pair<int, int>(check_y, x));
            check_y --;
        }
    }






