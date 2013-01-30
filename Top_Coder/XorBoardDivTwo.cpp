/*

Problem Statement
    
Fox Jiro has a rectangular board, divided into a grid of square cells. Each cell in the grid contains either the character '0', or the character '1'. The vector <string> board contains the current state of the board. The j-th character of the i-th element of board is the character in row i, column j of the grid.
 
Jiro now has to make exactly two flips. In the first flip, he must pick a row and flip all characters in that row. (When flipped, a '0' turns to a '1' and vice versa.) In the second flip, he must pick a column and flip all characters in that column.
 
You are given the vector <string> board. Return the maximum number of '1's in the grid after Jiro makes the two flips.
Definition
    
Class:
XorBoardDivTwo
Method:
theMax
Parameters:
vector <string>
Returns:
int
Method signature:
int theMax(vector <string> board)
(be sure your method is public)
    

Constraints
-
board will contain between 1 and 50 elements, inclusive.
-
Each element of board will contain the same number of characters.
-
Each element of board will contain between 1 and 50 characters, inclusive.
-
Each character in board will be '0' or '1'.
Examples
0)

    
{"101",
 "010",
 "101"}
Returns: 9
Jiro can obtain 9 '1's by flipping the center row and then the center column.
1)

    
{"111",
 "111",
 "111"}
Returns: 5
Jiro has to make both flips, even if that decreases the number of '1's.
2)

    
{"0101001",
 "1101011"}
Returns: 9

3)

    
{"000",
 "001",
 "010",
 "011",
 "100",
 "101",
 "110",
 "111"}
Returns: 15

4)

    
{"000000000000000000000000",
 "011111100111111001111110",
 "010000000100000001000000",
 "010000000100000001000000",
 "010000000100000001000000",
 "011111100111111001111110",
 "000000100000001000000010",
 "000000100000001000000010",
 "000000100000001000000010",
 "011111100111111001111110",
 "000000000000000000000000"}
Returns: 105

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


class XorBoardDivTwo {
public:
  int theMax(vector <string> board) {
	
		int maxres = -1;
		for(int row=0; row<board.size(); ++row){
			for(int col=0; col<board[row].size(); ++col){
			
				vector <string> myboard;
				for(int i=0; i<board.size(); ++i)
					myboard.push_back(board[i]);
					
				//row flip
				for(int i=0; i<myboard[row].size(); ++i)
					myboard[row][i]=(myboard[row][i]=='1')?'0':'1';
		
				//col flip
				for(int i=0; i<myboard.size(); ++i)
					myboard[i][col]=(myboard[i][col]=='1')?'0':'1';

				//count "1"
				int res = 0;
				for(int i=0; i<myboard.size(); ++i){
					for(int j=0; j<myboard[0].size(); ++j){
						if(myboard[i][j]=='1')
							++res;
					}
				}
				
				maxres = max(maxres, res);
			}
		}
		return maxres;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
