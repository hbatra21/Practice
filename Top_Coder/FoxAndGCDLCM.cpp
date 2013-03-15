/*

Problem Statement
    
Fox Jiro and Eel Saburo are good friends. One day Saburo found two interesting positive integers: A and B.
 
On the next day, Saburo met Jiro and wanted to tell him the two integers. However, he managed to forget their values. All Saburo could remember was their greatest common divisor G and their least common multiple L.
 
You are given two long longs: G and L. Find the original integers A and B, and return the value of A+B. If there are multiple pairs of A and B that correspond to G and L, pick the one that minimizes A+B. If it is impossible to find such A and B (i.e., Saburo made a mistake somewhere), return -1.
Definition
    
Class:
FoxAndGCDLCM
Method:
get
Parameters:
long long, long long
Returns:
long long
Method signature:
long long get(long long G, long long L)
(be sure your method is public)
    

Notes
-
The greatest common divisor of two integers a and b is the largest positive integer that divides both a and b without any remainder.
-
The least common multiple of two integers a and b is the smallest positive integer that is a multiple of both a and b.
Constraints
-
G will be between 1 and 1,000,000,000,000 (10^12), inclusive.
-
L will be between 1 and 1,000,000,000,000 (10^12), inclusive.
Examples
0)

    
2
20
Returns: 14
The possible pairs of A and B are {2, 20} and {4, 10}. We need to pick {4, 10} since 4+10 is the smallest sum of A and B.
1)

    
5
8
Returns: -1
There are no pairs of A and B such that their greatest common divisor is 5 and their least common multiple is 8.
2)

    
1000
100
Returns: -1

3)

    
100
1000
Returns: 700

4)

    
10
950863963000
Returns: 6298430

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


class FoxAndGCDLCM {
public:
  long long get(long long G, long long L) {
		if(G>L || (L/G)*G!=L)
			return -1;
		vector<int> factors;
		long long tmp = L/G;
		long long i = 2;
		
		//factor
		while(tmp>=i){
			if( (tmp/i)*i == tmp ){
				factors.push_back(i);
				tmp = tmp/i;
			}
			else
				++i;
		}
		
		//accumulate same factors
		vector<int> factors2;
		long long last=factors[0], mul=factors[0];
		for(int j=1; j<factors.size()+1; ++j){
			if(last==factors[j]){
				mul *= factors[j];
			}
			else{
				factors2.push_back(mul);
				mul = factors[j];
				last = factors[j];
			}
		}
		

		//brute force search
		long long ans = 100000000;
		for(int i=0; i<(1<<factors2.size()); ++i){
			long long A=G, B=G;
			for(int j=0; j<factors2.size(); ++j){
				if ((i>>j)&1)
					A *= factors2[j];
				else
					B *= factors2[j];
			}
			ans = min(A+B, ans);
		}
		
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
