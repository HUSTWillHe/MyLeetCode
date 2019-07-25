#include <iostream>
#include <string>
#include <vector>
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

vector<int> findChar(string s, int idx, char c){
    vector<int> v;
    for(int i = idx; i < s.size(); i++){
        if(s[i] == c){
            v.push_back(i);
        }
    }
    return v;
}

bool isMatch(string s, string p){
    int p_size = p.size();
    int si = 0;
    for(int pi = 0; pi < p_size; pi++){
        log("circle-------------------------\n");
        log("pi: "+to_string(pi) + '\n');
        log("si: "+to_string(si)+'\n');

        if(p[pi] == '.'){
            if(pi + 1 < p_size && cntChar(p, pi+1, '*') > 0){
                //dot with star
                //FIXME: dot star does not mean a series of same char, it means any chars in random number.
                log("dot with star\n");
                int star_num = cntChar(p, pi+1, '*');
                log("star_num: " + to_string(star_num));
                if(pi + star_num + 1 < p_size){
                    int char_num_p = cntChar(p, pi+star_num+1,s[si]);
                    int char_num_s = cntChar(s,si,s[si]);
                    if(char_num_s < char_num_p)
                        return false;
                    else{
                        pi += star_num + char_num_p;
                        si += char_num_s;
                    }
                }else{
                    int num_s = cntChar(s, si, s[si]);
                    if(si + num_s == s.size()){
                        return true;
                    }else{
                        return false;
                    }
                }
            }else{
                //dot without stars
                log("dot without star\n");
                si++;
            }
        }else{
            if(pi + 1 < p_size && cntChar(p, pi+1, '*') > 0){
                //char with star
                log("dot with star\n");
                int star_num = cntChar(p, pi+1,'*');
                if(pi+star_num+1 < p_size){
                    int same_char_num = cntChar(p, pi+star_num+1,p[pi]);
                    if(cntChar(s, si, p[pi]) < same_char_num)
                        return false;
                    else{
                        pi += star_num+same_char_num;
                        si += cntChar(s,si,p[pi]);
                    }
                }else{
                    int num_s = cntChar(s,si,p[pi]);
                    if(si + num_s == s.size())
                        return true;
                    else return false;
                }
            }else{
                //char without stars
                log("char without star");
                if(si >= s.size())
                    return false;
                if(p[pi] == s[si])
                    si++;
                else
                    return false;
            }
        }
    }
    if(si == s.size())
        return true;
    else return false;
}

int main(){
    //test cnt chat
    string s = "bcdddff";
    string p = "a*bc.****.f*";
    bool b = isMatch(s,p);
    log("result");
    log(to_string(b));

    return 0;
}
