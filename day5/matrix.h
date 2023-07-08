#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <stack>
#include <string>

#define MAP(x) ((x) - 'A')

class Matrix {
    std::vector<std::stack<int>> matrix;    
    public:
    Matrix(std::string matrix);
    void applyAction(std::string action);
    std::string getTopCrates();
};

#endif