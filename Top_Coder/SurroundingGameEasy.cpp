/*

Problem Statement
    
Surrounding Game is a single-player game played on a rectangular grid of cells. Cells are considered adjacent if they share a common side. (Hence, each cell has at most four adjacent cells. The cells on the sides and in the corners of the grid have fewer adjacent cells than the ones inside the grid.)  The game is played by placing stones into some of the cells. Each cell may only contain at most one stone. A cell is called dominated if at least one of the following two conditions holds:
The cell contains a stone.
All cells adjacent to the cell contain stones.
 Each cell of the grid contains two numbers, each from 0 to 9, inclusive: the cost of placing a stone into the cell, and the benefit from dominating the cell. At the end of the game, the overall score of the player is the sum of all benefits minus the sum of all costs.  You are given the vector <string>s cost and benefit. The characters cost[i][j] and benefit[i][j] represent the two digits written in the cell (i,j). For example, if character 7 of element 4 of cost is '3', the cost of placing a stone into the cell (4,7) is 3.  You are also given a vector <string> stone that describes the final state of the game. The character stone[i][j] is 'o' (lowercase letter oh) if the cell (i,j) contains a stone. Otherwise, stone[i][j] is '.' (a period). Calculate and return the overall score of the game.
Definition
    
Class:
SurroundingGameEasy
Method:
score
Parameters:
vector <string>, vector <string>, vector <string>
Returns:
int
Method signature:
int score(vector <string> cost, vector <string> benefit, vector <string> stone)
(be sure your method is public)
    

Constraints
-
cost will contain between 2 and 20 elements, inclusive.
-
cost, benefit and stone will each contain the same number of elements.
-
Each element of cost will contain between 2 and 20 characters, inclusive.
-
Each element of cost will contain the same number of characters.
-
Each element of benefit and stone will contain the same number of characters as each element of cost.
-
Each character in cost and benefit will be a digit ('0'-'9').
-
Each character in stone will either 'o' (lowercase letter oh) or '.'.
Examples
0)

    
{"21","12"}
{"21","12"}
{".o","o."}
Returns: 4
All the cells are dominated, so the overall benefit is 2+1+1+2 = 6. Only two of the cells contain stones. The total cost of placing the stones is 1+1 = 2. Therefore the overall score is 6-2 = 4.
1)

    
{"99","99"}
{"11","11"}
{".o","o."}
Returns: -14
A player may get a negative score.
2)

    
{"888","888","888"}
{"000","090","000"}
{"...",".o.","..."}
Returns: 1

3)

    
{"4362","4321"}
{"5329","5489"}
{"...o","..o."}
Returns: 22

4)

    
{"5413","4323","8321","5490"}
{"0432","7291","3901","2310"}
{"ooo.","o..o","...o","oooo"}
Returns: -12

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*

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

class SurroundingGameEasy {
public:
  int score(vector <string> cost, vector <string> benefit, vector <string> stone) {
		int c = 0, b = 0;
		for(int i=0; i<stone.size(); ++i){
			for(int j=0; j<stone[0].size(); ++j){
				if (stone[i][j] == 'o'){
					c += int(cost[i][j])-48;
					b += int(benefit[i][j])-48;
				}
				else if ( ( i+1>stone.size()-1 || stone[i+1][j] == 'o') && (i-1<0 || stone[i-1][j] == 'o') && (j+1>stone[0].size()-1 || stone[i][j+1] == 'o') && (j-1<0 || stone[i][j-1] == 'o')  )
					b += int(benefit[i][j])-48;
			}
		}
		return b-c;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!/
