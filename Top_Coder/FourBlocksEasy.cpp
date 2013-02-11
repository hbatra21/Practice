/*

Problem Statement
    
NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.  "4Blocks" is a two player cooperative game played on a special board. The board is a grid composed of 1x1 square cells. The grid is two cells high. There are two different kinds of blocks: '1' blocks and '4' blocks. '1' blocks are 1x1, and '4' blocks are 2x2:  
 
 You must place blocks on the board so that their sides are aligned to the grid lines and no two blocks overlap. The final score is the sum of the values in each cell. '1' blocks are worth 1 point, and '4' blocks are worth 16 points because they cover 4 cells and each cell is worth 4 points.  Your friend has taken his turn and placed a number of '1' blocks on the board. The current configuration is given in the vector <string> grid. The j-th character of the i-th element of grid is '.' if the cell at row i, column j is empty, and '1' if your friend placed a '1' block in that cell. It is now your turn, and you can place any number of '1' or '4' blocks on the board, but you cannot remove any of the blocks that have already been placed. Return the maximum score that can be achieved. For example, the following images show one possible starting state, and the optimal placement of blocks from that state:     The final score would be 4*16 + 6*1 = 70.
Definition
    
Class:
FourBlocksEasy
Method:
maxScore
Parameters:
vector <string>
Returns:
int
Method signature:
int maxScore(vector <string> grid)
(be sure your method is public)
    

Constraints
-
grid will contain exactly 2 elements.
-
Each element of grid will contain between 1 and 50 characters, inclusive.
-
All elements of grid will contain the same number of characters.
-
Each element of grid will contain only '.' or '1' (one).
Examples
0)

    
{".....1..1..",
 "..1.....1.."}
Returns: 70
This is the example from the statement.
1)

    
{"....................",
 "...................."}
Returns: 160
We can fit ten '4' blocks in this setup.
2)

    
{".1.........11.........",
 "..1.1......11........."}
Returns: 128

3)

    
{"......1.....1...1.",
 ".................."}
Returns: 108

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


class FourBlocksEasy {
public:
  int maxScore(vector <string> grid) {
		int ans = 0;
		for(int i=0; i<grid[0].size(); ++i){
			if(grid[0][i]=='1' || grid[1][i]=='1')
				ans += 2;
			else if(i==grid[0].size()-1)
				ans += 2;
			else if(grid[0][i]=='.' && grid[1][i]=='.' && grid[0][i+1]=='.' && grid[1][i+1]=='.'){
				ans += 16;
				++i;
			}
			else
				ans += 2;
		}
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
