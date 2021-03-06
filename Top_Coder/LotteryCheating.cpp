/*

Problem Statement
    
Bob likes to play the lottery, but it's so hard to win without cheating. Each lottery ticket has an identifier which contains exactly n decimal digits. If an identifier contains only '0's, it is considered a winning ticket. Otherwise, the identifier is interpreted as a positive integer X written in decimal notation (possibly with leading zeros). If X has an odd number of positive integer divisors, it is a winning ticket, otherwise, it is not. A positive integer is a divisor of X if it divides X evenly.  Unfortunately, Bob only has enough money to buy one ticket, and he cannot see the identifier before buying a ticket. Therefore, he decides to cheat by buying a ticket and modifying its identifier to make it a winning ticket. In a single change operation, he can choose one digit, erase it, and print some other digit in the same position. No other types of modifications are allowed. He can perform any number of these change operations, but he wants to perform as few as possible to minimize the risk of getting caught.  You are given a string ID, the initial identifier on Bob's ticket. Return the minimal number of change operations necessary to transform the identifier into a winning one. If the initial identifier is already a winner, return 0.
Definition
    
Class:
LotteryCheating
Method:
minimalChange
Parameters:
string
Returns:
int
Method signature:
int minimalChange(string ID)
(be sure your method is public)
    

Constraints
-
ID will contain between 1 and 10 characters, inclusive.
-
Each character in ID will be between '0' and '9', inclusive.
Examples
0)

    
"1"
Returns: 0
1 is the only divisor of this identifier. Since there are an odd number of divisors, it is already a winning ticket, and no changes are necessary.
1)

    
"1234"
Returns: 2
One possible solution is to transform "1234" into "1024". As 1024 is 2^10, it has 11 divisors: 2^0, 2^1, ..., 2^10.
2)

    
"9000000000"
Returns: 1
Bob can change the '9' into a '0'. The resulting identifier "0000000000" contains only '0's, so it is a winning ticket.
3)

    
"4294967296"
Returns: 0
The initial identifier represents the integer 2^32, so it has 33 divisors.
4)

    
"7654321"
Returns: 3

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
#include <sstream>


using namespace std;


class LotteryCheating {
public:
  //A square number has an odd number of divisors, while other numbers have an even number of divisors. An integer root is the only divisor that pairs up with itself to yield the square number, while other divisors come in pairs.
	int minimalChange(string ID) {
	
		long long iID = 0;
		for(int i=0; i<ID.size(); ++i)
			iID = iID*10 + (ID[i]-'0');
		
		//distance to "00...0"
		int cnt1=0;
		for(int i=0; i<ID.size(); ++i){
			if(ID[i]!='0')
				++cnt1;
		}
		
		//distance to a perfect square
		int cnt2=0;
		if (sqrt(iID)*sqrt(iID) != iID){
			long long t = 2;
			cnt2 = 1<<16;
			while(t*t<iID){
				//diff = dist(t^2, iID)
				std::stringstream out;
				out << t*t;
				string s = out.str();
				int diff = 0;
				for(int i=0; i<ID.size(); ++i){
					if(ID[i]!=s[i])
						++diff;
				}
				cnt2 = min(cnt2, diff);
				++t;
			}
		}

		return min(cnt1, cnt2);
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
