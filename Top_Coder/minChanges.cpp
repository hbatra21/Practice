/*

Problem Statement
    
A palindrome is a string that reads the same from left to right as it does from right to left. Given a String s, return a palindrome that is produced by changing the minimum possible number of characters in s. Changing a character means replacing it with any single character at the same position. You are not allowed to remove or add any characters. If there are multiple answers, return the one that comes first alphabetically.
Definition
    
Class:
Palindromize2
Method:
minChanges
Parameters:
string
Returns:
string
Method signature:
string minChanges(string s)
(be sure your method is public)
    

Constraints
-
s will contain between 1 and 50 characters, inclusive.
-
Each character of s will be a lowercase letter ('a'-'z').
Examples
0)

    
"ameba"
Returns: "abeba"
You can get "abeba" or "amema" with only 1 change. Among those two, "abeba" comes earlier alphabetically.
1)

    
"cigartragic"
Returns: "cigartragic"
The input is already a palindrome, so the best choice is to do 0 changes.
2)

    
"abcdef"
Returns: "abccba"

3)

    
"cxbpaxz"
Returns: "cxapaxc"

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


class Palindromize2 {
public:
  string minChanges(string s) {
		for(int i=0; i<s.size()/2; ++i){
			if(s[i]==s[s.size()-i-1])
				continue;
			else{
				char tmp = min(s[i],s[s.size()-i-1]);
				s[i] = tmp;
				s[s.size()-i-1] = tmp;
			}
		}
		return s;
		
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
