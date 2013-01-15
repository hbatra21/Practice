/*

Problem Statement
    
Percy has just received a new game called Penguin Tiles. The game is played on a rectangular grid. Except for one square, each square of the grid contains a tile with a part of an image of a penguin. The one remaining square is empty, and it is called the open square. The player is allowed to slide one of the tiles adjacent to the open square onto the open square. After several moves the tile game is supposed to form a picture with the bottom right corner containing the open square.
 
Percy's version of Penguin Tiles is a misprint. Instead of each tile containing a different part of a penguin all tiles contain an image of the same penguin. In other words each pair of tiles in Percy's Penguin Tiles is indistinguishable.
 
Percy has decided to play with the game anyway but instead of moving just one tile at a time he has decided to move several tiles at once. In one move, Percy can either move some consecutive vertical tiles one square vertically, or some consecutive horizontal tiles one square horizontally. Of course, one of the tiles has to be moved onto the open square. (In other words, instead of moving several tiles one at a time, Percy may move them all at once, if they all lie in the same row or in the same column.)
    
You are given a vector <string> tiles representing the game. The j-th character of the i-th element of tiles is 'P' if the square at row i, column j contains a tile, and it is '.' (a period) for the open square. Return the minimum number of moves to complete Percy's game.
Definition
    
Class:
PenguinTiles
Method:
minMoves
Parameters:
vector <string>
Returns:
int
Method signature:
int minMoves(vector <string> tiles)
(be sure your method is public)
    

Constraints
-
tiles will contain between 2 and 50 elements, inclusive.
-
Each element of tiles will contain between 2 and 50 characters, inclusive.
-
Each element of tiles will contain the same number of characters.
-
Each character of each element of tiles will be either 'P' or '.'.
-
tiles will contain exactly 1 occurrence of the character '.'.
Examples
0)

    
{"PP",
 "P."}
Returns: 0
The open tile is already in the bottom right corner.
1)

    
{"PPPPPPPP",
 ".PPPPPPP"}
Returns: 1

2)

    
{"PPP",
 "P.P",
 "PPP"}
Returns: 2

3)

    
{"P.",
 "PP",
 "PP",
 "PP"}
Returns: 1

4)

    
{".PPP",
 "PPPP",
 "PPPP",
 "PPPP"}
Returns: 2

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All ri
*/




#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


class PenguinTiles{
  public:
	int minMoves(vector<string> input){
		int i, j;
		int ex=input[0].size()-1, ey=input.size()-1, sx=0, sy=0;
		for(i=0; i<input.size(); ++i){
			for(j=0; j<input[i].length(); ++j){
				if(input[i][j] == '.'){
				    //capture the open slot
				    sx=j; sy=i;
				    //caculate the min steps
				    //return ( min(ex,sx) - max(ex,sx))%input[0].length()  +  ( min(ey,sy) - max(ey,sy) )%input.size();
				    int shortestx = min( (min(ex,sx) - max(ex,sx) + (int)input[0].size()), (max(ex,sx) - min(ex,sx)) );
				    int shortesty = min( (min(ey,sy) - max(ey,sy) + (int)input.size()),    (max(ey,sy) - min(ey,sy)) );
				    return shortestx + shortesty;
				}
			}
		}
		return -1; //infeasible
	} 


};
