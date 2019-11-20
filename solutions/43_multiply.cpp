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
    for( int idx_a = size_a - 1, idx_b = size_b - 1; idx_a >=0 || idx_b >= 0; idx_a--, idx_b--){
        int int_a = 0;
        if(idx_a >= 0)
            int_a = a[idx_a] - '0';
        int int_b = 0;
        if(idx_b >= 0)
            int_b = b[idx_b] - '0';
        int sum = int_a + int_b + plus;
        int cur = sum % 10;
        if(sum > 9)
            plus = true;
        else
            plus = false;
        ans.push_back('0' + cur);
    }
    if(plus)
        ans.push_back('1');
    reverse(ans.begin(), ans.end());
    return ans;
}

string single_multiply(char c, string num){
    int int_c = c - '0';
    int plus = 0;
    string ans = "";
    for(int i = num.size() - 1; i >= 0; i--){
        int int_n = num[i] - '0';
        int mul = int_c * int_n + plus;
        plus = mul / 10;
        int cur = mul % 10;
        ans.push_back('0' + cur);
    }
    if(plus != 0)
        ans.push_back('0' + plus);
    reverse(ans.begin(), ans.end());
    return ans;
}

string multiply(string num1, string num2){
    if(num1 == "0" || num2 == "0")
        return "0";
    string ans = "0";
    for(int i = num1.size()-1; i >= 0; i--){
        char c = num1[i];
        string cur_ans = single_multiply(c, num2);
        string zeros(num1.size() - 1 -i, '0');
        cur_ans += zeros;
        ans = str_add(ans, cur_ans);
    }
    return ans;
}

int main(int argc,char** argv){
    //string ans = str_add("0", "0");
    string ans = multiply("99","9");
    return 0;
}
