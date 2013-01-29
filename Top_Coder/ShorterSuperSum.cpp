/*


Problem Statement
    
SuperSum is a function defined as: 
SuperSum(0 , n) = n, for all positive n.
SuperSum(k , n) = SuperSum(k-1 , 1) + SuperSum(k-1 , 2) + ... + SuperSum(k-1 , n), for all positive k, n.
Given k and n, return the value for SuperSum(k , n).
Definition
    
Class:
ShorterSuperSum
Method:
calculate
Parameters:
int, int
Returns:
int
Method signature:
int calculate(int k, int n)
(be sure your method is public)
    

Constraints
-
k will be between 1 and 14, inclusive.
-
n will be between 1 and 14, inclusive.
Examples
0)

    
1
3
Returns: 6
When k = 1, SuperSum is equal to the sum of the first n = 3 numbers: 1 + 2 + 3 = 6.
1)

    
2
3
Returns: 10
SuperSum(2 , 3) = SuperSum(1 , 1) + SuperSum(1 , 2) + SuperSum(1 , 3) = 1 + 3 + 6 = 10.
2)

    
4
10
Returns: 2002

3)

    
10
10
Returns: 167960

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


class ShorterSuperSum {
public:
  int memo[14][14];//since 1<=k,n<=14
	int mytry(int k, int n){
		if (k==0)
			return n;
		else{
			int tmp = 0;
			for(int i=1; i<=n; ++i){
				if (memo[k-1][i]==0)
					memo[k-1][i] = calculate(k-1,i);
				tmp += memo[k-1][i];
			}
			return tmp;
		}
	}
	
	int calculate(int k, int n) {
		for(int i=0; i<14; ++i){
			for(int j=0; j<14; ++j)
				memo[i][j] = 0;
		}
		return mytry(k,n);
	}
	
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
