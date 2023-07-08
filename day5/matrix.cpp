#include "matrix.h"
#include <iostream>

Matrix::Matrix(std::string matrix){
   std::cout << matrix;
}

void Matrix::applyAction(std::string action){
    if(action == "" || action == " ") return;
    
}