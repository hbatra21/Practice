/*

Problem Statement
    
John is obsessed with security. He has several old houses and he wants to build a new one. John is very afraid of thieves, so he will choose the location of the new house using the following rule. There should be at least one old house directly to the North of the new one (i.e., with the same x coordinate and a greater y coordinate), at least one directly to the South, at least one directly to the West and at least one directly to the East.
You are given the locations of John's old houses in vector <int>s x and y. The i-th old house is located at (x[i], y[i]). Return the number of possible locations for the new house.
Definition
    
Class:
TheNewHouseDivTwo
Method:
count
Parameters:
vector <int>, vector <int>
Returns:
int
Method signature:
int count(vector <int> x, vector <int> y)
(be sure your method is public)
    

Notes
-
Several houses can be located at the same point.
Constraints
-
x will contain between 1 and 50 elements, inclusive.
-
x and y will contain the same number of elements.
-
Each element of x will be between -100 and 100, inclusive.
-
Each element of y will be between -100 and 100, inclusive.
Examples
0)

    
{-1, 1, 0, 0}
{0, 0, -1, 1}
Returns: 1
The origin (0, 0) is the only possible location for the new house.
1)

    
{4, 5, 0, 8, -3, 5, 4, 7}
{9, -4, 2, 1, 1, 11, 0, 2}
Returns: 4
Here the possible locations are (4, 1), (4, 2), (5, 1) and (5, 2).
2)

    
{4, 4, 4}
{7, 7, 7}
Returns: 0
All the houses are at the same point.
3)

    
{1, 7, 3, 4, 9, 3, 7, 1, 1, 6, 1, 6, 1, 9, 7, 9, 4, 9, 1, 4, 7, 1, 2, 5, 3, 8, 7, 7, 1}
{7, 2, 8, 9, 4, 3, 4, 1, 4, 1, 7, 8, 1, 1, 1, 4, 7, 1, 9, 4, 9, 1, 4, 1, 1, 1, 2, 4, 3}
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


class TheNewHouseDivTwo {
public:
  int count(vector <int> x, vector <int> y) {
		int xmin = *min_element(x.begin(), x.end());
		int xmax = *max_element(x.begin(), x.end());
		int ymin = *min_element(y.begin(), y.end());
		int ymax = *max_element(y.begin(), y.end());
		
		int ans = 0;
		for(int ix=xmin+1; ix<xmax; ++ix){
			for(int iy=ymin+1; iy<ymax; ++iy){
				bool W=false, E=false, S=false, N=false;
				for(int i=0; i<x.size(); ++i){
					if(x[i]==ix && y[i]>iy)
						N = true;
					if(x[i]==ix && y[i]<iy)
						S = true;
					if(x[i]>ix && y[i]==iy)
						E = true;
					if(x[i]<ix && y[i]==iy)
						W = true;
				}
				if(W && E && S && N){
					++ans;
				}
			}
		}
		
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
