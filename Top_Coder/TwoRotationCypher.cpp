/*

Problem Statement
    
You have decided to create your own simple encryption method for strings containing only lowercase letters and spaces. You start by splitting the alphabet into two groups. The first group consists of the first firstSize letters of the alphabet, and the second consists of the remaining 26 - firstSize letters. To encrypt a character in your message, you do the following:
If it a space, it is kept as is.
If it is a letter in the first group, it is moved firstRotate letters forward in the group, wrapping back to the start if necessary. For example, if firstSize is 6 and firstRotate is 2, then 'A' would become 'C', and 'F' would become 'B'.
If it is a letter in the second group, then it is moved secondRotate letters forward in the group, again wrapping back to the start of the group if necessary.
Given firstSize, firstRotate, secondRotate and a message, return the encrypted form of the message.
Definition
    
Class:
TwoRotationCypher
Method:
encrypt
Parameters:
int, int, int, string
Returns:
string
Method signature:
string encrypt(int firstSize, int firstRotate, int secondRotate, string message)
(be sure your method is public)
    

Constraints
-
firstSize will be between 1 and 25, inclusive.
-
firstRotate will be between 0 and firstSize - 1, inclusive.
-
secondRotate will be between 0 and 25 - firstSize, inclusive.
-
message will contain between 1 and 50 characters, inclusive.
-
message will contain only lowercase letters ('a' - 'z') and spaces.
Examples
0)

    
13
0
0
"this string will not change at all"
Returns: "this string will not change at all"

1)

    
13
7
0
"only the letters a to m in this string change"
Returns: "onfy tbl flttlrs h to g cn tbcs strcna jbhnal"

2)

    
9
0
16
"j to z will change here"
Returns: "z sn y vikk chamge heqe"

3)

    
17
9
5
"the quick brown fox jumped over the lazy dog"
Returns: "yqn izalc kwgsf ogt bzehnm grnw yqn djvu mgp"

4)

    
3
1
2
"  watch   out for strange  spacing "
Returns: "  ybvaj   qwv hqt uvtbpig  urbakpi "

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


class TwoRotationCypher {
public:
  string encrypt(int firstSize, int firstRotate, int secondRotate, string m) {
		string enc;
		for (int i=0; i<m.size(); ++i){
			
			if(m[i] == ' ')
				enc.push_back(m[i]);
			else if(m[i]-'a'<firstSize){
				//first group
				enc.push_back( ((m[i]-'a'+firstRotate)%firstSize)+'a' );
			}
			else{
				//second group
				enc.push_back( (m[i]-('a'+firstSize)+secondRotate)%(26-firstSize)+('a'+firstSize) );
			}
		}
		
		return enc;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
