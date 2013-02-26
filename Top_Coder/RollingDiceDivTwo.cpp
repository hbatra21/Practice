/*

Problem Statement
    
Byteasar is playing a tabletop role-playing game with his friends. To determine the effectiveness of their heroes' actions the players use a rather unique set of dice which may have nonequal number of faces. Each die has between 1 and 9 faces, inclusive. If a die has m faces, they contain precisely all the values between 1 and m, inclusive. More precisely, for each k between 1 and m, inclusive, there is one face that shows exactly k pips. When a die is cast, every face has equal probability to come out on top.  Every time all the dice were thrown at once, Byteasar wrote down the numbers of pips visible on each of the topmost faces (in any order). The results of the i-th throw are given in throws[i]; the length of throws[i] is equal to the number of dice and each character of throws[i] denotes the number of pips visible on one of the topmost faces. For example, if throws[3][0]='7', this means that in throw 3 (0-based index) one of the dice showed exactly 7 pips on the top. Please note that the ordering of dice may be different for different throws.  Given the vector <string> throws containing Byteasar's notes, return the minimum possible total number of faces of all dice.
Definition
    
Class:
RollingDiceDivTwo
Method:
minimumFaces
Parameters:
vector <string>
Returns:
int
Method signature:
int minimumFaces(vector <string> rolls)
(be sure your method is public)
    

Notes
-
Please note that a die can have as few as one or two faces.
Constraints
-
rolls will contain between 1 and 50 elements, inclusive.
-
rolls[0] will contain between 1 and 50 characters, inclusive.
-
All elements of rolls will contain the same number of characters.
-
Each character in each element of rolls will be one of '1'-'9'.
Examples
0)

    
{"137", "364", "115", "724"}
Returns: 14
In the first throw the numbers of pips on the topmost faces of the dice were 1, 3 and 7; in the second throw they were 3, 6 and 4, in the third they were 1, 1 and 5 and in the fourth roll they were 7, 2 and 4. The players may have used dice with 3, 4 and 7 faces, giving a total of 14 faces. No other possible set of dice has less faces in total.
1)

    
{"1112", "1111", "1211", "1111"}
Returns: 5
The players could have used three dice with one face each and one die with two faces.
2)

    
{"24412", "56316", "66666", "45625"}
Returns: 30
The players could have used five dice with six faces each.
3)

    
{"931", "821", "156", "512", "129", "358", "555"}
Returns: 19

4)

    
{"3", "7", "4", "2", "4"}
Returns: 7

5)

    
{"281868247265686571829977999522", "611464285871136563343229916655", "716739845311113736768779647392", "779122814312329463718383927626",
"571573431548647653632439431183", "547362375338962625957869719518", "539263489892486347713288936885", "417131347396232733384379841536"}
Returns: 176

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


class RollingDiceDivTwo {
public:
  string mysort(string){
	
	}
	
	int minimumFaces(vector <string> throws) {
		vector < vector<int> > rolls;
		for(int i=0; i<throws.size(); ++i){
			vector<int> tmp;
			for(int j=0; j<throws[i].size(); ++j)
				tmp.push_back(throws[i][j]-'0');
				
			sort(tmp.begin(), tmp.end());
			rolls.push_back(tmp);
		}
		
		int ans = 0;
		for(int i=0; i<rolls[0].size(); ++i){
			int mymax = -1;
			for(int j=0; j<rolls.size(); ++j){
				mymax = max(mymax, rolls[j][i]);
			}
			ans += mymax;
		}
		
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
