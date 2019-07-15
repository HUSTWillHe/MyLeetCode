#include <iostream>
#include <string>
#include <vector>
using namespace std;

string convert(string s, int numRows){
    if(numRows == 1) return s;
    int circle = numRows * 2 - 2;
    vector<string> vs(numRows);
    for(int i = 0; i<s.size(); i++){
        int idx = i % circle;
        if(idx < numRows){
            vs[idx] += (s[i]);
        }else{
            vs[circle - idx] += (s[i]);
        }
    }
    for(int i = 1; i < numRows; i++){
        vs[0] += (vs[i]);
    }
    return vs[0];
}

int main(int argc, char** argv){
    if(argc != 3){
        cout<<"usage a.out <num rows> <string>"<<endl;
        return 1;
    }
    int num_raws = atoi(argv[1]);
    string str = argv[2];
    string ans = convert(str, num_raws);
    cout<<"ans: "<<ans<<endl;
    return 0;
}
