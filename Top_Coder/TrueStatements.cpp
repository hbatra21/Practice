/*


Problem Statement
    
Professor Smith teaches a logic class. One day, he writes some statements on the blackboard:
Exactly a of these statements are true.
Exactly b of these statements are true.
Exactly c of these statements are true.
.
.
.
Each of a, b, c and so on is a number. He then asks the class how many of the statements are true.
You will be given a vector <int> statements, containing the numbers written in Professor Smith's statements. Return the number of the statements that are true. If there is more than one possible answer, return the largest one. If there are no possible answers, return -1.
Definition
    
Class:
TrueStatements
Method:
numberTrue
Parameters:
vector <int>
Returns:
int
Method signature:
int numberTrue(vector <int> statements)
(be sure your method is public)
    

Constraints
-
statements will contain between 1 and 50 elements, inclusive.
-
Each element of statements will be between 0 and 50, inclusive.
Examples
0)

    
{0, 1, 2, 3}
Returns: 1
The 2nd statement is true (there is one true statement) and the others are false.
1)

    
{0}
Returns: -1
This is the Epimedes paradox: if the statement is true then it claims to be false, but if it is false then it must be true.
2)

    
{0, 3, 1, 3, 2, 3}
Returns: 3
One solution is that the 3rd statement is the only true statement. However, it is also possible that the 2nd, 4th and 6th statements are true (all of which say that 3 statements are true), and the largest solution must be returned.
3)

    
{1, 1}
Returns: 0

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


class TrueStatements {
public:
  int numberTrue(vector <int> s) {
	
		int memo[50] = {0};
		for(int i=0; i<s.size(); ++i)
			++memo[s[i]];
		
		for (int i=50; i>=1; i--){
			if(i==memo[i])
				return i;
		}
		
		return (memo[0]==0)?0:-1;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
