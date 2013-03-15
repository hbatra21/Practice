/*

Problem Statement
    
You are the manager in charge of service at a restaurant. Over the course of an evening, groups of customers arrive and you need to allocate tables to them. The restaurant has tables of various sizes in order to cope with different sized groups. The tables are allocated as follows:
When a group of customers arrives, it is allocated the smallest unallocated table that is at least as big as the group. Apart from their sizes, tables are otherwise the same, so if there are multiple appropriate tables, one is allocated arbitrarily. If there is no appropriate table available when the group arrives, the group is immediately turned away, and it will not return again that evening. When a group finishes eating and leaves, its table becomes available again to be allocated to a new group of customers.
You want to know how many customers will be turned away using this method of allocating tables.
The sizes of the tables in the restaurant are given in a vector <int> tables, in which each element gives the size of a single table. The size, arrival time and departure time of group i will be represented by groupSizes[i], arrivals[i] and departures[i], respectively. The groups will be listed in the order that they arrive at the restaurant, and no two groups will arrive at the same time. If a group arrives at exactly the same time another group departs, the table of the departing group will be available to be allocated to the arriving group (see example 0). Return the number of customers who are turned away.
Definition
    
Class:
RestaurantManager
Method:
allocateTables
Parameters:
vector <int>, vector <int>, vector <int>, vector <int>
Returns:
int
Method signature:
int allocateTables(vector <int> tables, vector <int> groupSizes, vector <int> arrivals, vector <int> departures)
(be sure your method is public)
    

Constraints
-
tables will contain between 1 and 50 elements, inclusive.
-
Each element of tables will be between 1 and 20, inclusive.
-
groupSizes, arrivals and departures will each contain between 1 and 50 elements, inclusive.
-
groupSizes, arrivals and departures will each contain the same number of elements.
-
Each element of groupSizes will be between 1 and 20, inclusive.
-
Each element of arrivals and departures will be between 0 and 200, inclusive.
-
Element i of arrivals will be strictly less than element i of departures.
-
The elements of arrivals will be distinct and in increasing order.
Examples
0)

    
{4}
{4,8,4,2,2,4}
{0,10,12,16,18,26}
{10,20,18,26,36,28}
Returns: 14
This restaurant only has a single table that will seat 4 people. The first group of 4 arrives at time 0 and leaves at time 10. The next group also arrives at time 10, so the table is available, but the group is too big for the table so they are turned away. Another group of 4 then turns up at time 12 and is allocated the table until time 18. The group of 2 that turns up at time 16 is therefore turned away. Another group of 2 comes along at time 18, just as the table becomes available. They are still sitting as the final group comes along, so this group is also turned away. The total number of customers turned away is 8 + 2 + 4 = 14.
1)

    
{4,4}
{4,8,4,2,2,4}
{0,10,12,16,18,26}
{10,20,18,26,36,28}
Returns: 8
With 2 tables, the only group turned away is the group of size 8, which is too big for either table.
2)

    
{4,8}
{4,8,4,2,2,4}
{0,10,12,16,18,26}
{10,20,18,26,36,28}
Returns: 2
Now the restaurant has a table big enough for the group of size 8. A different group of size 2 is turned away later on because a table isn't available when they turn up.
3)

    
{10,8,11,16}
{14,1,15,1,19,15,9,15,20,2}
{4,5,7,18,21,25,29,31,46,49}
{8,37,11,36,36,46,40,42,47,50}
Returns: 69

4)

    
{18,15,2,6}
{7,9,16,3,10,3,2,10,16,16}
{10,15,19,20,21,22,27,35,37,43}
{13,24,22,32,32,32,35,48,41,44}
Returns: 10

5)

    
{13,9,6,1,9,8,6,2,8,20}
{20,10,11,10,1,5,16,2,9,17}
{12,14,64,78,100,121,151,155,162,164}
{19,26,159,96,155,134,169,199,169,174}
Returns: 17

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


class RestaurantManager {
public:
  int allocateTables(vector <int> tables, vector <int> groupSizes, vector <int> arrivals, vector <int> departures) {
		
		int ans=0, ai=0;
		vector <int> tablesTaken;
		vector <int> timeToLeave;
		
		for(int t=arrivals[0]; t<departures[departures.size()-1]; ++t){
			
			for(int i=0; i<tablesTaken.size(); ++i){
				if(timeToLeave[i]==t){
					tables.push_back(tablesTaken[i]);
					cout<<t<<": release a table of size "<<tablesTaken[i]<<endl;
				}
			}
			
			if(t==arrivals[ai]){
				sort(tables.begin(), tables.end());
				int table_idx = -1;
				for(int i=0; i<tables.size(); ++i){
					if(tables[i]>=groupSizes[ai]){
						table_idx = i;
						break;
					}
				}
				if(table_idx==-1){
					ans += groupSizes[ai];
					cout<<t<<": turn away of ppl "<<groupSizes[ai]<<endl;
				}
				else{
					tablesTaken.push_back(tables[table_idx]);
					timeToLeave.push_back(departures[ai]);
					tables.erase(tables.begin()+table_idx);
					cout<<t<<": take a table of size "<<groupSizes[ai]<<endl;
				}
				++ai;
			}
		}
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
