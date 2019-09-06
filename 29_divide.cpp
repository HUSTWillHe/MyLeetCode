#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int MIN_INT = 0x80000000;
int MAX_INT = 0x7FFFFFFF;

int sub_div(int dividend, int divisor){
    if(dividend < divisor) return 0;
    int i = 0;
    while(i<32 && divisor<<i>0 && divisor<<i <= dividend){
        i++;
    }
    int ans = 0;
    if(i == 0) ans = 0;
    else ans = 1<<(i-1);
    return ans + sub_div(dividend - (divisor<<(i-1)), divisor);
}

int divide(int dividend, int divisor){
    if(dividend > MAX_INT || divisor > MAX_INT || dividend < MIN_INT || divisor < MIN_INT){
        return MAX_INT;
    }
    if(dividend == MIN_INT){
        if(divisor == 1) return MIN_INT;
        if(divisor == -1) return MAX_INT;
        if(divisor == MIN_INT) return 1;
        if(divisor < 0){
            int a = MIN_INT - divisor;
            return sub_div(-a, -divisor) + 1;
        }else{
            int a = MIN_INT + divisor;
            return -sub_div(-a, divisor) - 1;
        }
    }else if(divisor == MIN_INT){
        return 0;
    }
    if( dividend < 0){
        if(divisor < 0){
            return sub_div(-dividend, -divisor);
        }else{
            return -sub_div(-dividend, divisor);
        }
    }else{
        if(divisor < 0){
            return -sub_div(dividend, -divisor);
        }else{
            return sub_div(dividend, divisor);
        }
    }
}

int main(int argc,char** argv){
    int i = divide(10,3);
    cout<<"10,3: "<<i<<endl;
    return 0;
}
