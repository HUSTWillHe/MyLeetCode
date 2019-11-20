#include <iostream>
#include <string>
using namespace std;
int myAtoi(string str){
    int MAX_INT = 0x7fffffff;
    int MIN_INT = 0x80000000;
    int size = str.size();
    bool get_num = false;
    bool negative = false;
    double rst = 0;
    for(int i = 0; i < size; i++){
        if(!get_num){
            if(str[i] >= '0' && str[i] <= '9'){
                get_num = true;
                rst = str[i] - '0';
                cout<<"rst: "<<rst<<endl;
            } else if(str[i] == '+' || str[i] == '-'){
                get_num = true;
                if(str[i] == '-')
                    negative = true;
            } else if(str[i] == ' '){
                continue;
            } else{
                return 0;
            }
        }else{
            if(str[i] >= '0' && str[i] <= '9'){
                int num = str[i] - '0';
                cout<<"num: "<<num<<endl;
                rst = rst * 10 + num;
                cout<<"rst: "<<rst<<endl;
            }else{
                break;
            }
        }
    }
    if(negative){
        rst = -rst;
    }
    if(rst > MAX_INT){
        return MAX_INT;
    }else if(rst < MIN_INT){
        return MIN_INT;
    }else {
        return (int)rst;
    }
}

int main(int, char** argv){
    string s(argv[1]);
    int i = myAtoi(s);
    cout<<"i: "<<i<<endl;
}
