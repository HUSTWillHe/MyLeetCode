#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>

using namespace std;

class Solution {
private:
	map<long, string::size_type> remainders;

public:
	string fractionToDecimal(int numerator, int denominator) {
		if(denominator == 0)
			return "0";
		long nume = (long) numerator;
		long deno = (long) denominator;
		if(nume % deno == 0)
			return to_string(nume/deno);
		bool is_negative = false;
		if((nume < 0 && deno > 0) || (nume > 0 && deno < 0)){
			is_negative = true;
			nume = abs(nume);
			deno = abs(deno);
		}
		string ans, decimal_part;
		string integer_part = to_string(nume/deno);
		long remainder = nume % deno;
		remainders[remainder] = 0;
		string::size_type cnt = 0;
		while(remainder != 0){
			cnt++;
			remainder = (remainder * 10);
			string quotient = to_string(remainder / deno);
			decimal_part += quotient;
			remainder = remainder % deno; 
			if(remainders.find(remainder) != remainders.end()){
				decimal_part.insert(remainders[remainder], "(");
				decimal_part += ")";
				break;
			}
			remainders[remainder] = cnt;
		}
		ans = integer_part + "." + decimal_part;
		if(is_negative)
			ans = "-" + ans;
		return ans;
	}
};

int main(int argc,char** argv){
	Solution s;
	string ans = s.fractionToDecimal(-2147483648, -1);
	cout<<"ans: "<<ans<<endl;
    return 0;
}
