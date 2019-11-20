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

string intToRoman(int num){
    char romanCharacter[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    string ret = "";
    int circle_cnt = 0;
    while(num != 0){
        int i = num %10;
        num = (num - i)/10;
        if((circle_cnt == 3 && i > 3) || circle_cnt > 3 ){
            cout<<"number is too large!"<<endl;
            return "";
        }
        switch(i){
            case 0:
                break;
            case 1:
            case 2:
            case 3:
                ret.append(i, romanCharacter[2 * circle_cnt]);
                break;
            case 4:
                ret += romanCharacter[2*circle_cnt + 1];
                ret += romanCharacter[2*circle_cnt];
                break;
            case 5:
            case 6:
            case 7:
            case 8:
                ret.append((i - 5), romanCharacter[2*circle_cnt]);
                ret += romanCharacter[2*circle_cnt + 1];
                break;
            case 9:
                ret += romanCharacter[2*circle_cnt + 2];
                ret += romanCharacter[2 * circle_cnt];
                break;
        }
        circle_cnt++;
    }
    cout<<"before reverse: "<<ret<<endl;
    reverse(ret.begin(), ret.end());
    cout<<"after reverse: "<<ret<<endl;
    return ret;
}

int main(int argc,char** argv){
    cout<<4<<endl;
    string s = intToRoman(4);
    cout<<9<<endl;
    s = intToRoman(9);
    cout<<8<<endl;
    s = intToRoman(8);
    cout<<12<<endl;
    s = intToRoman(12);
    cout<<22222<<endl;
    s = intToRoman(222222);
    cout<<1994<<endl;
    s = intToRoman(1994);
    return 0;
}
