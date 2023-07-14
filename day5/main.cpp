#include <iostream>
#include <fstream>
#include <string>
#include "matrix.h"
#include "lexer.h"
#include <vector>
#include <thread>

static bool strIncludes(std::string str, char s){ // str is Cells each cell is 3 tags
    
    for(int i = 0;i < str.size();i++){
        if(str.at(i) == s) return true;
    }
    return false;
}


int main(){
    std::fstream file("input.txt");
    std::string buffer;
    std::string i_buffer;

    while(getline(file,buffer)){
        if(strIncludes(buffer, '1')) break;
        i_buffer.append(buffer + '\n');
    }
    Lexer lex(i_buffer);
    
    std::vector<char> tokens = lex.getTokens();
    int cols = lex.getCols();

    Matrix m(tokens, cols);
    
    while(getline(file,buffer)){
        m.applyAction(buffer);
    }
    
    std::cout << m.getTopCrates();
    
    file.close();
    return 0;
}