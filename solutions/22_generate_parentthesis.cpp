#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool isValid(string s, int size){
    int left = 0, right = 0;
    for(auto a : s){
        if(a == '('){
            left ++;
        }else if(a == ')'){
            right ++;
        }
        if(right > size || left > size || right > left) return false;
    }
    return true;
}

vector<string> generateParenthesis(int n){
    deque<string> q;
    q.push_back("(");
    for(int i = 1; i < 2 * n; i++){
        int size = q.size();
        for(int k = 0; k < size; k++){
            string s1 = q[0] + "(";
            string s2 = q[0] + ")";
            if(isValid(s1, n)) q.push_back(s1);
            if(isValid(s2, n)) q.push_back(s2);
            q.pop_front();
        }
    }
    vector<string> v( q.begin(), q.end() );
    return v;
}

int main(int argc,char** argv){
    vector<string> vs = generateParenthesis(3);
    for(auto a: vs){
        cout<<a<<endl;
    }
    return 0;
}
