#include <iostream>
using namespace std;
int getLongest(string s, int i){
    int cnt;
    int longest;
    for(cnt = 0; i - cnt >=0 && i + cnt < s.size() && s[i - cnt] == s[i + cnt]; cnt++){
        continue;
    }
    longest = 2 * cnt - 1;
    for(cnt = 0; i - cnt >= 0 && i + 1 + cnt < s.size() && s[i - cnt] == s[i + cnt + 1]; cnt++){
        continue;
    }
    if(2 * cnt > longest){
        return 2*cnt;
    }
    return longest;
}

string longestPalindrome(string s){
    int longest = 1;
    int index = 0;
    for(int i = 0; i < s.size(); i++){
        int l = getLongest(s, i);
        if(l > longest){
            longest = l;
            index = i;
        }
    }

    if(longest % 2 == 0){
        return s.substr(index - longest/2 + 1, longest);
    }else{
        return s.substr(index - (longest - 1)/2, longest);
    }
}
int main(){
    string s = "cbaabc";
    string ss = longestPalindrome(s);
    cout<<ss<<endl;
    return 0;
}
