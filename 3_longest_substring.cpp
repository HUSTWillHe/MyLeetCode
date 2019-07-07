#include <iostream>
#include <string>

using namespace std;

bool hasSame(string s){
    bool b[128];
    for(int i = 0;i<128;i++){
        b[i] = false;
    }
    for(char c:s){
        if(b[c])
            return true;
        else
            b[c] = true;
    }
    return false;
}

int lengthOfLongestSubstring(string s){
    int length = s.length();
    for(int i = 1; i<=length;i++){
        cout<<"==========================="<<endl;
        cout << "length: "<<length + 1 - i<<endl;
        for(int j = 0; j < i; j++){
            cout<<"subString: "<<s.substr(j,length+1-i)<<endl;
            if(!hasSame(s.substr(j,length + 1 -i)))
                return length + 1 -i;
        }
    }
}

int getLongest(string s, int l){
    bool b[128];
    for(int i = 0; i< 128;i++){
        b[i] = false;
    }
    for(int i = 0; i<l;i++){
        if(b[s[i]] == true){
            return i;
        }else{
            b[s[i]] = true;
        }
    }
    return l;
}

int lengthOfLongestSubstring_2(string s){
    //上面那种方法是暴力法，这里试一试用某个位置开头最长解
    if(s == "") return 0;
    int max = 1;
    int length = s.length();
    for(int i = 0; i<length; i++ ){
        //cout <<"======================================"<<endl;
        //cout <<"Round: "<<i<<endl;
        if(max >= length - i){
            return max;
        }
        int l = getLongest(s.substr(i), length - i);
        //cout<<"length: "<<l<<endl;
        if (l > max){
            max = l;
        }
    }
    return max;
}

int main(){
    string s1 = "abcabcabcabc";
    string s2 = "bbbbbb";
    string s3 = "pwwkew";
    cout <<"length: s1: "<<lengthOfLongestSubstring_2(s1)<<endl;
    cout <<"length: s2: "<<lengthOfLongestSubstring_2(s2)<<endl;
    cout <<"length: s3: "<<lengthOfLongestSubstring_2(s3)<<endl;
    return 0;
}
