#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

string str_add(string a, string b){
    string ans = "";
    int size_a = a.size();
    int size_b = b.size();
    if(size_a == 0){
        return b;
    }
    if(size_b == 0){
        return a;
    }
    bool plus = false;
    for( int idx_a = size_a - 1, idx_b = size_b; idx_a--, idx_b--; idx_a >=0 || idx_b >= 0){
        char char_a = a[idx_a];
        char char_b = b[idx_b];
        int int_a = atoi(&char_a);
        int int_b = atoi(&char_b);

        int sum = int_a + int_b + plus;
        int cur = sum % 10;
        if(sum > 9)
            plus = true;
        else
            plus = false;
        ans.insert(0, itoa(cur));
    }
}

string multiply(string num1, string num2){

}

int main(int argc,char** argv){

    return 0;
}
