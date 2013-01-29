/*

Problem Statement
    
Punctuality is not exactly one of Dr. Wesley's strengths. His student John always shows up for class at the scheduled starting time, but he never knows when Dr. Wesley will arrive. This is a problem for John because he cannot stay in the same place doing nothing for a long period of time. Therefore, he has come up with the following method to reduce the amount of time he spends waiting by the classroom door. 
John arrives at time 0.
John waits for Dr. Wesley to arrive.
If after waitTime seconds Dr. Wesley has not arrived yet, John goes to take a walk for walkTime seconds.
John therefore arrives back to the classroom exactly at time waitTime + walkTime.
If Dr. Wesley has not arrived yet, John waits another waitTime seconds and then proceeds to take a new walk. The process is repeated until John becomes aware that Dr. Wesley has arrived.
Overall, John stands in front of the class door from time 0 to time waitTime, inclusive, then from time walkTime + waitTime to time walkTime + 2*waitTime, inclusive, and so on. At all other time moments he walks outside.  This has solved John's patience issues, but it has caused a new problem. When John returns from a walk, if Dr. Wesley is already in the classroom, it will appear that John has arrived late to class. Dr. Wesley does not like that, and he will deny John access to the class if he arrives lateTime or more seconds after the time at which Dr. Wesley arrived.  There are multiple variables that affect Dr. Wesley's arrival time, but for the purpose of the problem, assume that the arrival time will be a real number chosen uniformly from bestArrival to worstArrival, inclusive. Return the probability that John will be denied access to Dr. Wesley's class.
Definition
    
Class:
LateProfessor
Method:
getProbability
Parameters:
int, int, int, int, int
Returns:
double
Method signature:
double getProbability(int waitTime, int walkTime, int lateTime, int bestArrival, int worstArrival)
(be sure your method is public)
    

Notes
-
The returned value must have an absolute or relative error less than 1e-9.
Constraints
-
waitTime, walkTime, lateTime and worstArrival will each be between 1 and 10000000, inclusive.
-
bestArrival will be between 0 and worstArrival, inclusive.
Examples
0)

    
20
30
10
0
50
Returns: 0.4
The professor will arrive at some random moment between 0 and 50 seconds, inclusive. During this interval, these are John's activities: 
He waits from time 0 to time 20, inclusive.
He takes a walk between times 20 and 50, non-inclusive.
He arrives back at time 50.
John will only be too late if the professor arrives while he is away, and more than 10 seconds before he returns. This only happens if the professor arrives strictly between times 20 and 40. The probability that this will happen is (40-20)/(50-0) = 0.4.
1)

    
20
30
10
30
100
Returns: 0.42857142857142855
If the professor arrives between 30 and 40 seconds or between 70 and 90 seconds, John will be late to the class.
2)

    
20
40
50
0
300
Returns: 0.0
John's walking time is 40 seconds. Hence, even if the professor arrives while John is taking a walk, John will always be less than 50 seconds late.
3)

    
101
230
10
654
17890
Returns: 0.6637270828498492

4)

    
20
30
10
90
90
Returns: 1.0
Dr. Wesley will always arrive at time 90 seconds. John will arrive at time 100 seconds after taking two different walks. Since the time difference is equal to 10 seconds, John will be too late.
5)

    
1000
600
1
17000
17000
Returns: 0.0

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


class LateProfessor {
public:
  double getProbability(int waitTime, int walkTime, int lateTime, int bestArrival, int worstArrival) {
		vector<int> interval;
		interval.push_back(0);
		int i=0;
		while (interval.back()<max(bestArrival, worstArrival)){
			if ( i%2==0){
				if (interval.back()+lateTime+waitTime<min(bestArrival, worstArrival))
					interval.push_back(0);
				else
					interval.push_back(max(interval.back()+lateTime+waitTime);
			}
			
			if (i%2==1){
				if (interval.back()+walkTime-min(lateTime, walkTime)<min(bestArrival, worstArrival))
					interval.push_back(0);
				else
					interval.push_back(interval.back()+walkTime-min(lateTime, walkTime));
			}
			
			++i;
		}
		int tmp = interval.back();
		interval.pop_back();
		interval.push_back(min(tmp, max(bestArrival, worstArrival)) );

		
		//take care of a special case that bestArrival == worstArrival;
		if (bestArrival == worstArrival){
			for (i=0; i<interval.size()-1; ++i){
				if (interval[i]<bestArrival && bestArrival<=interval[i+1])
					return (i%2)?1.0:0.0;
			}
		}
		
		//general case
		double g=0.0, b=0.0;
		for (i=0; i<interval.size()-1; ++i){
				tmp = interval[i+1] - interval[i];
				if (i%2)
					b +=tmp;
				else
					g +=tmp;
			
			if( started==-1 && interval[i]<=min(bestArrival, worstArrival) && min(bestArrival, worstArrival)<=interval[i+1] ){
				tmp = interval[i+1] - min(bestArrival, worstArrival);
				if (i%2)
					b +=tmp;
				else
					g +=tmp;
				started = 1;
			}
			
		}
		
		return b/(b+g);
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
