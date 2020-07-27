#include "field.h"

void field::create_field()
{
    arr = new int* [10];
    for (int count = 0; count < 10; count++)
        arr[count] = new int[10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            arr[i][j] = 0;
    }
}

bool field::put_ship(int y, int x, string &shipName, char location)
{
        int deck = ships[shipName];
        if (!check_no_ships(y, x, deck, location))
            return false;
        if (location == 'v')
        {
            for (int i = 0; i < deck; i++)
                arr[y + i][x] = mark::deck;
        }
        if (location == 'h'){
            for (int i = 0; i < deck; i++)
                arr[y][x + i] = mark::deck;

        }
    return true;
}

bool field::check_no_ships(int y, int x, int deck, char location)
{   int wall1 = 3;
    int wall2 = deck + 1;

    if (location == 'h' &&(x + wall2 - 2== 9 || x == 0))
        wall2--;

    if (location == 'v' &&(y + wall2 -2 == 9 || y == 0))
        wall2--;

    if (location == 'v' && (x == 9 || x == 0))
       wall1--;
    if (location == 'h' && (y == 9 || y == 0))
        wall1--;
    if (x != 0)
        x -= 1;
    if (y != 0)
        y -= 1;
    if (location == 'v')
    {
        for (int i = 0; i <= wall2; i++)
        {
            for (int j = 0; j < wall1; j ++) {
                if ((x + j > 9) || ((y + i) > 9) || arr[y + i][x  + j] == mark::deck)
                    return false;
            }
        }
    }

    if (location == 'h') {
        for (int i = 0; i < wall1; i ++) {
            for (int j = 0; j <= wall2; j++) {
                if ((x + j > 9) || ((y + i) > 9) || arr[y + i][x + j] == mark::deck)
                    return false;
            }
        }
    }
    return true;
}


field:: field()
{
    ships = {{"fourdeck", 4}, {"threedeck", 3}, {"twodeck", 2}, {"onedeck", 1}};
}

field::~field()
{
    delete (arr);
}
