/*

Problem Statement
    
Jakub is trying out a one-dimensional keyboard. It consists of a single row of keys. The distance between any two adjacent keys is 1. Each key contains a distinct letter of the English alphabet. Jakub uses only one finger to type on the keyboard. He wonders what is the smallest total distance he will have to move his finger while typing a given word.
 
For example, if the keyboard's only row is "qwertyuiop", and Jakub wants to type the word "potter", he will have to move his finger from 'p' to 'o' (distance 1), from 'o' to 't' (distance 4), from 't' to 't' (distance 0), from 't' to 'e' (distance 2) and from 'e' to 'r' (distance 1), for a total distance of 1 + 4 + 0 + 2 + 1 = 8.
 
You are given a string keyboard and a string word, describing the keyboard and the word Jakub wants to write. Return the minimum distance he will have to move his finger in order to type the word on the keyboard.
Definition
    
Class:
TypingDistance
Method:
minDistance
Parameters:
string, string
Returns:
int
Method signature:
int minDistance(string keyboard, string word)
(be sure your method is public)
    

Notes
-
When moving the finger from the i-th key to the j-th key, the distance covered by the move can be computed as |i-j|, that is, the positive difference between i and j.
Constraints
-
keyboard will contain between 1 and 26 characters, inclusive.
-
Each character in keyboard will be a different lowercase letter of the English alphabet ('a'-'z').
-
word will contain between 1 and 50 characters, inclusive.
-
Each character in word will be present in keyboard.
Examples
0)

    
"qwertyuiop"
"potter"
Returns: 8
The example from the problem statement.
1)

    
"tc"
"tctcttccctccccttc"
Returns: 9

2)

    
"a"
"aaaaaaaaaaa"
Returns: 0

3)

    
"kwadrutove"
"rowerowe"
Returns: 39

4)

    
"qwertyuiopasdfghjklzxcvbnm"
"topcodersingleroundmatchgoodluckhavefun"
Returns: 322

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


class TypingDistance {
public:
  int minDistance(string keyboard, string word) {
		if (keyboard.size() == 0 || word.size() == 0)
			return 0;
		int dist = 0, lastpos=keyboard.find(word[0]);
		for (int i=1; i<word.size(); ++i){
			int pos = keyboard.find(word[i]);
			dist += abs(pos - lastpos);
			lastpos = pos;
		}
		return dist;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
