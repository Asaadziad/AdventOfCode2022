#include <iostream>
#include <fstream>
#include <string>

#include "pair.h"

int main(){
    std::fstream file("input.text");
    std::string buffer;
    int overlaped_cnt = 0;
    while(getline(file,buffer)){
        Pair p(buffer);
        if(p.isSectionParlyOverlaped()) overlaped_cnt++;
        
    }
    std::cout << overlaped_cnt << std::endl;
    file.close();
    return 0;
}