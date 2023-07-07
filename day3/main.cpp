#include <iostream>
#include <fstream>
#include <string>
#include "group.h"


int main(){
    std::fstream file("input.txt");
    std::string buffer;
    int sum = 0;
    int j = 0;
    Group group;
    while (getline(file,buffer))
    {
        rucksack r(buffer);
        if(j == 3){
            
            sum += group.getBadge();
            j = 0;
            group = Group();
            
        }
        group.addRuckSack(r);
        j++;
        
    }
    sum += group.getBadge();
    std::cout << std::to_string(sum);
    return 0;
}

