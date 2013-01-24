/*

Problem Statement
    
Josh loves playing with blocks. Currently, he has N blocks, labeled 0 through N-1. The heights of all blocks are positive integers. More precisely, for each i, the height of block i is blockHeights[i]. Josh is interested in making the tallest block tower possible. He likes all his towers to follow three simple rules:
The blocks must be stacked in a single column, one atop another. The height of the tower is simply the sum of heights of all its blocks.
The labels of blocks used in the tower must increase from the bottom to the top. In other words, whenever Josh places box x on top of box y, we have x > y.
Josh will never place a box of an even height on top of a box of an odd height.
You are given the vector <int> blockHeights. Return the height of the tallest possible block tower Josh can build.
Definition
    
Class:
BlockTower
Method:
getTallest
Parameters:
vector <int>
Returns:
int
Method signature:
int getTallest(vector <int> blockHeights)
(be sure your method is public)
    

Constraints
-
blockHeights will contain between 1 and 50 elements, inclusive.
-
Each element of blockHeights will be between 1 and 50, inclusive.
Examples
0)

    
{4,7}
Returns: 11
The optimal tower contains both blocks. Block 0 is on the bottom of the tower.
1)

    
{7,4}
Returns: 7
This time the optimal tower contains just block 0. Josh cannot put block 1 on top of it, because 4 is even and 7 is odd.
2)

    
{7}
Returns: 7

3)

    
{4}
Returns: 4

4)

    
{48,1,50,1,50,1,48}
Returns: 196
Note that in a valid tower the labels of the blocks have to increase from bottom to top. Their heights do not have to. In this case the optimal tower consists of blocks 0, 2, 4, and 6, in this order. Its total height is 48 + 50 + 50 + 48 = 196.
5)

    
{49,2,49,2,49}
Returns: 147

6)

    
{44,3,44,3,44,47,2,47,2,47,2}
Returns: 273

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


class BlockTower {
public:
  int getTallest(vector <int> H) {
		int res = 0;
		for(int i=0; i<(1<<H.size()); ++i){
			vector<int> tmp;
			int last = -1;
			for(int j=0; j<H.size(); ++j){
				if ( (i>>j)&1 ){
					if ( last>-1 && ((last%2)==1) && ((H[j]%2)==0) ){
						tmp.clear();
						break;
					}
					else{
						tmp.push_back(H[j]);
						last = H[j];
					}
				}
			}
			if (tmp.size()>0){
				res = max(res, accumulate(tmp.begin(), tmp.end(), 0));
			}
		}
		return res;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
