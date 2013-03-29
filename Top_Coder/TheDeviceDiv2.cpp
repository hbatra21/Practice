/*

Problem Statement
    
Manao works at a laboratory on a highly classified project. From time to time, he is given a special device and has to determine its exact structure. Every such device operates on special plates. There are M bits written on each of the plates from left to right. The device has two inputs and a screen. Each input requires a plate. When two plates are connected to the device, M bits of output appear on the screen. Each bit of output is either a binary OR, AND or XOR of the corresponding bits of the input plates. Manao's task is to determine what operation is carried out for each of the bits.  Manao has N plates. He is going to test the device on each possible pair of these plates and determine its structure by the outputs on the screen. It might be that the plates Manao has are not enough to uniquely identify every possible device. You are given vector <string> plates, where each element describes a plate Manao has. If these plates are certainly sufficient to determine the structure of the device completely, return "YES". Otherwise, return "NO".
Definition
    
Class:
TheDeviceDiv2
Method:
identify
Parameters:
vector <string>
Returns:
string
Method signature:
string identify(vector <string> plates)
(be sure your method is public)
    

Constraints
-
plates will contain between 1 and 50 elements, inclusive.
-
Each element of plates will be between 1 and 50 characters long, inclusive.
-
All elements of plates will be of equal length.
-
Each element of plates will contain characters from the set {'0', '1'} only.
Examples
0)

    
{"010",
 "011",
 "000"}
Returns: "NO"
With these plates we cannot determine anything about the operation done on the first bit, because all of them give the same result. Also, we cannot be sure that we can determine the operation done on the third bit: if it is the AND operation, we can find this out (for example by using the first two plates), but we cannot distinguish between OR and XOR using the given plates.
1)

    
{"1",
 "0",
 "1",
 "0"}
Returns: "YES"
Manao will see the result for every possible combination of bits, which is enough to distinguish between AND, OR and XOR.
2)

    
{"11111"}
Returns: "NO"
A single plate is not enough for even one test.
3)

    
{"0110011",
 "0101001",
 "1111010",
 "1010010"}
Returns: "NO"
The operation done on the fifth bit from the left (1-based index) cannot be determined.
4)

    
{"101001011",
 "011011010",
 "010110010",
 "111010100",
 "111111111"}
Returns: "YES"

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


class TheDeviceDiv2 {
public:
  string identify(vector <string> plates) {
		if(plates.size()==1)
			return "NO";
		for(int i=0; i<plates[0].size(); ++i){
			int numO=0, numZ=0;
			for(int j=0; j<plates.size(); ++j){
				if(plates[j][i]=='0')
					++numZ;
				if(plates[j][i]=='1')
					++numO;
			}
			if(numO>=2 && numZ>=1){
				//pass
			}
			else
				return "NO";
		}
		return "YES";
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
