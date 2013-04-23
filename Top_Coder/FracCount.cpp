/*

Problem Statement
    
It is possible to assign a unique integer value to each irreducible fraction between 0 and 1. (This shows that there are a countable infinity of fractions.) The usual way to number them is shown below

1/2  1/3  2/3  1/4  3/4  1/5  2/5  3/5  4/5  1/6  5/6  1/7  ...
 
Notice that 2/4, for example, does not get listed because it reduces to 1/2. Given an irreducible fraction we want to find where it appears in the above counting order, where 1/2 is counted as 1, 1/3 as 2, etc.
Create a class FracCount that contains a method position that is given the numerator and denominator of an irreducible fraction between 0 and 1 and that returns its position in the counting order.
Definition
    
Class:
FracCount
Method:
position
Parameters:
int, int
Returns:
int
Method signature:
int position(int numerator, int denominator)
(be sure your method is public)
    

Constraints
-
numerator will be between 1 and denominator - 1 inclusive.
-
denominator will be between 2 and 1,000 inclusive.
-
The greatest common divisor of numerator and denominator will be 1.
Examples
0)

    
1
2
Returns: 1
1/2 is at position 1 in the counting order
1)

    
5
6
Returns: 11
5/6 is at position 11 in the counting order
2)

    
999
1000
Returns: 304191

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


class FracCount {
public:
  int gcd(int a, int b){
	  int c;
	  while (a!=0) {
	     c=a; a=b%a;  b=c;
	  }
	  return b;
	}

	int position(int numerator, int denominator) {
		int cnt = 0;
		int i=1, j=2;
		while(true){
			if(gcd(i,j)==1){
				++cnt;
				if(i==numerator && j==denominator)
					break;
			}
			++i;
			if(i>=j){
				++j;
				i=1;
			}
		}
		return cnt;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
