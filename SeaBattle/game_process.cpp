#include "game_process.h"
enum  optionIndex {COUNT, FIRST, SECOND};

bool game_process::game_end(player &first, player &second) {
    if (first.return_count_ships() == all){
        cout << "first wins" << endl;
        return false;
}
    if (second.return_count_ships() == all) {
        cout << "second wins" << endl;
        return false;
    }
    return true;
}

void game_process::game(player &first, player &second)
{


    int count = 0;
    first.ship_installation();
    second.ship_installation();
       while (game_end(first, second) != false)
       {
           if (count % 2 == 0) {
               screen.watch_mine(first, second.return_my_turns());
               screen.watch_opponent(second, first.return_my_turns());
               status.make_move(first, second);
           }
           else {
               screen.watch_mine(second, first.return_my_turns());
               screen.watch_opponent(first, second.return_my_turns());
               status.make_move(second, first);
           }
           count++;
       }
}

game_process:: game_process(option::Option* opt)
{
    for (int i = 0; i < opt[COUNT].arg[0]; i ++) {
        player *first = return_type(opt[FIRST].arg[0]);
        player *second = return_type(opt[SECOND].arg[0]);
        game(*first, *second);
        delete (first);
        delete (second);
    }
};
player *game_process::return_type(char type)
{
    if (type == 'r' )
            return new random_player;
    if (type == 'o')
           return new optimal_player;
    if (type == 'u')
        return new real_player;

}



