/*

Problem Statement
    
John works at a company called "FIELD-Tech", and today, he was so tired after work that he fell asleep as soon as he got home. Unfortunately, even in his sleep, he was unable to forget about his work. In one dream, he was asked to help a carrot producing company deal with the following question: how many carrots grow on a line segment connecting two given carrots? The endpoints of the segment (i.e., the two given carrots) should not be included. It's a rather strange question, and to make it even stranger, the company's representatives (guys who have carrots instead of heads) said that all the carrots grow on an infinite plane, and there is exactly one carrot at each point with integer coordinates. You must help tired John deal with this problem.
The coordinates of the two carrots are (x1, y1) and (x2, y2). Return the number of carrots that lie strictly on the line segment connecting these carrots.
Definition
    
Class:
DreamingAboutCarrots
Method:
carrotsBetweenCarrots
Parameters:
int, int, int, int
Returns:
int
Method signature:
int carrotsBetweenCarrots(int x1, int y1, int x2, int y2)
(be sure your method is public)
    

Constraints
-
x1, y1, x2, and y2 will each be between 0 and 50, inclusive.
-
(x1, y1) and (x2, y2) will represent different points.
Examples
0)

    
1
1
5
5
Returns: 3
There are three points inside of the segment: (2,2), (3,3) and (4,4).
1)

    
0
0
1
1
Returns: 0

2)

    
50
48
0
0
Returns: 1

3)

    
0
0
42
36
Returns: 5

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


class DreamingAboutCarrots {
public:
  int carrotsBetweenCarrots(int x1, int y1, int x2, int y2) {
		int cnt = 0;
		for(int x=min(x1,x2)+1; x<max(x1,x2); ++x){
			for(int y=min(y1,y2)+1; y<max(y1,y2); ++y){
				if ((y-y1) * (x2-x1) == (y2-y1)*(x-x1))
					++cnt;
			}
		}
		return cnt;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

