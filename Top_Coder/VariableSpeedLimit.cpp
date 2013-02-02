/*

Problem Statement
    
In order to make its roads safer, the government of a particular country has decided to introduce a speed limit that varies throughout the day. At busy times, the speed limit will decrease to reduce the risk of a dangerous accident. You need to drive a distance of journeyLength units and want to know how long it will take you.
You are given details of the speed limit in a vector <int> speedLimit. Element i (zero-based) gives the speed limit in DISTANCE UNITS/TIME UNITS that is in force between times T = i and T = i + 1. speedLimit describes the speed limit for a full day, so after this the pattern repeats (i.e., if N is the number of elements in speedLimit, the speed limit between times N and N+1 is given by speedLimit[0], etc.). You start your journey at time T = 0 and should assume that you travel exactly at the speed limit for your entire journey. Return a double containing the amount of time it takes to complete your journey.
Definition
    
Class:
VariableSpeedLimit
Method:
journeyTime
Parameters:
int, vector <int>
Returns:
double
Method signature:
double journeyTime(int journeyLength, vector <int> speedLimit)
(be sure your method is public)
    

Notes
-
Your return value must be accurate to an absolute or relative tolerance of 1E-9.
Constraints
-
journeyLength will be between 1 and 100000 (10^5), inclusive.
-
speedLimit will contain between 1 and 50 elements, inclusive.
-
Each element of speedLimit will be between 1 and 100, inclusive.
Examples
0)

    
100
{50}
Returns: 2.0
Here the speed limit doesn't change. The journey therefore takes a time of DISTANCE/SPEED = 100/50 = 2 time units.
1)

    
100
{50,25}
Returns: 2.5
Now the speed limit drops to 25 every other time unit. You drive 50 units in the first time unit and 25 in the second. You reach the end of your journey halfway through the third time unit.
2)

    
1000
{50,40,30,40,50}
Returns: 24.0

3)

    
2058
{80,43,57,23,28,45,60,75,73,80}
Returns: 37.4

4)

    
17216
{26,30,62,55,51,56,58,4,60,23,31}
Returns: 415.03333333333336

5)

    
9839
{45,90,13,4,81,50,81,10,64,86,69}
Returns: 182.8395061728395

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


class VariableSpeedLimit {
public:
  double journeyTime(int journeyLength, vector <int> speedLimit) {
		
		double ans = 0;
		int i=0;
		while(journeyLength >0){
			journeyLength -= speedLimit[i%speedLimit.size()];
			++ans;
			++i;
		}
		return ans + (double)journeyLength/(double)speedLimit[(i-1)%speedLimit.size()];
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
