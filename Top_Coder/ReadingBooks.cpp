/*

Problem Statement
    
There are some books, each consisting of exactly three parts: introduction, story and edification. There is a reader who goes through the books and reads various parts. Each time he finishes reading a part, he adds the name of the part to the end of a list. He may read zero or more parts from each book, and he can read them in any order, but he cannot read each part more than once. Whenever he starts reading a new book, he can no longer go back and read any parts of books he has looked at previously.
You are given a vector <string> readParts containing the list created by the reader. Each element of readParts is "introduction", "story" or "edification" (quotes for clarity). Return the maximum possible number of books for which the reader has read all three parts.
Definition
    
Class:
ReadingBooks
Method:
countBooks
Parameters:
vector <string>
Returns:
int
Method signature:
int countBooks(vector <string> readParts)
(be sure your method is public)
    

Constraints
-
readParts will contain between 1 and 50 elements, inclusive.
-
Each element of readParts will be "introduction", "story" or "edification" (quotes for clarity).
Examples
0)

    
{"introduction", "story", "introduction", "edification"}
Returns: 1
It is possible that the reader has read the introduction from the first book and all 3 parts from the second one. Of course, it is also possible that he has read one part from four different books, but we are interested in the maximal number of books for which all 3 parts have been read.
1)

    
{"introduction", "story", "edification", "introduction", "story", "edification"}
Returns: 2
Two books have been read in their entirety.
2)

    
{"introduction", "story", "introduction", "edification", "story", "introduction"}
Returns: 1

3)

    
{"introduction", "story", "introduction", "edification", "story",
 "story", "edification", "edification", "edification", "introduction",
 "introduction", "edification", "story", "introduction", "story",
 "edification", "edification", "story", "introduction", "edification",
 "story", "story", "edification", "introduction", "story"}
Returns: 5

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


class ReadingBooks {
public:
  int countBooks(vector <string> readParts) {
		int ans = 0;
		for(int i=0; i<readParts.size()-2;){
			vector <string> tmp;
			tmp.push_back(readParts[i]);
			tmp.push_back(readParts[i+1]);
			tmp.push_back(readParts[i+2]);
			sort(tmp.begin(), tmp.end());

			if(tmp[0]=="edification" && tmp[1]=="introduction" && tmp[2]=="story"){
				++ans;
				++i;++i;++i;
			}
			else
				++i;
		}
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
