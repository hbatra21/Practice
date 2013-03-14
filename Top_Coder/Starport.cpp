/*

Problem Statement
    
A new starport has just started working. Starting from some moment of time (call it minute 0), a new spaceship arrives at the starport every M minutes. In other words, spaceships arrive at the starport at minutes 0, M, 2*M, 3*M and so on.  Similarly, starting from minute 0 and repeating each N minutes, all arrived spaceships that are still placed at the port are teleported to the shed. If a spaceship arrives at the exact same minute when such a teleportation happens, it will be teleported immediately. Otherwise it will need to wait until the next teleportation happens.  Let the waiting time of a spaceship be the time between its arrival and its teleportation to the shed. Return the average waiting time of a spaceship in minutes. See notes for an exact definition.
Definition
    
Class:
Starport
Method:
getExpectedTime
Parameters:
int, int
Returns:
double
Method signature:
double getExpectedTime(int N, int M)
(be sure your method is public)
    

Notes
-
Let W(i) be the waiting time for the spaceship that arrives at minute M * i. The average waiting time can be defined as the limit of (W(0) + W(1) + ... + W(P - 1)) / P when P tends to positive infinity. This limit will always exist.
-
The returned value must have an absolute or relative error less than 1e-9.
Constraints
-
N and M will each be between 1 and 1,000,000,000, inclusive.
Examples
0)

    
4
2
Returns: 1.0
Spaceships arrive at the starport at minutes 0, 2, 4, 6, 8, and so on. Teleportations are done at minutes 0, 4, 8, and so on. The waiting times for the spaceships are, correspondingly, 0, 2, 0, 2, 0, and so on, so the expected waiting time is 1.
1)

    
5
3
Returns: 2.0

2)

    
6
1
Returns: 2.5

3)

    
12345
2345
Returns: 6170.0

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


class Starport {
public:
  double getExpectedTime(int N, int M) {
		vector<int> waitTime;
		int in=0, im=0;
		while(true){
			if(im*M==in*N){
				waitTime.push_back(0);
				if(waitTime.size()>1){
					break;	//got a cycle
				}
				++im;++in;
			}
			if(im*M<in*N){
				waitTime.push_back(in*N-im*M);
				++im;
			}
			else
				++in;
		}
		
		int sum = std::accumulate( waitTime.begin(), waitTime.end(), 0 );
		return (double)sum/(double)(waitTime.size()-1);
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
