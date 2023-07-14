#include "lexer.h"

static bool colsCounted = false;
/*
* [N] - is a cell, N is value , [ ] are the bounds
*/
static char getCellValue(std::string cell){ // each cell consists of bounds and value
    return cell[1]; 
}

void Lexer::skipSpace(void){
    if(input_buffer[cursor] == ' ' || input_buffer[cursor] == '\n'){
        if(!colsCounted) colsCounted = (input_buffer[cursor] == '\n') ;
        cursor++;
    }
}


Lexer::Lexer(std::string buffer){
    input_buffer = buffer;
    cursor = 0;
    cols = 0;
    int cell_jump = 3;
    while(cursor < buffer.length()){
        char value = getCellValue(input_buffer.substr(cursor, cursor + cell_jump));

        tokens.push_back(value);

        cursor += cell_jump;
        if(!colsCounted) {
            cols++;
        }
        skipSpace();
        
    }
}

std::vector<char> Lexer::getTokens(){
    return this->tokens;
}

int Lexer::getCols(){
    return this->cols;
}