/*

Problem Statement
    
There are some chickens and some cows in Farmer John's yard.
John's daughter Susie counted that all the animals in the yard have a total of 3 heads. John's son Billy counted their legs and got a total of 8. Using their answers, Farmer John easily determined that there have to be exactly 2 chickens and 1 cow.
Write a method that will solve a general version of Farmer John's problem. You are given two ints heads and legs. Compute the number of chickens and the number of cows. Return a vector <int> with two elements: first the number of chickens, then the number of cows. If there is no solution, return an empty vector <int> instead.
Definition
    
Class:
OnTheFarmDivTwo
Method:
animals
Parameters:
int, int
Returns:
vector <int>
Method signature:
vector <int> animals(int heads, int legs)
(be sure your method is public)
    

Notes
-
If the solution exists, it is always unique.
-
A chicken has 1 head and 2 legs. A cow has 1 head and 4 legs.
Constraints
-
heads will be between 0 and 1,000,000, inclusive.
-
legs will be between 0 and 1,000,000, inclusive.
Examples
0)

    
3
8
Returns: {2, 1 }
Two chickens and a cow have a total of three heads and eight legs.
1)

    
10
40
Returns: {0, 10 }
Ten cows.
2)

    
10
42
Returns: { }
This test case has no solution because the number of legs is too large (or the number of heads is too small).
3)

    
1
3
Returns: { }
No set of animals can have one head and three legs.
4)

    
0
0
Returns: {0, 0 }

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


class OnTheFarmDivTwo {
public:
  vector <int> animals(int heads, int legs) {
		vector <int> ans;
		if (legs%2==1 || legs/2<heads || 2*heads<legs/2)
			return ans;
		ans.push_back(2*heads-legs/2);
		ans.push_back(legs/2-heads);
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
