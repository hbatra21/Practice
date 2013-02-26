/*

Problem Statement
    
Warning: This problem statement contains superscripts and/or subscripts. It may not display properly outside of the applet.
 In this problem we will consider binary polynomials. A binary polynomial can be written in the following form:  P(x) = a[0] * x0 + a[1] * x1 + ... + a[n] * xn  The values a[i] are integer constants (called coefficients). For a binary polynomial we must have a[n] = 1 and each other a[i] must be either 0 or 1. The number n is called the degree of the polynomial.  Several examples:
P(x) = 1 * x0 + 0 * x1 + 1 * x2 is a binary polynomial of degree 2.
P(x) = 0 * x0 + 1 * x1 + 0 * x2 + 1 * x3 is a binary polynomial of degree 3.
P(x) = 1 * x0 is a binary polynomial of degree 0.
P(x) = 0 * x0 + 3 * x1 - 1 * x2 is not a binary polynomial, because each coefficient must be a 0 or a 1.
P(x) = 0 * x0 is not a valid binary polynomial, because the last of the values a[i] must be 1.
We can evaluate a binary polynomial for the inputs x = 0 and x = 1. In order to do so, we just have to substitute 0 or 1 for x in the above expression, compute the value of the expression and take the remainder it gives when divided by two. For example, if P(x) = 1 * x0 + 0 * x1 + 1 * x2, then P(0) = 1 * 00 + 0 * 01 + 1 * 02 = 1 and P(1) = 1 * 10 + 0 * 11 + 1 * 12 = 0 (modulo 2). Note that in this problem we assume that x0 = 1 for all x. In particular, also 00 = 1.  We call an integer x (where x is 0 or 1) a root of the binary polynomial P if P(x) = 0. You are given a binary polynomial P as the array a of its coefficients. Return the number of roots of that binary polynomial.
Definition
    
Class:
BinaryPolynomialDivTwo
Method:
countRoots
Parameters:
vector <int>
Returns:
int
Method signature:
int countRoots(vector <int> a)
(be sure your method is public)
    

Constraints
-
The degree of P will be between 0 and 49, inclusive.
-
a will contain exactly n+1 elements, where n is the degree of P.
-
Each element of a will be either 0 (zero) or 1 (one).
-
a[n] will be equal to 1 (one).
Examples
0)

    
{1, 0, 1}
Returns: 1
The example from the problem statement. The only root of this binary polynomial is 1.
1)

    
{0, 1, 0, 1}
Returns: 2
This is the maximum possible answer; both 0 and 1 are roots of this binary polynomial.
2)

    
{1}
Returns: 0
This binary polynomial has no roots - it always evaluates to 1.
3)

    
{1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1}
Returns: 0

4)

    
{1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0,
 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1}
Returns: 1

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


class BinaryPolynomialDivTwo {
public:

  int mypow(int x,int i){
		return (i==0)?1:x;
	}
	
	int countRoots(vector <int> a) {
		int sum0 = 0;
		int sum1 = 0;
		for(int i=0; i<a.size(); ++i){
			sum0 += a[i]*mypow(0,i);
			sum1 += a[i]*mypow(1,i);
		}
		return ((sum0%2)==0)+((sum1%2)==0);
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
