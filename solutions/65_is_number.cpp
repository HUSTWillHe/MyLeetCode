#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void skipSpaces(string& s){
		int begin = 0, end = 0;
		for(auto a: s){
			if(a == ' ')
				begin++;
			else
				break;
		}
		for(int i = s.size() - 1; i >= 0; i--){
			if(s[i] == ' ')
				end++;
			else
				break;
		}
		s = s.substr(begin, s.size() - end - begin);
	}

	bool isPureNumber(string s){
		for(auto a : s){
			if(a - '0' >= 0 && a - '0' <= 9)
				continue;
			else{
				return false;
			}
		}
		return true;
	}

	bool checkBeforeE(string s){
		if(s.size() == 0)
			return false;
			string cur_str;
		if(s[0] == '+' || s[0] == '-'){
			cur_str = s.substr(1);
			if(cur_str.size() == 0)
				return false;
		}
		else
			cur_str = s;

		if(find(cur_str.begin(), cur_str.end(), '.') == cur_str.end()){
			return isPureNumber(cur_str);
		}
		else{
			string::iterator it = find(cur_str.begin(), cur_str.end(), '.');
			string first_part(cur_str.begin(), it); 
			string second_part(it+1, cur_str.end());
			if(first_part.size() == 0 && second_part.size() == 0)
				return false;
			if(first_part.size() == 0)
				return isPureNumber(second_part);
			if(second_part.size() == 0)
				return isPureNumber(first_part);
			else
				return (isPureNumber(first_part) && isPureNumber(second_part));
		}
	}

	bool checkAfterE(string s){
		if(s.size() == 0)
			return false;
		string cur_str;
		if(s[0] == '+' || s[0] == '-'){
			cur_str = s.substr(1);
			if(cur_str.size() == 0)
				return false;
		}
		else
			cur_str = s;
		return isPureNumber(cur_str);
	}
	
	bool isNumber(string s){
		int size = s.size();
		if(size == 0) 
			return false;
		skipSpaces(s);
		string cur_str;
		if(find(s.begin(), s.end(), 'e') == s.end()){
			return checkBeforeE(s);
			//return isPureNumberDot(s);
		}
		else{
			string::iterator it = find(s.begin(), s.end(), 'e');
			string first_part(s.begin(), it);
			string second_part(it+1, s.end());
			if(first_part.size() == 0 || second_part.size() == 0)
				return false;
			return (checkBeforeE(first_part) && checkAfterE(second_part));
			//return (isPureNumberDot(first_part) && isPureNumberDot(second_part));
		}
	}
};

int main(int argc,char** argv){
	Solution s;
	bool b;
	string str;
	str = "6e6.5 ";
	b = s.isNumber(str);
	//str = "abc";
	//b = s.isNumber(str);
	//str = "2e10";
	//b = s.isNumber(str);
	//str = "-90e3";
	//b = s.isNumber(str);
	//str = "53.5e97";
	//b = s.isNumber(str);
	//b = s.isPureNumber("123");
	//b = s.isPureNumber("1");
    return 0;
}
