#include <iostream>
#include <string>
#include <algorithm>

int reverse(int x){
    int MAX_INT = 0x7fffffff;
    int MIN_INT = 0x80000000;
    //std::cout<<"max: "<<MAX_INT<<" min: "<<MIN_INT<<std::endl;
    std::string s = std::to_string(x);
    //std::cout<<"s: "<<s<<std::endl;
    bool minus = false;

    if(s[0] == '-'){
        minus = true;
        std::reverse(s.begin()+1, s.end());
        //std::cout<<"s is minus, sub: "<<s<<std::endl;

    }else{
        std::reverse(s.begin(), s.end());
        //std::cout<<"s in zheng reverse is: "<<s<<std::endl;
    }
    double d = stod(s);
    if(d > MAX_INT || d < MIN_INT){
        //std::cout<<"over, d is: "<<d<<std::endl;
        return 0;
    }
    int i = stoi(s);
    return i;
}

int main(int argc, char** argv){
    for(int i = 1; i < argc; i++){
        int k = atoi(argv[i]);
        int j = reverse(k);
        std::cout<<"ans: "<<j<<std::endl;
    }
    return 0;
}
