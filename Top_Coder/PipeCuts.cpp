/*

Problem Statement
    
A 100 meter long pipe must be cut in two places. It can only be cut at certain places, where it was originally welded from smaller pipes. If the two cut locations are chosen at random (each potential location has equal probability of being chosen), find the probability of a resulting pipe being longer than L meters.  Create a method named probability that accepts a int[] weldLocations and int L as parameters. It should calculate the probability of one or more resulting pipes being strictly longer than L if the two cut locations are chosen at random from weldLocations. Each element in weldLocations represents the number of meters from the left end of the pipe.
Definition
    
Class:
PipeCuts
Method:
probability
Parameters:
vector <int>, int
Returns:
double
Method signature:
double probability(vector <int> weldLocations, int L)
(be sure your method is public)
    

Notes
-
Your return value must have a relative or absolute error less than 1e-9.
Constraints
-
weldLocations will have between 2 and 50 elements, inclusive.
-
Each element in weldLocations will be between 1 and 99, inclusive.
-
weldLocations will not contain duplicate elements.
-
L will be between 1 and 100, inclusive.
Examples
0)

    
{25, 50, 75}
25
Returns: 1.0
Any random set of cuts results in a pipe being longer than 25 meters.
1)

    
{25, 50, 75}
50
Returns: 0.0
This time, it is impossible to cut the pipe such that some resulting pipe is longer than 50 meters.
2)

    
{25, 50, 75}
24
Returns: 1.0

3)

    
{99, 88, 77, 66, 55, 44, 33, 22, 11}
50
Returns: 0.7222222222222222

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


class PipeCuts {
public:
  double probability(vector <int> weldLocations, int L) {
		int Pcnt=0, Ncnt=0;
		sort(weldLocations.begin(), weldLocations.end());
		for (int i=0; i<weldLocations.size(); ++i){
			for (int j=i+1; j<weldLocations.size(); ++j){
				int tmp = (weldLocations[i]>L) + (weldLocations[j]-weldLocations[i]>L) + (100-weldLocations[j]>L);
				if(tmp>=1)
					++Pcnt;
				else
					++Ncnt;
			}
		}
		return double(Pcnt)/double(Pcnt+Ncnt);
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!


