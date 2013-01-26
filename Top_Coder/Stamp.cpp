/*

Problem Statement
    
Little Fox Jiro has a rectangular board. On the board there is a row of N unit cells. The cells are numbered 0 through N-1 from the left to the right. Initially, the cells are not colored. Jiro must color each of the cells red, green, or blue.

You are given a string desiredColor with N characters. For each i, character i of desiredColor represents the color Jiro must use for cell i. If a character is one of 'R' (as red), 'G' (as green), and 'B' (as blue), it means that Jiro must use that particular color. If a character is '*', Jiro may use any of the three colors for the particular cell.

You are also given the ints stampCost and pushCost that describe the cost of the coloring process. The coloring process consists of two phases. In the first phase, Jiro must pick a single stamp he will then use to color all the cells. The length L of the stamp can be any integer between 1 and N, inclusive. A stamp of length L costs L*stampCost.

In the second phase, Jiro must repeatedly use the stamp to color the cells. Each use of the stamp works as follows:
Jiro picks one of the three colors and pushes the stamp into ink of the chosen color C.
Jiro picks a segment of L contiguous cells such that each of them is either uncolored or already has the color C. The segment must be completely inside the board. That is, the leftmost cell of the segment must be one of the cells 0 through N-L.
Jiro pushes the stamp onto the chosen segment of cells. All the cells now have color C.
Each use of the stamp costs pushCost.

Return the smallest possible total cost of coloring all the cells using the above process.
Definition
    
Class:
Stamp
Method:
getMinimumCost
Parameters:
string, int, int
Returns:
int
Method signature:
int getMinimumCost(string desiredColor, int stampCost, int pushCost)
(be sure your method is public)
    

Constraints
-
desiredColor will contain between 1 and 50 characters, inclusive.
-
Each character of desiredColor will be either 'R' or 'G' or 'B' or '*'.
-
stampCost will be between 1 and 100,000, inclusive.
-
pushCost will be between 1 and 100,000, inclusive.
Examples
0)

    
"RRGGBB"
1
1
Returns: 5
The optimal solution is to choose L=2 and then stamp three times: using red color for cells [0,1], green for [2,3], and blue for [4,5]. The stamp costs 2*1 = 2, each of the three uses costs 1, so the total costs is 2*1 + 3*1 = 5.
1)

    
"R**GB*"
1
1
Returns: 5
The optimal solution is the same as in the previous example. Note that you must color all the cells, so choosing L=1 and then using the stamp three times is not a valid solution.
2)

    
"BRRB"
2
7
Returns: 30
Also, note that once a cell is colored, you are not allowed to stamp over it using a different color. Therefore, you can only choose L=1 in this case.
3)

    
"R*RR*GG"
10
58
Returns: 204
It is allowed to stamp the same cell multiple times if all of those stamps use the same color.
4)

    
"*B**B**B*BB*G*BBB**B**B*"
5
2
Returns: 33

5)

    
"*R*RG*G*GR*RGG*G*GGR***RR*GG"
7
1
Returns: 30

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


class Stamp {
public:
  int getL(string desiredColor, char C){
		if(desiredColor.find(C)==-1)
			return 0;
		int res = 1<<16, cnt = 0;
		int flag = false; 										//exclude all "*" substrings
		for (int i=0; i<desiredColor.size(); ++i){
			if(desiredColor[i] == C || desiredColor[i] == '*'){
				++cnt;
				if (desiredColor[i] == C)
					flag = true;
			}
			else{
				if (flag)
				      res = min(res, cnt);
				cnt  = 0;
				flag = false;
			}
		}
		if (flag)
			res = min(res, cnt);
		return res;
	}
	
	//brute force
	int mytry(string desiredColor, int L, int stampCost, int pushCost){
		int i=0, j, cnt = 0;
		while(true){
			char base = desiredColor[i+0];
			for (j=0; j<L; ++j){
				if (base == '*')
					base = desiredColor[i+j];
				if ( desiredColor[i+j]=='*' || desiredColor[i+j]==base ){
					//pass
				}
				else
					break;
			}
			if (j==L){
				i += L;  ++cnt;
				if (i>=desiredColor.size())
					break;
			}
			else
				i += j-L;
		}
		return L*stampCost + pushCost*cnt;
	}

	int getMinimumCost(string desiredColor, int stampCost, int pushCost) {
		if (desiredColor.size()==0)
			return 0;
		int rl = getL(desiredColor, 'R'); rl = ((rl==0)?65535:rl);
		int gl = getL(desiredColor, 'G'); gl = ((gl==0)?65535:gl);
		int bl = getL(desiredColor, 'B'); bl = ((bl==0)?65535:bl);
		int L = min(min(rl,gl),bl);

		int res = desiredColor.size()*pushCost + stampCost;	//when L=1
		for(int l=2; l<=L; ++l){
			res = min(res, mytry(desiredColor, l, stampCost, pushCost));
		}
		return res;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
