#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	vector<string> originalWords;
	int printWidth;
public:
	string assemble(int begin, int end){
		int word_length = 0;
		int cnt = end - begin;
		for(int i = begin; i < end; i++){
			word_length += originalWords[i].size();
		}
		int delta = printWidth - word_length;
		if(cnt == 1){
			int space = printWidth - originalWords[begin].size();
			return originalWords[begin] + string(space, ' ');
		}
		int average = delta / (cnt - 1);
		int plus = delta - average * (cnt - 1);
		string ans;
		for(int i = begin; i < end; i++){
			ans += originalWords[i];
			if(i != end - 1)
				ans += string(average, ' ');
			if(plus-->0)
				ans += ' ';
		}
		return ans;
	}

	string assemble_last(int begin){
		string ans = "";
		for(int i = begin; i < originalWords.size(); i++){
			ans += originalWords[i];
			if(i != originalWords.size() - 1)
				ans += " ";
		}
		int space = printWidth - ans.size();
		return ans + string(space, ' ');
	}

	vector<string> fullJustify(vector<string>& words, int maxWidth){
		originalWords = words;
		printWidth = maxWidth;
		if(words.size() == 0 || maxWidth <= 0)
			return vector<string>();
		int cnt = 0;
		int begin = 0;
		vector<string> ans;
		for(int i = 0; i < words.size(); i++){
			cnt += words[i].size();
			if(cnt > maxWidth){
				ans.push_back(assemble(begin, i));
				cnt = words[i].size() + 1;
				begin = i;
			}else{
				cnt ++;
			}
		}
		ans.push_back(assemble_last(begin));
		return ans;
	}
};

int main(int argc,char** argv){
	vector<string> vs{"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
	//vector<string> vs{"this", "is", "an", "example", "of", "text", "justification", "think", "12345678901","12345","12345"};
	Solution s;
	vector<string> ans = s.fullJustify(vs, 20);
	for(auto a: ans){
		cout<<a<<"|"<<endl;
	}
    return 0;
}
