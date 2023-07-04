#include <iostream>
#include "Game.h"

int main(){
    Game game("elf","asaad", "input.txt");
    game.calculateScores();
    std::cout <<    std::to_string(game.getSecondPlayer().getScore());
    return 0;
}