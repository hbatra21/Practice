/*

Problem Statement
    
Let D(X) denote the sum of digits of the positive integer X. For example, D(4007) = 4 + 0 + 0 + 7 = 11.
Take any positive integer X, and let Y = X / D(X). If Y is an integer, we say that Y is the parent of X (and that X is a child of Y). For example, if X=12 then X / D(X) = 12 / (1+2) = 4, hence 4 is the parent of 12.
Note that multiple numbers can have the same parent. For example, 4 is also the parent of 36, as 36/(3+6) = 36/9 = 4.
We say that a number Y is childless if there is no positive integer X such that Y is the parent of X.
You are given two ints A and B. Find and return the count of all childless numbers that lie between A and B, inclusive.
Definition
    
Class:
ChildlessNumbers
Method:
howMany
Parameters:
int, int
Returns:
int
Method signature:
int howMany(int A, int B)
(be sure your method is public)
    

Constraints
-
A will be between 1 and 1,000,000,000, inclusive.
-
B will be between A and 1,000,000,000, inclusive.
-
B-A will be between 0 and 10,000, inclusive.
Examples
0)

    
4
7
Returns: 0
Each of the numbers {4,5,6,7} has at least one child. For example, 54 / (5+4) = 6, hence 6 is not childless.
1)

    
37
37
Returns: 0
E.g., 333 / (3+3+3) = 37.
2)

    
61
65
Returns: 3
In this range there are three childless numbers: 62, 63, and 65. For the other two we have 732 / (7+3+2) = 732/12 = 61 and 320 / (3+2+0) = 320/5 = 64.
3)

    
275
300
Returns: 1
The only childless number in this range is 276.
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


class ChildlessNumbers {
public:
  int funcD(long long x){
		int sum = 0;
		while(x>0){
			sum += x%10;
			x /= 10;
		}
		return sum;
	}
	
	int howMany(int A, int B) {	
		int ans = 0;
		for(long long i=A; i<=B; ++i){	
			bool hasChild = false;
			for(int k=1; k<=108; ++k){
				long long tmp = i*k;
				if( funcD(tmp) == k ){
					hasChild = true;
					break;
				}
			}
			if(!hasChild)
				++ans;
		}
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
