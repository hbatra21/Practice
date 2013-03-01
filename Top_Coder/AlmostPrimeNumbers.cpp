/*

Problem Statement
    
An integer N greater than 1 is called almost prime if and only if the following conditions hold:
N is not prime. In other words, it is divisible by some positive integer other than 1 and itself.
Each positive divisor of N (other than 1) is greater than 10.
Return the smallest almost prime number that is strictly greater than m.
Definition
    
Class:
AlmostPrimeNumbers
Method:
getNext
Parameters:
int
Returns:
int
Method signature:
int getNext(int m)
(be sure your method is public)
    

Constraints
-
m will be between 1 and 10^6, inclusive.
Examples
0)

    
200
Returns: 209
201 is divisible by 3, which is less than 10, so 201 is not almost prime. 202, 204, 206, and 208 are all divisible by 2. 203 is divisible by 7, 205 by 5, and 207 by 3. So, the smallest almost prime number greater than 200 is 209 = 11*19.
1)

    
666
Returns: 667
667 = 23*29, so it's almost prime.
2)

    
1000
Returns: 1003

3)

    
1591
Returns: 1633

4)

    
6
Returns: 121
The smallest almost prime number is 11*11 = 121.
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


class AlmostPrimeNumbers {
public:
  int getNext(int m) {
		if(m<=10)
			return 11*11;
		while(true){
			++m;		
			if(m%2==1){
				bool flag=true;	
				for(int i=3; i<=10; ++i){
					if(m==(m/i)*i){
						flag = false;
						break;
					}
				}
				if(flag){
					//see if it is a prime
					bool flag2=true;	
					for(int i=3; i<m; ++i){
						if(m==(m/i)*i){
							flag2 = false;
							break;
						}
					}
					if (flag2==false)
						return m;
				}
			}
		}
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
