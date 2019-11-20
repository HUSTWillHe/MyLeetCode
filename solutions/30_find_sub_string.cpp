#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> push2vec(string s, int length, int size, int index){
    vector<string> vs;
    if(s.size() < index + length * size) return vs;
    for(int i = 0; i < size; i++){
        vs.push_back(s.substr(index + i * length, length));
    }
    return vs;
}

bool compVec(vector<string> a, vector<string> b){
    if(a.size() != b.size())
        return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}

vector<int> findSubstring(string s, vector<string>& words){
    vector<int> vi;
    int size = words.size();
    if(s.size() == 0 || size == 0) return vi;
    int length = words[0].size();
    if(s.size() < length * size) return vi;
    for(int i = 0; i < s.size(); i++){
        string sub = s.substr(i, length);
        vector<string>::iterator it = find(words.begin(), words.end(), sub);
        if(it != words.end()){
            vector<string> vs = push2vec(s, length, size, i);
            if(vs.size()!=0){
                if(compVec(words, vs)){
                    vi.push_back(i);
                }
            }
        }
    }
    return vi;
}

int main(int argc,char** argv){
    string s = "barfoothefoobarman";
    vector<string> vs{"bar","foo"};
    vector<int> vi = findSubstring(s, vs);
    for(auto a: vi){
        cout<<a<<endl;
    }
    return 0;
}
