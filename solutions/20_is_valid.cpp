#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(string s){
    vector<char> v;
    for(int i = 0; i< s.size(); i++){
        switch(s[i]){
            case '(':
                v.push_back('(');
                break;
            case '[':
                v.push_back('[');
                break;
            case '{':
                v.push_back('{');
                break;
            case ')':
                if(v.size() == 0) return false;
                if(*(v.end()-1) != '(') return false;
                v.pop_back();
                break;
            case ']':
                if(v.size() == 0) return false;
                if(*(v.end()-1) != '[') return false;
                v.pop_back();
                break;
            case '}':
                if(v.size() == 0) return false;
                if(*(v.end()-1) != '{') return false;
                v.pop_back();
                break;
            default:
                return false;
                break;
        }
    }
    if(v.size() != 0) return false;
    return true;
}

int main(int argc,char** argv){
    cout<<"()  "<<isValid("()")<<endl;
    cout<<"(){}[]  "<<isValid("(){}[]")<<endl;
    cout<<"(] "<<isValid("(]")<<endl;
    return 0;
}
