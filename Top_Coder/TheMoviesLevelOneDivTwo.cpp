/*

Problem Statement
    
John and Brus are going to a theater to see a very interesting movie. They would like to have seats next to each other in the same row. The theater contains n rows, with m seats in each row. Rows are numbered 1 to n from front to back, and seats are numbered 1 to m from left to right. Some of the seats are already reserved, but John and Brus can book any of the available seats.  You are given vector <int>s row and seat. The i-th elements of row and seat are the row number and seat number of the i-th reserved seat. All remaining seats are available. Return the number of ways for John and Brus to book two available seats next to each other in the same row.
Definition
    
Class:
TheMoviesLevelOneDivTwo
Method:
find
Parameters:
int, int, vector <int>, vector <int>
Returns:
int
Method signature:
int find(int n, int m, vector <int> row, vector <int> seat)
(be sure your method is public)
    

Notes
-
Two bookings are considered different only if one contains a seat that the other does not contain. In other words, they don't need to decide which seat John sits in and which seat Brus sits in.
Constraints
-
n and m will each be between 1 and 47, inclusive.
-
row will contain between 1 and 47 elements, inclusive.
-
row and seat will contain the same number of elements.
-
Each element of row will be between 1 and n, inclusive.
-
Each element of seat will be between 1 and m, inclusive.
-
All pairs (row[i], seat[i]) will be distinct.
Examples
0)

    
2
3
{1, 2}
{2, 3}
Returns: 1
The first and the second seat in the second row are the only two free seats next to each other in the same row.
1)

    
2
3
{1, 1, 1, 2, 2, 2}
{1, 2, 3, 1, 2, 3}
Returns: 0
There are no free seats in the theater.
2)

    
4
7
{1}
{1}
Returns: 23

3)

    
10
8
{1, 9, 6, 10, 6, 7, 9, 3, 9, 2}
{7, 7, 3, 3, 7, 1, 5, 1, 6, 2}
Returns: 54

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


class TheMoviesLevelOneDivTwo {
public:
  bool isTaken(int x, int y, vector <int> row, vector <int> seat){
		for(int i=0; i<row.size(); ++i){
			if(row[i]==y+1 && seat[i]==x+1)
				return true;
		}
		return false;
	}
	
	int find(int n, int m, vector <int> row, vector <int> seat) {
		int ans = 0;
		for(int y=0; y<n; ++y){
			for(int x=0; x<m-1; ++x){
				if(isTaken(x,y,row,seat)==false && isTaken(x+1,y,row,seat)==false)
					++ans;
			}
		}
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
