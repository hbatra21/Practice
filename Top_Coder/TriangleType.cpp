/*

Problem Statement
    
In Euclidean Geometry, triangles can be categorized into one of three types based on their angle measures. A triangle is acute if all three angles are less than 90 degrees. A triangle is obtuse if one angle is greater than 90 degrees. Lastly, a triangle with one angle at exactly 90 degrees is a right triangle.  It could also be the case that three positive integers can not possibly form the side-lengths of a triangle. This happens when the length of one side is equal to or larger than the sum of the lengths of the other two sides, because it would not be possible to connect the end points of the three sides in such a way that a triangle was formed.  Write a method that takes as input three positive integer side-lengths of a triangle. Return "IMPOSSIBLE" if a triangle cannot be formed. Return "ACUTE" if the triangle is acute, "OBTUSE" if the triangle is obtuse, and "RIGHT" if the triangle is right.
Definition
    
Class:
TriangleType
Method:
type
Parameters:
int, int, int
Returns:
string
Method signature:
string type(int a, int b, int c)
(be sure your method is public)
    

Notes
-
For a triangle with side-lengths x, y, and z and x <= y <= z. * The triangle is right if x*x + y*y = z*z. * The triangle is obtuse if x*x + y*y < z*z. * The triangle is acute if x*x + y*y > z*z. * It is impossible to have x + y <= z.
Constraints
-
a, b, and c are between 1 and 10,000, inclusive.
Examples
0)

    
3
4
5
Returns: "RIGHT"

1)

    
3
4
4
Returns: "ACUTE"

2)

    
3
4
6
Returns: "OBTUSE"

3)

    
7
4
3
Returns: "IMPOSSIBLE"

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


class TriangleType {
public:
  string type(int a, int b, int c) {
		if(a>=b+c || b>=a+c || c>=a+b)
			return "IMPOSSIBLE";
		
		if(a*a==b*b+c*c || c*c==a*a+b*b || b*b==a*a+c*c)
			return "RIGHT";
			
		if(a*a>b*b+c*c || c*c>a*a+b*b || b*b>a*a+c*c)
			return "OBTUSE";
		
		return "ACUTE";
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
