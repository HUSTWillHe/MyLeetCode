#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs){
    int ret = 0;
    while(1){
        for(auto s: strs){
            cout<<"ret: "<<ret<<" s[ret]: "<<s[ret]<<" strs[0][ret]: " << strs[0][ret]<< endl;
            if(ret == s.size() || s[ret] != strs[0][ret]){
                return s.substr(0, ret);
            }
        }
        ret++;
    }
    return strs[0].substr(0, ret);
}

int main(){
    vector<string> strs = {"flower", "flow", "flight"};
    string s = longestCommonPrefix(strs);
    cout<<s<<endl;
    strs = {"lower", "flow", "flight"};
    s = longestCommonPrefix(strs);
    cout<<s<<endl;
}
