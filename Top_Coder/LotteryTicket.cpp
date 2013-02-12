/*

Problem Statement
    
Nick likes to play the lottery. The cost of a single lottery ticket is price. Nick has exactly four banknotes with values b1, b2, b3 and b4 (some of the values may be equal). He wants to know if it's possible to buy a single lottery ticket without getting any change back. In other words, he wants to pay the exact price of a ticket using any subset of his banknotes. Return "POSSIBLE" if it is possible or "IMPOSSIBLE" if it is not (all quotes for clarity).
Definition
    
Class:
LotteryTicket
Method:
buy
Parameters:
int, int, int, int, int
Returns:
string
Method signature:
string buy(int price, int b1, int b2, int b3, int b4)
(be sure your method is public)
    

Constraints
-
price will be between 1 and 4000, inclusive.
-
b1, b2, b3 and b4 will each be between 1 and 1000, inclusive.
Examples
0)

    
10
1
5
10
50
Returns: "POSSIBLE"
Nick can use the banknote with value b3.
1)

    
15
1
5
10
50
Returns: "POSSIBLE"
Here he can use the banknotes with values b2 and b3.
2)

    
65
1
5
10
50
Returns: "POSSIBLE"
b2 + b3 + b4 is 65.
3)

    
66
1
5
10
50
Returns: "POSSIBLE"
All four banknotes must be used.
4)

    
1000
999
998
997
996
Returns: "IMPOSSIBLE"

5)

    
20
5
5
5
5
Returns: "POSSIBLE"
Some of the banknote values may be equal.
6)

    
2
1
5
10
50
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


class LotteryTicket {
public:
  string buy(int price, int b1, int b2, int b3, int b4) {
		for(int i=0; i<(1<<4); ++i){
			int tmp=0;
			if((i>>0)&1)
				tmp += b1;
			if((i>>1)&1)
				tmp += b2;
			if((i>>2)&1)
				tmp += b3;
			if((i>>3)&1)
				tmp += b4;
			
			if (tmp == price)
				return "POSSIBLE";
		}
		return "IMPOSSIBLE";
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
