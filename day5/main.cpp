#include <iostream>
#include <fstream>
#include <string>
#include "matrix.h"

static bool strIncludes(std::string str, char s){
    for(int i = 0;i < str.size();i++){
        if(str.at(i) == s) return true;
    }
    return false;
}

int main(){
    std::fstream file("fakeput.txt");
    std::string buffer;
    std::string matrix;

    while(getline(file,buffer)){
        matrix.append(buffer);
        if(strIncludes(matrix, '1')) break;
    }
    
    Matrix m(matrix);

    while(getline(file,buffer)){
        m.applyAction(buffer);
    }

    //std::cout << m.getTopCrates();
    
    file.close();
    return 0;
}