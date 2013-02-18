/*


Problem Statement
    
Ash is a marble collector and he likes to create various ornaments using his marbles.  One day, Elsh asks him to create a simple decoration for her desk. She wants a sequence of marbles consisting of at most two different colors. To make the sequence look interesting, each pair of adjacent marbles must have different colors.  Currently, Ash has R red marbles, G green marbles, and B blue marbles. Elsh wants that the resulting sequence is as long as possible. Return this maximum length.
Definition
    
Class:
MarbleDecoration
Method:
maxLength
Parameters:
int, int, int
Returns:
int
Method signature:
int maxLength(int R, int G, int B)
(be sure your method is public)
    

Constraints
-
R will be between 0 and 50, inclusive.
-
G will be between 0 and 50, inclusive.
-
B will be between 0 and 50, inclusive.
Examples
0)

    
0
0
0
Returns: 0
Ash currently doesn't have any marbles at all.
1)

    
3
0
0
Returns: 1
The only valid sequence is (red).
2)

    
5
1
2
Returns: 5
One possible sequence is (red, blue, red, blue, red).
3)

    
7
7
4
Returns: 14

4)

    
2
3
5
Returns: 7

5)

    
13
13
13
Returns: 26

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


class MarbleDecoration {
public:
  int maxLength(int R, int G, int B) {
		
		int c1, c2;
		if(R<=G && R<=B){
			c1 = G;
			c2 = B;
		}
		else if(G<=R && G<=B){
			c1 = R;
			c2 = B;
		}
		else if(B<=R && B<=G){
			c1 = R;
			c2 = G;
		}
		
		
		return (c1==c2)?min(c1,c2)*2:min(c1,c2)*2+1;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
