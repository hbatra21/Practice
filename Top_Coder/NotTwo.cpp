/*

Problem Statement
    
Bob has a width x height rectangular board divided into 1 x 1 cells. Rows of the board are numbered 0 to height-1 and columns are numbered 0 to width-1.  Each cell can contain at most one stone, and the Euclidean distance between each pair of stones must not equal 2. The Euclidean distance between cell in row x1, column y1 and cell in row x2, column y2 is defined as the square root from (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2).  Return the maximal number of stones he can place on the board.
Definition
    
Class:
NotTwo
Method:
maxStones
Parameters:
int, int
Returns:
int
Method signature:
int maxStones(int width, int height)
(be sure your method is public)
    

Constraints
-
width will be between 1 and 1000, inclusive.
-
height will be between 1 and 1000, inclusive.
Examples
0)

    
3
2
Returns: 4
He can place four stones on the board. Here is one possible arrangement: 
- * *
* * -
1)

    
3
3
Returns: 5
* - -
* * -
- * *
2)

    
8
5
Returns: 20

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


class NotTwo {
public:
  int board[1000][1000];
	int maxStones(int width, int height) {
		for(int i=0; i<1000; ++i){
			for(int j=0; j<1000; ++j)
				board[i][j] = 1;
		}
			
		for(int i=0; i<1000; ++i){
			for(int j=0; j<1000; ++j){
				if(board[i][j]==1){
					if(i>2)
						board[i-2][j] = 0;
					if(i+2<1000)
						board[i+2][j] = 0;
					if(j>2)
						board[i][j-2] = 0;
					if(j+2<1000)
						board[i][j+2] = 0;
				}
			}
		}
		int cnt = 0;
		for(int i=0; i<width; ++i){
			for(int j=0; j<height; ++j)
				cnt += board[i][j];
		}
		return cnt;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
