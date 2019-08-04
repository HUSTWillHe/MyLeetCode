#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs){
    int ret = 0;
    int size = strs.size();
    if(size == 0) return "";
    if(size == 1) return strs[0];
    vector<int> s_size;
    for(int i = 0; i< size;i++){
        s_size.push_back(strs[i].size());
    }
    while(1){
        for(int i = 1; i < size ;i++){
            if(ret >= s_size[i] || strs[i][ret] != strs[0][ret]){
                return strs[i].substr(0, ret);
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
    strs = {};
    s = longestCommonPrefix(strs);
    cout<<s<<endl;
}
