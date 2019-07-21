#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isVecPalindrome(vector<int> v){
    vector<int>::iterator ifront = v.begin();
    vector<int>::iterator iback = v.end() -1;
    while(1){
        if(ifront >= iback){
            break;
        }
        if(*ifront == *iback){
            ifront ++;
            iback --;
        }else{
            return false;
        }
    }
    return true;
}

bool isPalindrome(int x){
    int i = 0;
    int cnt = 0;
    vector<int> v;
    if(x < 0) return false;
    if(x == 0) return true;
    while(1){
        if(x == 0){
            break;
        }
        cnt++;
        i = x % 10;
        v.push_back(i);
        x = (x - i)/10;
    }
    return isVecPalindrome(v);
}

int main(){
    int i = 1234321;
    bool b = isPalindrome(i);
    cout<<b<<endl;
    i = 124566;
    b = isPalindrome(i);
    cout<<b<<endl;
    return 0;
}
