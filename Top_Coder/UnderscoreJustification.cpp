/*

Problem Statement
    
Most word processors available today allow several standard ways to format lines in a paragraph. One of those ways is to 'justify' each line to a given width. The precise definition for that operation is as follows:
Assume that a line of text consists of several words separated by spaces (for simplicity, there will be no punctuation). Define a gap as the sequence of spaces between a pair of adjacent words. When reformatting a line, each gap can be replaced with a gap of a different non-zero length. The line is said to be justified to width w if it is exactly w characters long, has no leading or trailing spaces, and all gaps are as evenly distributed as possible. This means that the gaps should all be of equal length, or, if that is not possible, the difference in length between the longest and smallest gaps must be 1.
To better illustrate the results of the justification operation, we will use underscores ('_') in place of spaces.
Obviously, the above rules don't uniquely define the result of a justification. If there are multiple ways to justify a line of text, the one that comes earliest lexicographically is used. Note that an underscore comes after uppercase letters but before lowercase letters in the ASCII ordering.
You are given a vector <string> words containing all the words in a line of text. The words are given in the order that they appear in the line. Return the line of text justified to the given width, using underscores as spaces.
Definition
    
Class:
UnderscoreJustification
Method:
justifyLine
Parameters:
vector <string>, int
Returns:
string
Method signature:
string justifyLine(vector <string> words, int width)
(be sure your method is public)
    

Notes
-
Note that you must make all the gaps have equal length if possible. Only if that is impossible, the longest gap will be one longer than the shortest.
-
Remember that 'A' < 'B' < 'C' < ... < 'Z' < '_' < 'a' < 'b' < 'c' < ... < 'z'.
-
A string is lexicographically smaller than another string if it contains a smaller character in the first position where they differ.
Constraints
-
words will contain between 2 and 10 elements, inclusive.
-
Each element of words will contain between 1 and 10 characters, inclusive.
-
Each element of words will contain only letters ('A'-'Z', 'a'-'z').
-
width will be between 3 and 200, inclusive.
-
width will be greater than or equal to len+n-1, where n is the number of elements in words, and len is the total number of characters in words, to allow at least one space between adjacent words.
Examples
0)

    
{"A", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"}
50
Returns: "A___quick__brown__fox__jumps__over__the__lazy__dog"
We have 7 groups of 2 underscores and 1 group of 3 underscores to put between our words. If the first gap contains 2 underscores, then the string would start with "A__q", which is lexicographically larger than "A___", so it's advantageous to put 3 underscores in the first gap.
1)

    
{"Alpha", "Beta", "Gamma", "Delta", "Epsilon"}
32
Returns: "Alpha_Beta_Gamma__Delta__Epsilon"
There are six possible variants: Alpha_Beta_Gamma__Delta__Epsilon Alpha_Beta__Gamma_Delta__Epsilon Alpha_Beta__Gamma__Delta_Epsilon Alpha__Beta_Gamma_Delta__Epsilon Alpha__Beta_Gamma__Delta_Epsilon Alpha__Beta__Gamma_Delta_Epsilon The former is the lexicographically smallest one.
2)

    
{"Hello", "world", "John", "said"}
29
Returns: "Hello____world___John____said"
Sometimes it's better to mix large and small groups of underscores.
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


class UnderscoreJustification {
public:
  
	string justifyLine(vector <string> words, int width) {
		int wlen = 0;
		for(int i=0; i<words.size(); ++i)
			wlen += words[i].size();
		
		int u = width-wlen;				//underscores needed
		int exu = u%(words.size()-1);	//evenly give one underscore per gap (for several rounds) and see how many are left
		string avu = "";				//average underscore string
		for(int i=0; i<u/(words.size()-1); ++i)
			avu += "_";
		
		vector <string> all;
		for(int i=0; i<(1<<words.size()-1); ++i){
			int cntone = 0;
			for(int j=0; j<words.size()-1; ++j)
				cntone += (i>>j)&1;
			if(cntone==exu){
				string tmp;
				for(int j=0; j<words.size()-1; ++j){
					tmp += words[j];
					tmp += avu;
					if((i>>j)&1)
						tmp += "_";
				}
				tmp += words[words.size()-1];
				all.push_back(tmp);
			}
		}
		
		//get the lexicographically smallest one
		string ans = all[0];
		for(int i=1; i<all.size(); ++i){
			if(lexicographical_compare(all[i].begin(),all[i].end(),ans.begin(),ans.end()))
				ans = all[i];
		}
		
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
