/*

Problem Statement
    
I need software that can read written numbers and convert them to integers. The numbers are always between 1 and 99 inclusive, but may be misspelled. The correct spelling of numbers is given by the following grammar, in which '<' '>' '::=' and '|' are metacharacters and all others are literal:
<NUMBER> ::= <ONES> | <TEEN> | <TENS> | <TENS>-<ONES>
<ONES> ::= one | two | three | four | five | six | seven | eight | nine
<TEEN> ::= ten | eleven | twelve | thirteen | fourteen | fifteen | sixteen | seventeen | eighteen | nineteen
<TENS> ::= twenty | thirty | forty | fifty | sixty | seventy | eighty | ninety
Create a class Speller that contains a method value that is given a string number and that returns the integer value whose correct spelling is closest to number. The distance between two spellings is defined to be the number of characters in one of the spellings that would need to be changed to a different character in order to make them match, where matching is case sensitive. Two spellings of different lengths are considered to be infinitely far apart.
The method should return -1 if there is more than one value that is closest to number.
Definition
    
Class:
Speller
Method:
value
Parameters:
string
Returns:
int
Method signature:
int value(string number)
(be sure your method is public)
    

Constraints
-
number will contain between 1 and 20 characters inclusive.
-
Each character in number will be between ASCII 33 and ASCII 126 inclusive.
Examples
0)

    
"forty-two"
Returns: 42

1)

    
"FORTY-TWO"
Returns: -1
"forty-two" and " fifty-two" are both a distance of 8 from "FORTY-TWO". No other number is closer.
2)

    
"eightene"
Returns: 18
"eighteen" is 2 misspelled letters away from "eightene"
3)

    
"fi"
Returns: -1
All numbers are infinitely far away, since there are no 2 character strings that represent numbers.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class Speller {

public:
  int dist(string x, string y){
		if(x.size()!=y.size())
			return 1<<31 - 1;
		
		int cnt = 0;
		for(int i=0; i<x.size(); ++i){
			if(x[i]!=y[i])
				++cnt;
		}
		
		return cnt;
	}
	
	
	int value(string number) {
		const  string ONES[20] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
		const  string TENS[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
		
		vector<string> all;
		for(int i=1; i<100; ++i){
			if(i<20)
				all.push_back(ONES[i]);
			else{
				string tmp = TENS[i/10];
				if(i%10 > 0){
					tmp += "-";
					tmp += ONES[i%10];
				}
				all.push_back(tmp);
			}
			//cout<<all.back()<<endl;
		}
		
		//find the one with min dist
		int mymin = 1<<31 - 1;
		int ans = 0;
		for(int i=0; i<all.size(); ++i){
			int mydist = dist(all[i], number);
			if(mydist<mymin){
				mymin = mydist;
				ans = i+1;
			}
		}
		
		//check if the answer is unique
		for(int i=0; i<all.size(); ++i){
			int mydist = dist(all[i], number);
			if(mydist==mymin && i+1!=ans){
				return -1;
			}
		}
		
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
