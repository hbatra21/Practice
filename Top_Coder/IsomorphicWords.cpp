/*

Problem Statement
    
Two words are called isomorphic if the letters in one word can be remapped to get the second word. Remapping a letter means replacing all occurrences of it with another letter. The ordering of the letters remains unchanged. No two letters may map to the same letter, but a letter may map to itself.
For example, the words "abca" and "zbxz" are isomorphic because we can map 'a' to 'z', 'b' to 'b' and 'c' to 'x'.
Given a vector <string> words, return how many (unordered) pairs of words are isomorphic.
Definition
    
Class:
IsomorphicWords
Method:
countPairs
Parameters:
vector <string>
Returns:
int
Method signature:
int countPairs(vector <string> words)
(be sure your method is public)
    

Constraints
-
words will contain between 2 and 50 elements, inclusive.
-
Each element of words will contain between 1 and 50 lowercase letters ('a'-'z'), inclusive.
-
All elements of words will have the same length.
-
There will be no duplicates in words.
Examples
0)

    
{"abca", "zbxz", "opqr"}
Returns: 1
"abca" and "zbxz" are isomorphic, but none of the two is isomorphic with "opqr".
1)

    
{"aa", "ab", "bb", "cc", "cd"}
Returns: 4
The four isomorphic pairs are {"aa", "bb"}, {"aa", "cc"}, {"bb", "cc"} and {"ab", "cd"}.
2)

    
{ "cacccdaabc", "cdcccaddbc", "dcdddbccad", "bdbbbaddcb",
  "bdbcadbbdc", "abaadcbbda", "babcdabbac", "cacdbaccad",
  "dcddabccad", "cacccbaadb", "bbcdcbcbdd", "bcbadcbbca" }
Returns: 13

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


class IsomorphicWords {
public:

  bool isIsomorphic(string a, string b){
		if (a.size() != b.size())
			return false;
		
		int used[26]={0};
		for(int i=0; i<a.size(); ++i){
		
			//a[i] -> b[i]
			if(used[b[i]-'a']!=0 && used[b[i]-'a']!=a[i]-'a'+1)
				return false;
			else
				used[b[i]-'a']=a[i]-'a'+1;
				
			for(int j=i+1; j<a.size(); ++j){
				if(a[j]==a[i] && b[j]!=b[i])
					return false;
			}
		}
		return true;
	}
	
	
	int countPairs(vector <string> words) {
		int ans = 0;
		for(int i=0; i<words.size(); ++i){
			for(int j=i+1; j<words.size(); ++j){
				ans += isIsomorphic(words[i], words[j]);
			}
		}
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
