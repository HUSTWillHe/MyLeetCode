#include <iostream>
#include <string>
using namespace std;
#define PRINT_LOG 1

void log(string s){
    if(PRINT_LOG){
        cout<<s<<endl;
    }
}

int cntChar(string s, int idx, char c){
    int rst = 0;
    while(idx + rst < s.size() && s[idx + rst] == c){
        rst ++;
    }
    return rst;
}

bool isMatch(string s, string p){
    int p_size = p.size();
    int si = 0;
    for(int pi = 0; pi < p_size; pi++){
        if(p[pi] == '.'){
            if(pi + 1 < p_size && cntChar(p, pi+1, '*') > 0){
                //dot with star
                int star_num = cntChar(p, pi+1, '*');
                if(pi + star_num + 1 < p_size){
                    int char_num_p = cntChar(p, pi+star_num+1,s[si]);
                    int char_num_s = cntChar(s,si,s[si]);
                    if(char_num_s < char_num_p)
                        return false;
                    else{
                        pi += star_num + char_num_p;
                        si += char_num_s;
                    }
                }
            }else{
                //dot without stars
                si++;
            }
        }else{
            if(pi + 1 < p_size && cntChar(p, pi+1, '*') > 0){
                //char with star
                int star_num = cntChar(p, pi+1,'*');
                if(pi+star_num+1 < p_size){
                    //has same char after star
                    int same_char_num = cntChar(p, pi+star_num+1,p[pi]);
                    if(cntChar(s, si, p[pi]) < same_char_num)
                        return false;
                    else{
                        pi += star_num+same_char_num;
                        si += cntChar(s,si,p[pi]);
                    }
                }
            }else{
                //char without stars
                if(si >= s.size())
                    return false;
                if(p[pi] == s[si])
                    si++;
                else
                    return false;
            }
        }
    }
    return true;
}

int main(){
    //test cnt chat
    string s = "abc";
    string p = "...*";
    bool b = isMatch(s,p);
    log(to_string(b));

    return 0;
}
