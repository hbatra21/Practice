/*

Problem Statement
    
You are given a vector <string> words, each element of which is a single word. Return a vector <string> where the i-th element is the abbrevation for the i-th word. The abbreviation for a word is its shortest non-empty prefix that is not a prefix of any other given word. The constraints will guarantee that it is possible to find an abbreviation for all the given words.
Definition
    
Class:
WordAbbreviation
Method:
getAbbreviations
Parameters:
vector <string>
Returns:
vector <string>
Method signature:
vector <string> getAbbreviations(vector <string> words)
(be sure your method is public)
    

Notes
-
A string s1 is called a prefix of string s2 if and only if s1 can be obtained by removing zero or more characters from the end of s2.
Constraints
-
words will contain between 1 and 50 elements, inclusive.
-
Each element of words will contain between 1 and 50 characters, inclusive.
-
Each element of words will only contain lowercase letters ('a'-'z').
-
No element of words will be a prefix of another element of words.
Examples
0)

    
{"abc","def","ghi"}
Returns: {"a", "d", "g" }
A single character is enough.
1)

    
{"aaab","aaac","aaad"}
Returns: {"aaab", "aaac", "aaad" }
It's possible that the abbreviation is the same as the original word.
2)

    
{"top","coder","contest"}
Returns: {"t", "cod", "con" }

3)

    
{
 "bababaaaaa",
 "baaabaababa",
 "bbabaaabbaaabbabaabaabbbbbaabb",
 "aaababababbbbababbbaabaaaaaaaabbabbbaaab",
 "baaaaabaababbbaabbbabbababbbabbbbbbbbab"
}
Returns: {"bab", "baaab", "bb", "a", "baaaa" }

4)

    
{"oneword"}
Returns: {"o" }

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


class WordAbbreviation {
public:
  vector <string> getAbbreviations(vector <string> words) {
		vector <string> ans;
		for(int i=0; i<words.size(); ++i){
			for(int j=1; j<words[i].size()+1; ++j){
				string tmp = words[i].substr(0,j);
				bool flagall = true;
				for(int k=0; k<words.size(); ++k){
					 size_t found = words[k].find(tmp);
  					 if (found==0 && k!=i){
						flagall = false;
						break;
					}
				}
				if (flagall){
					ans.push_back(tmp);
					break;
				}
			}
		}
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
