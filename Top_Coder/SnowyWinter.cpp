/*

Problem Statement
    
Southern China is suffering from a heavily snowy winter. The heavy snow even causes the closure of an important highway connecting southern and northern China. You've got several reports containing the start and end points of highway segments covered by heavy snow. Given those reports as two vector <int>s startPoints and endPoints, you are to return the total length of highway segments covered by snow. Note that the reported segments may overlap.
Definition
    
Class:
SnowyWinter
Method:
snowyHighwayLength
Parameters:
vector <int>, vector <int>
Returns:
int
Method signature:
int snowyHighwayLength(vector <int> startPoints, vector <int> endPoints)
(be sure your method is public)
    

Constraints
-
startPoints will contain between 1 and 50 elements, inclusive.
-
endPoints will contain the same number of elements as startPoints.
-
Each element of startPoints and endPoints will be between 0 and 10000, inclusive.
-
The i-th element of startPoints will be smaller than the corresponding element in endPoints.
Examples
0)

    
{17,85,57}
{33,86,84}
Returns: 44
These segments don't overlap.
1)

    
{45,100,125,10,15,35,30,9}
{46,200,175,20,25,45,40,10}
Returns: 132
There are 3 segments covered by snow: 9-25, 30-46 and 100-200.
2)

    
{4387,711,2510,1001,4687,3400,5254,584,284,1423,3755,929,2154,5719,1326,2368,554}
{7890,5075,2600,6867,7860,9789,6422,5002,4180,7086,8615,9832,4169,7188,9975,8690,1423}
Returns: 9691
The snow covered segment is 284-9975.
3)

    
{4906,5601,5087,1020,4362,2657,6257,5509,5107,5315,277,6801,2136,2921,5233,5082,497,8250,3956,5720}
{4930,9130,9366,2322,4687,4848,8856,6302,5496,5438,829,9053,4233,4119,9781,8034,3956,9939,4908,5928}
Returns: 9510
There are 2 segments covered by snow: 277-4930 and 5082-9939.
4)

    
{51,807,943,4313,8319,3644,481,220,2161,448,465,1657,6290,22,6152,647,3185,4474,2168}
{1182,912,1832,7754,9557,7980,4144,3194,7129,5535,1172,2043,6437,7252,9508,4745,8313,8020,4017}
Returns: 9535

5)

    
{8786,7391,201,4414,5822,5872,157,1832,7487,7518,2267,1763,3984,3102,7627,4099,524,1543,1022,3060}
{9905,7957,3625,6475,9314,9332,4370,8068,8295,8177,7772,2668,7191,8480,9211,4802,2625,1924,9970,4180}
Returns: 9813

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


class SnowyWinter {
public:
  int snowyHighwayLength(vector <int> startPoints, vector <int> endPoints) {
		
		int mymin = *min_element(startPoints.begin(), startPoints.end());
		int mymax = *max_element(endPoints.begin(), endPoints.end());
			
		vector <int> road(mymax-mymin, 0);
		for(int i=0; i<startPoints.size(); ++i){
			for(int j=startPoints[i]; j<endPoints[i]; ++j)
				road[j-mymin] = 1;
		}
		
		int ans = 0;
		for(int i=0; i<road.size(); ++i)
			ans += road[i];
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
