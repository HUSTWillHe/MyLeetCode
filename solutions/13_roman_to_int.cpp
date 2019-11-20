#include <iostream>
#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <memory>
#include <new>
#include <complex>
#include <exception>
#include <functional>
#include <utility>
#include <typeinfo>

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <climits>
#include <cerrno>
#include <ctime>
#include <csignal>
#include <csetjmp>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/time.h>

using namespace std;

int romanToInt(string s){
    vector<char> vRoma = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int num = 0;
    int size = s.size();
    for(int i = 0; i<size;i++){
        switch(s[i]){
            case 'I':
                if(i+1<size){
                    if(s[i+1] == 'V'){
                        cout<<"IV"<<endl;
                        num += 4;
                        i++;
                        break;
                    }else if(s[i+1] == 'X'){
                        num+=9;
                        i++;
                        break;
                    }
                }
                num++;
                break;
            case 'V':
                num+=5;
                break;
            case 'X':
                if(i+1<size){
                    if(s[i+1] == 'L'){
                        num += 40;
                        i++;
                        break;
                    }else if(s[i+1] == 'C'){
                        cout<<"XC"<<endl;
                        num += 90;
                        i++;
                        break;
                    }
                }
                num+=10;
                break;
            case 'L':
                num += 50;
                break;
            case 'C':
                if(i + 1 < size){
                    if( s[i + 1]=='D' ){
                        num+=400;
                        i++;
                        break;
                    }else if(s[i+1] == 'M'){
                        cout<<"CM"<<endl;
                        num+=900;
                        i++;
                        break;
                    }
                }
                num+=100;
                break;
            case 'D':
                num+=500;
                break;
            case 'M':
                num+=1000;
                break;
        }
    }
    return num;
}

int main(int argc,char** argv){
    int i = romanToInt("MCMXCIV");
    cout<<"1994: "<<i<<endl;
    return 0;
}
