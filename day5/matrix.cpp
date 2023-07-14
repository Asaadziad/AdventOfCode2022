#include "matrix.h"
#include <iostream>

static void printMatrix(std::vector<std::vector<char>> matrix){
    for(int i = 0;i < matrix.size();i++){
        for(int j = 0; j < matrix.at(i).size() ;j++){
            std::cout << matrix.at(i).at(j);
        }
        std::cout << "\n";
    }
}

Matrix::Matrix(std::vector<char> tokens,int cols){
   int tokens_size = tokens.size();
   int i = tokens.size() - 1;
   for(int j = 0;j < cols;j++){std::vector<char> tmp; matrix.push_back(tmp);}
   while(i >= 0){
    for(int j = cols - 1; j >= 0; j--){
        if(!(tokens.at(i) == ' ')){
            matrix.at(j).push_back(tokens.at(i));
        }
        i--;
    }
    
   }
}

void Matrix::applyAction(std::string action){
    if(action == "" || action == " ") return;
    int n_chars = action[action.find("move") + 5] - '0';
    int i_col = action[action.find("from") + 5] - '0' - 1;
    int target_col = action.at(action.find("to") + 3) - '0' - 1;

    for(int i = 0; i < n_chars;i++){  
        matrix.at(target_col).push_back(matrix.at(i_col).back());
        matrix.at(i_col).pop_back();
    }
    printMatrix(matrix);

}

std::string Matrix::getTopCrates(){
    std::string buffer;
    for(int i = 0; i < matrix.size() ; i++){
        
            buffer += (matrix.at(i).back());
        
    }
    return buffer;
}

