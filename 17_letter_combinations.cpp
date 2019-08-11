#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> vvs{
    {""},
    {""},
    {"a", "b", "c"},
    {"d", "e", "f"},
    {"g", "h", "i"},
    {"j", "k", "l"},
    {"m", "n", "o"},
    {"p", "q", "r", "s"},
    {"t", "u", "v"},
    {"w", "x", "y", "z"}
};

vector<string> mergeStrings(vector<string> a, vector<string> b){
    int a_size = a.size();
    int b_size = b.size();
    cout<<"a size: "<<a_size<<" b size: "<<b_size<<endl;
    vector<string> rst;
    for(int i = 0; i< a_size; i++){
        for(int k = 0; k < b_size; k++){
            rst.push_back(a[i] + b[k]);
        }
    }
    cout<<"merged size: "<<rst.size()<<endl;
    return rst;
}

vector<string> letterCombinations(string digits){
    int size = digits.size();
    vector<string> v;
    if(size == 0) return v;
    if(size == 1){
        int num = stoi(digits);
        v = vvs[num];
        return v;
    }
    v = vvs[stoi(digits.substr(0,1))];
    for(int i = 1; i < size; i++){
        int num = stoi(digits.substr(i,1));
        cout<<"num: "<<num<<endl;
        v = mergeStrings(v,vvs[num]);
    }
    return v;
}

int main(int argc,char** argv){
    vector<string> v = letterCombinations("234");
    for(auto a: v){
        cout<<a<<endl;
    }
    return 0;
}
