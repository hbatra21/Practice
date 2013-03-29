/*

Problem Statement
    
A long time ago in a galaxy far, far away the Jedi Academy conducted a test to detect children with high Force sensitivy which would then be trained to become Jedi. The test was conducted in the Jedi Temple which had several floors. You are given a vector <int> students which has as many elements as there are floors in the building. For each i, students[i] is the number of children on the i-th floor (0-based index).  During the test, the children will be supervised by Yoda and possibly also by some other Jedi. Each Jedi, including Yoda, can only supervise children on one of the floors. Additionally, there is a limit on how many children a single Jedi may supervise: Yoda is able to supervise up to Y children, inclusive, and any other Jedi is able to supervise up to J children, inclusive. Each child has to be supervised by some Jedi.  For example: Yoda and a single other Jedi can supervise a floor that contains up to Y+J children. Two Jedi can supervise a floor that contains up to 2J children.  Find the minimum number of Jedi which were required to help Yoda so that every child at each floor was supervised. Note that Yoda may choose which floor he wants to supervise, and that the answer may sometimes be zero.
Definition
    
Class:
TheJediTestDiv2
Method:
countSupervisors
Parameters:
vector <int>, int, int
Returns:
int
Method signature:
int countSupervisors(vector <int> students, int Y, int J)
(be sure your method is public)
    

Constraints
-
students will contain between 1 and 50 elements, inclusive.
-
Each element in students will be between 0 and 1000, inclusive.
-
J will be between 1 and 999, inclusive.
-
Y will be between J+1 and 1000, inclusive.
Examples
0)

    
{10, 15}
12
5
Returns: 3
Yoda can supervise at most 12 children, so he can either supervise all kids on floor 0, or 12 out of the 15 children on floor 1. If Yoda supervises floor 0, we need three other Jedi on floor 1. If Yoda supervises a part of floor 1, we need one other Jedi on floor 1 and two more for floor 0. In either case, there have to be at least 3 Jedi other than Yoda.
1)

    
{11, 13, 15}
9
5
Returns: 7
In the optimal solution, Yoda will supervise either on floor 0 or on floor 1. In either case we need one Jedi to help him on his floor, and three Jedi for each of the other two floors. Note that if Yoda chooses floor 2, eight additional Jedi would be needed.
2)

    
{10}
100
2
Returns: 0
Yoda can handle the entire floor.
3)

    
{0, 0, 0, 0, 0}
145
21
Returns: 0
For the Jedi Academy, a bad day it was.
4)

    
{4, 7, 10, 5, 6, 55, 2}
20
3
Returns: 26

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


class TheJediTestDiv2 {
public:
  int countSupervisors(vector <int> students, int Y, int J) {
	
		int ans = 1<<20;
		for(int i=0; i<students.size(); ++i){
			int numJ = 0;
			for(int j=0; j<students.size(); ++j){
				if(i==j){
					if(students[j]>Y){
						numJ += ceil((float)(students[j]-Y)/(float)J);
					}
				}
				else
					numJ += ceil((float)students[j]/(float)J);
			}
			ans = min(ans, numJ);
		}
		
		return ans;
		
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
