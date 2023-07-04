#ifndef PLAYER_H
#define PLAYER_H

class Player {
    const char* name;
    int score;
    public:
    Player(const char* name, int score = 0): name(name), score(score){}
    int getScore();
    void setScore(int score);
};

#endif