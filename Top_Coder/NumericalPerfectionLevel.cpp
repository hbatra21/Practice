/*

Problem Statement
    
It is a well known fact that of all numbers, the number 4 is the most relevant. Patterns related to the number 4 tend to appear everywhere. For example, the numerical perfection level is closely related to the number 4.  We define the perfection level of a positive integer N as k if N can be expressed as a product of 4 positive integers, each with a perfection level of at least (k-1), and cannot be expressed as a product of 4 positive integers, each with a perfection level greater than (k-1). There is one exception - if it is not possible to express N as a product of 4 positive integers all greater than 1, then the perfection level of N is 0.  Given a long long N, return its perfection level.
Definition
    
Class:
NumericalPerfectionLevel
Method:
getLevel
Parameters:
long long
Returns:
int
Method signature:
int getLevel(long long N)
(be sure your method is public)
    

Constraints
-
N will be between 1 and 10000000000000 (10^13), inclusive.
Examples
0)

    
4
Returns: 0
4 cannot be expressed as a product of 4 numbers all greater than 1.
1)

    
144
Returns: 1
144 = 4 x 2 x 3 x 6 The level of 4, 2, 3 and 6 is 0.
2)

    
1152
Returns: 1
One of many possible ways to express 1152 is: 1152 = 144 x 2 x 2 x 2 Although 144's level is 1, the remaining factors are of level 0. There is no way to express 1152 as a product of four level 1 numbers.
3)

    
1679616
Returns: 2
1679616 = 36 x 36 x 36 x 36 36 = 2 x 2 x 3 x 3
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


class NumericalPerfectionLevel {
public:
  vector<int> factor(long long N){
		//get all prime factors
		vector<int> ans;
		if (N==0)
			ans.push_back(-1);
		else if (N==1)
			ans.push_back(1);
		else{
			int i=2;
			while(i<=N){
				if( (N/i)*i == N){
					ans.push_back(i);
					N = N/i;
				}
				else
					++i;
			}
		}
		return ans;
	}

	int getLevel(long long N) {
		
		vector<int> m = factor(N);
		if(m.size()<4)
			return 0;
			
		int cnt = m.size(), ans=0;
		while(cnt/4>0){
			//since 4 prime factors will increase the perfection level by one
			++ans;
			cnt /= 4;
		}
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
