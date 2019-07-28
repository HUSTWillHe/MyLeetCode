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

void dotStar(string s, int idx, int& dot_num, int& first_char_idx){
    // idx is the index after dot-star
    // c is the first char after dots and stars
    // dot_num is the count of dots
    dot_num = 0;
    first_char_idx = -1;
    for(int i = idx; i < s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            first_char_idx = i;
            return;
        }
        else if(s[i] == '.' && i + 1 < s.size() && s[i + 1] != '*'){
            dot_num++;
        }
    }
}

bool isMatch(string s, string p){
    if(s.size() == 0)
        return true;
    int p_size = p.size();
    int si = 0;
    for(int pi = 0; pi < p_size; pi++){
        log("circle-------------------------\n");
        log("current p: "+ p.substr(pi) + '\n');
        log("current s: "+ s.substr(si)+'\n');

        if(p[pi] == '.'){
            if(pi + 1 < p_size && cntChar(p, pi+1, '*') > 0){
                //dot with star
                log("dot with star\n");
                int star_num = cntChar(p, pi + 1, '*');
                int dot_num = 0;
                int first_char_idx = -1;
                dotStar(p, pi + star_num + 1, dot_num, first_char_idx);
                log("dot num: " + to_string(dot_num));
                log("first_char_idx: " + to_string(first_char_idx));
                if(first_char_idx == -1){
                    log("no char after dot-star");
                    if(s.size() - si >= dot_num)
                        return true;
                    else
                        return false;
                }else{
                    for(int i = si + dot_num; i <= s.size(); i++){
                        log("recursive:================================================");
                        log("s.substr(): " + s.substr(i));
                        log("p.substr(): " + p.substr(first_char_idx));
                        if(isMatch(s.substr(i), p.substr(first_char_idx))){
                            return true;
                        }
                    }
                    return false;
                }
            }else{
                //dot without stars
                log("dot without star\n");
                si++;
            }
        }else{
            if(pi + 1 < p_size && cntChar(p, pi+1, '*') > 0){
                //char with star
                log("char with star\n");
                int star_num = cntChar(p, pi+1,'*');
                int same_char_num_s = cntChar(s, si, p[pi]);
                if(same_char_num_s == 0){
                    pi += star_num;
                }else{
                    for(int i = 0; i <= same_char_num_s; i++){
                        log("recursive:================================================");
                        log("round: " + to_string(i) + ".............");
                        log("new p: " + p.substr(pi + star_num + 1));
                        log("new s: " + s.substr(si + i));
                        if(isMatch(s.substr(si + i), p.substr(pi + star_num + 1)))
                            return true;
                    }
                    return false;
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
    string s = "ab";
    string p = ".*..c*";
    bool b = isMatch(s,p);
    log("result");
    log(to_string(b));

    return 0;
}
