#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <stack>
#include <string>

#define MAP(x) ((x) - 'A')

class Matrix {
    std::vector<std::vector<char>> matrix;
    int cols;    
    public:
    Matrix(std::vector<char> tokens, int cols); // gets array of tokens and build up a matrix
    void applyAction(std::string action);
    std::string getTopCrates();
};

#endif