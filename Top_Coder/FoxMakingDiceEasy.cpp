/*

Problem Statement
    
Fox Jiro likes dice. He wants to make his own dice. Each die he wants to make is a cube. Each of the 6 faces has an integer between 1 and N, inclusive. No two faces have same number. Also the following condition must be satisfied: for all faces, the sum of the numbers on opposite faces must be equal and the sum must be greater than or equal to K.
 
He realized that there are many ways to make such dice. He wants to know how many ways there are. Please help Jiro to make a program that is given two integers N and K and returns the number of different dice satisfying the condition mentioned above.
 
Two dice are considered the same if you can rotate one to form the other.
Definition
    
Class:
FoxMakingDiceEasy
Method:
theCount
Parameters:
int, int
Returns:
int
Method signature:
int theCount(int N, int K)
(be sure your method is public)
    

Notes
-
The answer will always fit in a signed 32-bit integer.
Constraints
-
N will be between 1 and 50, inclusive.
-
K will be between 1 and 100, inclusive.
Examples
0)

    
6
7
Returns: 2
You can make normal dice. There are two ways to arrange the numbers.
1)

    
5
7
Returns: 0
You cannot make 6 sided dice with 5 numbers.
2)

    
50
1
Returns: 105800

3)

    
31
46
Returns: 504

4)

    
10
10
Returns: 48

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


class FoxMakingDiceEasy {
public:
  int theCount(int N, int K) {
		if(N<6)
			return 0;
		    int result = 0;
	    for (int i0 = 1; i0 <= N; i0++) {
	      for (int i1 = i0 + 1; i1 <= N; i1++) {
	        for (int i2 = i1 + 1; i2 <= N; i2++) {
	          for (int i3 = i2 + 1; i3 <= N; i3++) {
	            for (int i4 = i3 + 1; i4 <= N; i4++) {
	              for (int i5 = i4 + 1; i5 <= N; i5++) {
	                int s0 = i0 + i5;
	                int s1 = i1 + i4;
	                int s2 = i2 + i3;
	                if (s0 >= K && s1 >= K && s2 >= K && s1 == s0 && s0 == s2) {
	                  result++;
	                }
	              }
	            }
	          }
	        }
	      }
	    }
	    return result * 2;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
