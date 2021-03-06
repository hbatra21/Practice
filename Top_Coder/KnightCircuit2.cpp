/*

Problem Statement
    
The knight is a chess piece that moves by jumping: two cells in one direction, one in the other. Formally, a knight standing on the cell (x,y) can move to any of the following eight cells: (x+2,y+1), (x+2,y-1), (x-2,y+1), (x-2,y-1), (x+1,y+2), (x+1,y-2), (x-1,y+2), and (x-1,y-2). Of course, if the knight is close to the edge of the board, some of these cells might not be on the board. It is not allowed to jump to a cell that is not on the board.  A knight circuit is a sequence of cells on a chessboard that starts and ends with the same cell. Each consecutive pair of cells in the knight circuit must correspond to a single jump of the knight. The knight circuit may visit each cell arbitrarily many times. The size of a knight circuit is the number of different cells visited by the circuit.  You are given the ints w and h: the width (in columns) and the height (in rows) of a rectangular chessboard. Return the maximum knight circuit size that can be obtained on the given board. You are free to choose any cell as the start of your circuit.
Definition
    
Class:
KnightCircuit2
Method:
maxSize
Parameters:
int, int
Returns:
int
Method signature:
int maxSize(int w, int h)
(be sure your method is public)
    

Constraints
-
w and h will each be between 1 and 45000, inclusive.
Examples
0)

    
1
1
Returns: 1
Note that a sequence that consists of a single cell is considered to be a valid knight circuit.
1)

    
15
2
Returns: 8
If you start at any corner of the board, it is possible to move the knight to visit 8 cells, and then do the same moves in reverse in order to return to the starting cell. One possibility for the first eight cells of an optimal knight circuit is shown below:  
1...3...5...7..
..2...4...6...8
2)

    
100
100
Returns: 10000
It is possible to make a Knight circuit that contains all the cells on the board.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/



#include <algorithm>
using namespace std;

class KnightCircuit2{
  public:
	int maxSize(int row, int col){
		if (row>col) swap(row,col);
		
		//some special cases to be taken care of
		if (row==1)
			return 1;
		if (row==2)
			return (col+1)/2;
		if (row==3 && col==3)
			return 8;
		
		//for board larger than specified above, knight can reach every cell
		return row*col;
	}
};
