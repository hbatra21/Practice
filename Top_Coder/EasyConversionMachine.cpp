/*

Problem Statement
    
We have a string originalWord. Each character of originalWord is either 'a' or 'b'. Timmy claims that he can convert it to finalWord using exactly k moves. In each move, he can either change a single 'a' to a 'b', or change a single 'b' to an 'a'.  You are given the strings originalWord and finalWord, and the int k. Determine whether Timmy may be telling the truth. If there is a possible sequence of exactly k moves that will turn originalWord into finalWord, return "POSSIBLE" (quotes for clarity). Otherwise, return "IMPOSSIBLE".
Definition
    
Class:
EasyConversionMachine
Method:
isItPossible
Parameters:
string, string, int
Returns:
string
Method signature:
string isItPossible(string originalWord, string finalWord, int k)
(be sure your method is public)
    

Notes
-
Timmy may change the same letter multiple times. Each time counts as a different move.
Constraints
-
originalWord will contain between 1 and 50 characters, inclusive.
-
finalWord and originalWord will contain the same number of characters.
-
Each character in originalWord and finalWord will be 'a' or 'b'.
-
k will be between 1 and 100, inclusive.
Examples
0)

    
"aababba"
"bbbbbbb"
2
Returns: "IMPOSSIBLE"
It is not possible to reach finalWord in fewer than 4 moves.
1)

    
"aabb"
"aabb"
1
Returns: "IMPOSSIBLE"
The number of moves must be exactly k=1.
2)

    
"aaaaabaa"
"bbbbbabb"
8
Returns: "POSSIBLE"
Use each move to change each of the letters once.
3)

    
"aaa"
"bab"
4
Returns: "POSSIBLE"
The following sequence of 4 moves does the job: aaa -> baa -> bab -> aab -> bab
4)

    
"aababbabaa"
"abbbbaabab"
9
Returns: "IMPOSSIBLE"

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


class EasyConversionMachine {
public:
  string isItPossible(string originalWord, string finalWord, int k) {
		if(originalWord.size() != finalWord.size())
			return "IMPOSSIBLE";
		
		int diffCnt = 0;
		for(int i=0; i<originalWord.size(); ++i){
			if(originalWord[i]!=finalWord[i])
				++diffCnt;
		}
		
		if(diffCnt>k)
			return "IMPOSSIBLE";
		
		while(k>=diffCnt){
			if(diffCnt==k)
				return "POSSIBLE";
			--k; --k;
		}
		
		return "IMPOSSIBLE";
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
