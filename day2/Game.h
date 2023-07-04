#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <string>

class Game {
    const char* file_path;
    Player first_player;
    Player second_player;
    public:
    Game(const char* player1,const char* player2, const char* file_path):file_path(file_path),
    first_player(Player(player1)),
    second_player(Player(player2)){};
    Player getSecondPlayer();
    void calculateScores();
    /*
    * RETURNS: 0 - its a TIE ,
    *          1 - first player won,
    *          2 - second player won
    */
    void checkRound(std::string round);
};

#endif