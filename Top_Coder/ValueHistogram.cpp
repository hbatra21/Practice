/*
Problem Statement
    
A histogram of a given collection of numbers graphically represents the frequency of each value in the collection. We are given several numbers ranging from 0 to 9 as a vector <int> values. The goal is to build their histogram according to the following rules.  1) The width of the histogram should be exactly 10.  2) The height of the histogram should equal to H+1, where H is the number of times the most frequent element occurs in values.  3) The i-th (0-based) column of the histogram corresponds to the value i. Let X(i) be the frequency of value i in values. Then the last X(i) characters in the column should be 'X's and the other ones should be '.'s. For example, if value i was not present in values, the column should be filled with '.' characters. If i was present once, the last element of the column should be 'X' and and the other ones should be '.'s. If i was present twice, the last two elements should be 'X's and and the other ones should be '.'s, and so on.  Build the histogram and return it as a vector <string>.
Definition
    
Class:
ValueHistogram
Method:
build
Parameters:
vector <int>
Returns:
vector <string>
Method signature:
vector <string> build(vector <int> values)
(be sure your method is public)
    

Constraints
-
values will contain between 1 and 50 elements, inclusive.
-
Each element of values will be between 0 and 9, inclusive.
Examples
0)

    
{2, 3, 5, 5, 5, 2, 0, 8}
Returns: {"..........", ".....X....", "..X..X....", "X.XX.X..X." }
The most frequent value is 5, which occurs 3 times. Hence the height of the histogram is 4. It looks as follows:
..........
.....X....
..X..X....
X.XX.X..X.
1)

    
{9, 9, 9, 9}
Returns: {"..........", ".........X", ".........X", ".........X", ".........X" }
..........
.........X
.........X
.........X
.........X
2)

    
{6, 4, 0, 0, 3, 9, 8, 8}
Returns: {"..........", "X.......X.", "X..XX.X.XX" }
..........
X.......X.
X..XX.X.XX
3)

    
{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
Returns: {"..........", "XXXXXXXXXX" }
..........
XXXXXXXXXX
4)

    
{6, 2, 3, 3, 3, 7, 8, 1, 0, 9, 2, 2, 4, 3}
Returns: {"..........", "...X......", "..XX......", "..XX......", "XXXXX.XXXX" }
..........
...X......
..XX......
..XX......
XXXXX.XXXX
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/



#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class ValueHistogram{
  
	public:
	
	vector<string> build(vector<int> values){	
		int i, j, mymax=0;
		vector<string> res, res2;
		int stat[10] = {0};
		for (i=0; i < values.size(); ++i) {
			++stat[values[i]];
			mymax = max(mymax, stat[values[i]]);
		}

		for (i=0; i < 10; ++i) {
			string S = "";
			for (j=0; j<10; ++j) {
				if (stat[j]>i)
				  S.append("X");
				else
				  S.append(".");
			}
			res.push_back(S);

		if (i>mymax-1)
			break;
		}

		for (i=0; i < res.size(); ++i)
			res2.push_back(res[res.size()-1-i]);

		return res2;
	}
};
