/*

Problem Statement
    
There are N friends sitting in a circle, numbered clockwise in increasing order from 1 to N. At the beginning of the game, player 1 receives a ball. The players take turns passing the ball to each other. At the beginning of the game and before each next pass the following actions are performed. If the player with the ball has already received the ball M times, the game is over. Otherwise, if the player has received the ball p times, he'll pass the ball directly to the person L places to his left if p is even, or L places to his right if p is odd (see examples for clarification). Given N, M and L, return the number of times that the ball is passed.
Definition
    
Class:
ThrowTheBall
Method:
timesThrown
Parameters:
int, int, int
Returns:
int
Method signature:
int timesThrown(int N, int M, int L)
(be sure your method is public)
    

Constraints
-
N will be between 3 and 50, inclusive.
-
M will be between 1 and 50, inclusive.
-
L will be between 1 and N-1, inclusive.
Examples
0)

    
5
3
2
Returns: 10
First, player 1 gets the ball. Since he has held the ball 1 time, he passes the ball to player 4, who is two places to his right. This is player 4's first time holding the ball, so he gives it to player 2, who passes it to player 5. Player 5 then passes the ball to player 3, who passes it back to player 1. Since player 1 has now held the ball 2 times, he passes it to player 3, who passes it to player 5, who then passes the ball to player 2. Finally, player 2 passes the ball to player 4, who then passes it to player 1. Player 1 has now held the ball 3 times, and the game ends.
1)

    
4
1
3
Returns: 0
Here, the ball is never passed.
2)

    
10
3
5
Returns: 4

3)

    
15
4
9
Returns: 15

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


class ThrowTheBall {
public:
  int timesThrown(int N, int M, int L) {
		int i=0, ans=0;
		vector<int> times;
		for(int i=0; i<N; ++i)
			times.push_back(0);
		
		while(true){
			++times[i];
			if(times[i]>=M)
				return ans;
				
			//pass
			++ans;
			if(times[i]%2==0){
				i = (i - L);
				if(i<0)
				 i += N;
			}
			else
				i = (i + L)%N;
		}
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
