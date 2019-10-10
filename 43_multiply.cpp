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
        cout<<"-----------------new round-------------------"<<endl;
        int int_a = 0;
        if(idx_a >= 0)
            int_a = a[idx_a] - '0';
        int int_b = 0;
        if(idx_b >= 0)
            int_b = b[idx_b] - '0';
        cout<<"current a is: "<<int_a<<endl;
        cout<<"current b is: "<<int_b<<endl;
        int sum = int_a + int_b + plus;
        int cur = sum % 10;
        if(sum > 9)
            plus = true;
        else
            plus = false;
        ans.push_back('0' + cur);
        cout<<"current ans is: "<<cur<<endl;
        cout<<"current plus is: "<<plus<<endl;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string multiply(string num1, string num2){
    return "";
}

int main(int argc,char** argv){
    string a = "123000";
    string b = "321";
    string c = str_add(a,b);
    cout<<"the add result is: "<<c<<endl;
    return 0;
}
