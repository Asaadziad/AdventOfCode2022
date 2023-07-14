#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <string>

class Lexer {
    std::string input_buffer;
    std::vector<char> tokens;    
    size_t cursor;
    int cols;
    
    protected:
    void skipSpace(void);

    public:
    Lexer(std::string buffer);
    std::vector<char> getTokens();
    int getCols();
    
};

#endif