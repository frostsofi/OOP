#include "view.h"

#include <utility>

void view::watch_opponent(player &opponent, multimap<int, int> my_turns)
{
    int **arr = update(std::move(my_turns), opponent.return_field());

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++){
            if (arr[i][j] == mark::deck)
                cout << " " << "| ";
            if (arr[i][j] == crash)
                cout << "*" << "| ";
            if (arr[i][j] == empty)
                cout << " " << "| ";
            if (arr[i][j] == miss)
                    cout << "O" << "| ";
            if (arr[i][j] == killed_ship)
                cout << "X" << "| ";
            }
        cout << endl;
        cout << " _______________________________________" << endl;
    }
    cout << "opponent" << endl;
    cout << endl << endl << endl;
    delete arr;
}

void view::watch_mine(player &gamer, multimap<int, int> turns_opponent)
{
    int **arr = update(turns_opponent, gamer.return_field());

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++){
            if (arr[i][j] == mark::deck)
                cout << "#" << "| ";
            if (arr[i][j] == crash)
                cout << "X" << "| ";
            if (arr[i][j] == empty)
                cout << " " << "| ";
            if (arr[i][j] == miss)
                cout << "O" << "| ";
        }
        cout << endl;
        cout << " _______________________________________" << endl;
    }
    cout << "mine" << endl;
    cout << endl << endl << endl;
}

int **view::update(multimap<int, int> turns, int **arr)
{
    int **arr_copy;
    arr_copy = new int* [10];
    for (int count = 0; count < 10; count++)
        arr_copy[count] = new int[10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            arr_copy[i][j] = arr[i][j];
    }
    auto cur = turns.begin();
    while(cur != turns.end())
    {
        arr_copy[cur -> second/10][cur -> second%10] = cur -> first;
        cur++;
    }
    return arr_copy;
}