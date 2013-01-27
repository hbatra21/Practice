/*


Problem Statement
    
You are the Incubator. You have the ability to turn normal girls into magical girls.   There are n girls in the city. The girls are conveniently numbered 0 through n-1. Some girls love some other girls. Love is not necessarily symmetric. It is also possible for a girl to love herself.   You are given a vector <string> love. Character j of element i of love is 'Y' if girl i loves girl j. Otherwise, that character is 'N'. In the rest of the problem statement, we will use love[i][j] to denote the truth value of the statement "girl i loves girl j".   Each girl has two boolean properties: isMagical (is she a magical girl?) and isProtected (is she protected by some girl?). Initially, for each girl i we have isMagical[i] = False and isProtected[i] = False.   At any moment, you can choose an ordinary girl and turn her into a magical girl. That is, you can take a girl i such that isMagical[i] = False, and change isMagical[i] to True.   Each such change will trigger a series of events:
Each magical girl will protect all girls she loves: if isMagical[i] and love[i][j], then isProtected[j] is set to True.
Each protected girl will also protect all girls she loves: if isProtected[i] and love[i][j], then isProtected[j] is set to True.
Note that some of these changes may in turn trigger other changes, as more and more girls become protected.   Once there are no more changes, you can again change another ordinary girl into a magical one, and so on. Your goal is to reach a situation with many girls that are magical, but not protected. That is, you are interested in girls such that isMagical[i] = True and isProtected[i] = False. Return the maximum number of such girls in a situation that can be reached using the above process.
Definition
    
Class:
IncubatorEasy
Method:
maxMagicalGirls
Parameters:
vector <string>
Returns:
int
Method signature:
int maxMagicalGirls(vector <string> love)
(be sure your method is public)
    

Constraints
-
n will be between 1 and 10, inclusive.
-
love will contain exactly n elements.
-
Each element of love will contain exactly n characters.
-
Each character in each element of love will be either 'Y' or 'N'.
Examples
0)

    
{"NY","NN"}
Returns: 1
One optimal solution is to change girl 0 to a magical girl. Girl 0 will be magical and she will not be protected. It is not possible to have two girls that are both magical and not protected: if you change both girls to magical girls (in any order), you will get a situation in which girl 1 is protected.
1)

    
{"NYN", "NNY", "NNN"}
Returns: 1
Again, there is no way to create more than one unprotected magical girl. For example, if we start by making girl 2 magical, and then make girl 0 magical, magical girl 0 will protect girl 1, and protected girl 1 will protect girl 2. Thus, in this case girl 0 will be magical and unprotected, girl 1 will be ordinary and protected, and girl 2 will be magical and protected.
2)

    
{"NNYNN","NNYNN","NNNYY","NNNNN","NNNNN"}
Returns: 2

3)

    
{"NNNNN","NYNNN","NYNYN","YNYNN","NNNNN"}
Returns: 2

4)

    
{"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"}
Returns: 5

5)

    
{"Y"}
Returns: 0
Note that a girl may love herself.
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


class IncubatorEasy {
public:
  int g[10]; //00:normal; 01:M not P; 10: P not M; 11:M and P
	
	void transform(vector <string> love){
		while(true){
			int change = 0;
			for(int i=0; i<love.size(); ++i){
				for(int j=0; j<love.size(); ++j){
					if( ( (g[i]&1) || ((g[i]&2)>>1) ) && (love[i][j]=='Y') && (((g[j]&2)>>1)==0) ){
						g[j] |= 1<<1;
						change = 1;
					}
				}
			}
		if (change==0)
			break;
		}
	}
	
	
	int maxMagicalGirls(vector <string> love) {
		int ans = 0;	//if do not turn any girl into magical, return 0
		for(int i=1; i<(1<<love.size()); ++i){
			for(int j=0; j<love.size(); ++j)
				g[j] = 0;
			for(int j=0; j<love.size(); ++j){
				if((i>>j)&1){
					//turn j-th girl
					g[j] = 1;
					transform(love);
					int tmpcnt = 0;
					for(int k=0; k<love.size(); ++k){
						if(g[k]==1)
							++tmpcnt;
					}
					ans = max(ans, tmpcnt);
				}
			}
		}
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
