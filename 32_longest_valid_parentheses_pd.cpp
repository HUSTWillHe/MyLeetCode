#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int longestValidParentheses(string s){
    int size = s.size();
    vector<int> v_current_longest;
    v_current_longest.push_back(0);
    int all_longest = 0;
    for(int i = 1; i<s.size(); i++){
        if(s[i] == ')'){
            if(s[i-1] == '('){
                int current_longest;
                if(i-2 >=0){
                    current_longest = v_current_longest[i-2]+2;
                }else{
                    current_longest = 2;
                }
                cout<<"(): occur current longest is:  "<<current_longest<<endl;
                v_current_longest.push_back(current_longest);
            }else{
                if(v_current_longest[i-1] == 0){
                    v_current_longest.push_back(0);
                }else{
                    int current_longest;
                    int last_longest = v_current_longest[i-1];
                    if(i - last_longest - 1 >= 0 && s[i - last_longest - 1] == '('){
                        if(i - last_longest - 2 >=0){
                            current_longest = v_current_longest[i-last_longest-2] + v_current_longest[i-1]+2;
                        }else{
                            current_longest = v_current_longest[i-1]+2;
                        }
                    }else{
                        current_longest = 0;
                    }
                    v_current_longest.push_back(current_longest);
                }
            }
        }else{
            v_current_longest.push_back(0);
        }
        if(v_current_longest[i] > all_longest)
            all_longest = v_current_longest[i];
        cout<<"current idx: "<<i<<" current longest: "<<v_current_longest[i]<<endl;
    }
    cout<<"---------------------------"<<endl;
    for(auto a: v_current_longest){
        cout<<a<<'\t';
    }
    cout<<endl;
    return all_longest;
}

int main(int argc,char** argv){
    string s = "((()))";
    int i = longest_valid_parentheses(s);
    cout<<s<<" : "<<i<<endl;
    s="))))()()()";
    i = longest_valid_parentheses(s);
    cout<<s<<" : "<<i<<endl;

    return 0;
}
