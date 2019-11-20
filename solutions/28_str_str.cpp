#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int strStr(string haystack, string needle){
    if(haystack.size()==0){
        if(needle.size()==0)
            return 0;
        else
            return -1;
    }
    int end_idx = haystack.size() - needle.size();
    if(end_idx < 0) return -1;
    for(int i = 0; i <= end_idx; i++){
        if(haystack.substr(i,needle.size())==needle) return i;
    }
    return -1;
}

int main(int argc,char** argv){
    string he="aaa";
    string li="aaaa";
    int i = strStr(he,li);
    cout<<i<<endl;
    return 0;
}
