/*

Problem Statement
    
We say that two integer numbers differ from each other by one digit, when in their decimal notation, possibly with leading zeros, they will differ in exactly one position. For example numbers 128 and 28 differ by one digit:
  128
	028
But numbers 2047 and 40 differ by two digits:
	2047
	0040
Given the number N, find and return the smallest possible non-negative number M, such that number N and M differ from each other by exactly one digit.
Definition
    
Class:
OneDigitDifference
Method:
getSmallest
Parameters:
int
Returns:
int
Method signature:
int getSmallest(int N)
(be sure your method is public)
    

Constraints
-
N will be between 0 and 2,000,000,000, inclusive.
Examples
0)

    
9
Returns: 0
0 is the smallest non-negative number and differs by only one digit.
1)

    
0
Returns: 1
The result number is not always smaller than N.
2)

    
900000123
Returns: 123
Leading zeros in the result are okay:
 900000123
 000000123
3)

    
30000
Returns: 0
Leading zeros are okay also with 0 as a result:
 30000
 00000
4)

    
47
Returns: 7

5)

    
1907654321
Returns: 907654321

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


class OneDigitDifference {
public:
  int getSmallest(int N) {

		stringstream out;
		out << N;
		string strN = out.str();

		if(strN.size()==1){
			if(N==0)
				return 1;
			else
				return 0;
		}
		
		strN[0] = '0';
		
		int value;
		stringstream(strN) >> value; 
		return value;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
