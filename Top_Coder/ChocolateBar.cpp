/*

Problem Statement
    
You just bought a very delicious chocolate bar from a local store. This chocolate bar consists of N squares, numbered 0 through N-1. All the squares are arranged in a single row. There is a letter carved on each square. You are given a string letters. The i-th character of letters denotes the letter carved on the i-th square (both indices are 0-based).  You want to share this delicious chocolate bar with your best friend. At first, you want to give him the whole bar, but then you remembered that your friend only likes a chocolate bar without repeated letters. Therefore, you want to remove zero or more squares from the beginning of the bar, and then zero or more squares from the end of the bar, in such way that the remaining bar will contain no repeated letters.  Return the maximum possible length of the remaining chocolate bar that contains no repeated letters.
Definition
    
Class:
ChocolateBar
Method:
maxLength
Parameters:
string
Returns:
int
Method signature:
int maxLength(string letters)
(be sure your method is public)
    

Constraints
-
letters will contain between 1 and 50 characters, inclusive.
-
Each character of letters will be a lowercase letter ('a' - 'z').
Examples
0)

    
"srm"
Returns: 3
You can give the whole chocolate bar as it contains no repeated letters.
1)

    
"dengklek"
Returns: 6
Remove two squares from the end of the bar.
2)

    
"haha"
Returns: 2
There are three possible ways:
Remove two squares from the beginning of the bar.
Remove two squares from the end of the bar.
Remove one square from the beginning of the bar and one square from the end of the bar.
3)

    
"www"
Returns: 1

4)

    
"thisisansrmbeforetopcoderopenfinals"
Returns: 9

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


class ChocolateBar {
public:
  bool isrepeated(string bar){
		int exist[26] = {0};
		for(int i=0;  i<bar.size(); ++i){
			if( exist[bar[i]-97] == 0 )
				exist[bar[i]-97] = 1;
			else
				return true;	//repeated
		}
		return false;
	}
	
	int maxLength(string letters) {
		int ans = -1;
		for(int i=0;  i<letters.size(); ++i){
			for(int j=i+1;  j<letters.size()+1; ++j){
				if( isrepeated(letters.substr(i, j-i)) == false )
					ans = max(ans, j-i);
			}
		}
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
