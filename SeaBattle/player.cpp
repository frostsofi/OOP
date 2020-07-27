#include "player.h"
#include <ctime>

int **random_player::return_field()
{
    return mine.arr;
}

void random_player::ship_installation()
{
mine.create_field();
srand(time(0));

string ship1 = "fourdeck";
string ship2 = "threedeck";
string ship3 = "twodeck";
string ship4 = "onedeck";

generate_place(ship1, 1);
generate_place(ship2, 2);
generate_place(ship3, 3);
generate_place(ship4, 4);

}

void random_player::generate_place(string &ship, int pos)
{

    for (int i = 0; i < pos; i++){

        int x = 0, y = 0;
        while (x == y) {
            x = rand() % 10;
            y = rand() % 10;
        }
        if (i%2 == 0) {
            if (! mine.put_ship(y, x, ship, 'v'))
                pos ++;
        }
        else
            if (! mine.put_ship(y, x, ship, 'h'))
                pos++;
    }
}

int *random_player::attack()
{
    int *arr = new int[2];
    arr[0] = rand()%10;
    arr[1] = rand()%10;
    return arr;
}

int random_player::return_count_ships()
{
    return count_ships;
}
multimap<int, int> &random_player::return_my_turns()
{
    return my_turns;
}

void random_player::count_ships_plus()
{
    count_ships++;
}

random_player::random_player()
{
    count_ships = 0;
}

int **optimal_player::return_field()
{
    return mine.arr;
}

void optimal_player::ship_installation()
{
    mine.create_field();

    string ship1 = "fourdeck";
    string ship2 = "threedeck";
    string ship3 = "twodeck";
    string ship4 = "onedeck";

    generate_place(ship1, 1);
    generate_place(ship2, 2);
    generate_place(ship3, 3);
    generate_place_boats(ship4);

}

void optimal_player::generate_place_boats(string &ship)
{   int pos = 4;

    for (int i = 0; i < pos; i++) {
        int y = rand()%10;
        int x = rand()%10;
        if (mine.put_ship(y, x, ship, 'v') == false)
            pos++;
    }

}

void optimal_player::generate_place(string &ship, int pos)
{
        int x, y, variant;

        for (int i = 0; i < pos; i++){
        variant = rand() % 4;
        switch(variant) {
            case (0): {
                y = 0;
                x = rand() % 10;
                if (mine.put_ship(y, x, ship, 'h') == false)
                    pos ++;
            }
                break;
            case (1): {
                y = 9;
                x = rand() % 10;
                if (mine.put_ship(y, x, ship, 'h') == false)
                    pos ++;
            }
                break;
            case (2):{
                x = 0;
                y = rand() % 10;
                if (mine.put_ship(y, x, ship, 'v') == false)
                    pos ++;

            }
                break;
            case (3):
            {
                x = 9;
                y = rand() % 10;
                if (mine.put_ship(y, x, ship, 'v') == false)
                    pos ++;
            }
                break;
        }
    }
}

int *optimal_player::attack()
{
    int *arr;

    arr = new int [2];
    if (last_killed_ship < count_ships) {
        make_conclusion();
        last_killed_ship = count_ships;
    }

    arr[0] = last_pos%10;
    arr[1] = last_pos/10;
    coordinates_ship = last_pos;

    if (state == 3) {
        arr[0] = rand()%10;
        arr[1] = rand()%10;
    }
    if (state == 1)
        make_new_pos1();
    if (state == 2)
        make_new_pos2();


    return arr;
}

optimal_player::optimal_player()
{
    last_pos = 0;
    count_ships = 0;
    last_killed_ship = 0;
    state = 1;
}

void optimal_player::make_new_pos1()
{
    if (last_pos != 99) {

        if (last_pos/10 == 9 && last_pos % 10 == 0)
            last_pos = 39;
        else {
            if (last_pos%10 == 0 && last_pos != 9 && last_pos/10 != 9)
                last_pos = last_pos / 10 + 3;
            else if (last_pos / 10 == 9 && last_pos %10 != 0 && last_pos != 9)
                last_pos = (last_pos % 10 + 3) * 10 + 9;
            else
                last_pos = (last_pos / 10 + 1) * 10 + (last_pos % 10 - 1);
        }
    }
    else {
        state = 2;
        last_pos = 1;
    }
}

void optimal_player::make_new_pos2()
{
    if (last_pos != 97) {
        if (last_pos == 70)
            last_pos = 19;
        else {
            if (last_pos%10 == 0 && last_pos != 9 && last_pos/10 != 9)
                last_pos = last_pos / 10 + 3;
            else if (last_pos / 10 == 9 && last_pos %10 != 0 && last_pos != 9)
                last_pos = (last_pos % 10 + 3) * 10 + 9;
            else
                last_pos = (last_pos / 10 + 1) * 10 + (last_pos % 10 - 1);
        }
    }
    else {
        state = 3;
        last_pos = 20;
    }
}

void optimal_player::make_conclusion()
{
    auto it = my_turns.find(mark::killed_ship);
    while ((it ->second/10 != coordinates_ship%10 && it ->second%10 != coordinates_ship/10) && it != my_turns.end())
            it++;

    while (it != my_turns.end())
    {
        if (it -> first%10 != 0)
        my_turns.insert(pair<int,int>(miss,it -> first/10*10+(it->second%10-1)));
        if (it -> first%10 != 9)
        my_turns.insert(pair<int,int>(miss,it->first/10*10+(it -> second%10 +1)));
        if (it -> first/10 != 9)
        my_turns.insert(pair<int,int>(miss,(it -> first/10 + 1)*10 + it -> second%10));
        if (it -> first/10 != 0)
        my_turns.insert(pair<int,int>(miss,(it -> first/10 - 1)*10+it->second%10));
        it++;
    }
}

multimap<int, int> &optimal_player::return_my_turns()
{
    return my_turns;
}
void optimal_player::count_ships_plus()
{
    last_killed_ship = count_ships;
     count_ships++;
}

int optimal_player::return_count_ships()
{
    return count_ships;
}

real_player::real_player()
{
    count_ships = 0;
}
int **real_player::return_field()
{
   return mine.arr;
}

void real_player::ship_installation()
{
    mine.create_field();

    string ship1 = "fourdeck";
    string ship2 = "threedeck";
    string ship3 = "twodeck";
    string ship4 = "onedeck";
    cout << "please, type location of ship in format: 'x' 'y' 'location' (location can be 'v' or 'h')" << endl;
    cout << "you should write it for ships from fourdeck to onedeck" << endl;
    generate_place(ship1, 1);
    generate_place(ship2, 2);
    generate_place(ship3, 3);
    generate_place(ship4, 4);
}

void real_player::generate_place(string &ship, int pos)
{
    for (int i = 0; i < pos; i++)
    {
        cout << ship << endl;
        int x = 0, y = 0;
        char location = 'v';
        cin >> x >> y >> location;

        if (!mine.put_ship(y, x, ship, location)) {
            cout << "please, try again" << endl;
            pos ++;
        }
    }
}

int *real_player::attack()
{
    int *arr = new int[2];
    cout << "your turn, type 'x', 'y' " << endl;
    cin >> arr[1] >> arr[0];
    return arr;
}

int real_player::return_count_ships()
{
    return count_ships;
}

multimap<int, int> &real_player::return_my_turns()
{
    return my_turns;
}

void real_player:: count_ships_plus()
{
     count_ships++;
}