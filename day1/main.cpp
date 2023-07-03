#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

void parseInput(std::string file_path, std::vector<int>* v);
void getMaxN(std::vector<int> v, int N, int* i_max_arr);

int main(){
    std::vector<int> arr;
    parseInput("input.txt", &arr);
    int max = arr.at(0);
    for(int i = 0; i < arr.size(); i++){
        if(max < arr.at(i)){
            max = arr.at(i);
        }
        
    }
    int max3[3] = {arr.at(0),arr.at(1),arr.at(2)};
    getMaxN(arr,3,max3);
    int total = 0;
    for(int i = 0 ; i < 3;i++){
        std::cout << std::to_string(max3[i]) << std::endl;
        total += max3[i];
    }
    std::cout << "total: "+ std::to_string(total) + "\n";
    
    return 0;
}

static int stringToInt(std::string string){
    if(string == "\n" || string == "") return 0;
    int tmp = 0;
    for(int i = 0; i < string.length(); i++){
        tmp *= 10;
        tmp += string.at(i) - '0';
    }
    return tmp;
}

void parseInput(std::string file_path, std::vector<int>* v){
    std::string buffer;
    std::fstream file(file_path);
    
    int current_sum = 0;
    while (getline (file, buffer)) {
        int buffer_int = stringToInt(buffer);
        if(buffer_int == 0) {
            v->push_back(current_sum);
            current_sum = 0;
        }
        current_sum += stringToInt(buffer);
    }
    v->push_back(current_sum);
    file.close(); 
}

void getMaxN(std::vector<int> v, int N, int* i_max_arr){
    for(int i =0 ; i < v.size();i++){
        if(v.at(i) >= i_max_arr[0]){
            int tmp = i_max_arr[0];
            int tmp2 = i_max_arr[1];
            i_max_arr[0] = v.at(i);
            i_max_arr[1] = tmp;
            i_max_arr[2] = tmp2;
        }
        else if(v.at(i) >= i_max_arr[1]){
            int tmp = i_max_arr[1];
            i_max_arr[1] = v.at(i);
            i_max_arr[2] = tmp;
        }
        else if(v.at(i) >= i_max_arr[2]){
            i_max_arr[2] = v.at(i);
        }
    }
}

