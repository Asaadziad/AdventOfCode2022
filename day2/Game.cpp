#include "Game.h"
#include <fstream> 
#include <string>
#include <iostream>

#define WIN_PTS 6
#define LOSE_PTS 0
#define TIE_PTS 3

#define ROCK_PTS 1

 Player Game::getSecondPlayer(){
    return this->second_player;
 }

void Game::calculateScores(){
    std::string buffer;
    std::fstream file(this->file_path);
    
    while (getline(file, buffer)) {
        this->checkRound(buffer);
    }
    file.close();
}

// returns the points earned for player2 move PLUS WIN/LOSE/DRAW
static int decryptMove(const char p1_move, const char encrypted_move){
    int edge;
    switch (encrypted_move)
    {
    case 'X': // LOSE SITUATION
    edge = (p1_move - 'A' + ROCK_PTS + 2 );
    return (edge > 3 ?  edge%3 : edge) + LOSE_PTS;
    break;
    case 'Y': // DRAW SITUATION
        return (p1_move - 'A' + ROCK_PTS) + TIE_PTS;
    break;
    case 'Z': // WIN SITUATION
    edge = ((p1_move - 'A' + ROCK_PTS + 1));
    return  (edge > 3 ? edge%3 : edge) + WIN_PTS;
    break;

    }
    return 0;
}

void Game::checkRound(std::string round){
    const char player1_move = round.at(0);
    const char player2_move = round.at(2);
    int player1_move_pts = player1_move - 'A' + ROCK_PTS;
    int player2_move_pts = decryptMove(player1_move, player2_move);
    this->first_player.setScore(this->first_player.getScore() + player1_move_pts);
    this->second_player.setScore(this->second_player.getScore() + player2_move_pts);

  /*  if(player1_move_pts == player2_move_pts){ return 0;
    std::cout << "TIED";}
    switch (player1_move)
    {
    case 'A': //ROCK 
        if(player2_move == 'Y') {return 2;} 
        else return 1;
    break;
    case 'B': //PAPER
        if(player2_move == 'Z') {return 2;}
        else return 1;
    break;
    case 'C': //SCISSORS
        if(player2_move == 'X') {return 2;}
        else return 1;
    break;
   
    }

    return 0;*/
}

