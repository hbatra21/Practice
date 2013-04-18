/*

Problem Statement
    
There are two types of egg cartons. One type contains 6 eggs and the other type contains 8 eggs. John wants to buy exactly n eggs. Return the minimal number of egg cartons he must buy. If it's impossible to buy exactly n eggs, return -1.
Definition
    
Class:
EggCartons
Method:
minCartons
Parameters:
int
Returns:
int
Method signature:
int minCartons(int n)
(be sure your method is public)
    

Constraints
-
n will be between 1 and 100, inclusive.
Examples
0)

    
20
Returns: 3
He should buy 2 cartons containing 6 eggs and 1 carton containing 8 eggs. In total, he buys 3 egg cartons.
1)

    
24
Returns: 3
There are two ways to buy 24 eggs: buy 4 cartons containing 6 eggs or buy 3 cartons containing 8 eggs. Minimize the number of cartons.
2)

    
15
Returns: -1
He can't buy an odd number of eggs.
3)

    
4
Returns: -1

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


class EggCartons {
public:  
	int minCartons(int n) {
		if(n%2==1 || n<6)
			return -1;
		else if(n==6 || n==8)
			return 1;
		else{
			int t1 = minCartons(n-6);
			int t2 = minCartons(n-8);
			if(t1!=-1 && t2!=-1)
				return min(t1, t2)+1;
			else if(t1==-1 && t2!=-1)
				return t2+1;
			else if(t1!=-1 && t2==-1)
				return t1+1;
			else
				return -1;
		}
			
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
