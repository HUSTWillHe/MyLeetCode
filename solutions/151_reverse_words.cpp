#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

class Solution {
public:
	deque<string> word_queue;
	string reverseWords(string s){
		bool start = false;
		string word = "";
		for(auto a: s){
			if(start){
				if(a == ' '){
					start = false;
					word_queue.push_back(word);
					word = "";
				}else{
					word += a;
				}
			}else{
				if(a != ' '){
					start = true;
					word = a;
				}
			}
		}
		if(word != "")
			word_queue.push_back(word);
		string ans = "";
		while(word_queue.size() > 0){
			ans += word_queue.back();
			word_queue.pop_back();
			if(word_queue.size() != 0)
				ans += " ";
		}
		return ans;
	}
};

int main(int argc,char** argv){
	Solution s;
	string ans = s.reverseWords("  hello world ");
	cout<<"ans is:"<<ans<<endl;
    return 0;
}
