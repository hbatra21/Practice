/*

Problem Statement
    
Elly's memories of last night's sleepover with her friends are rather blurry. She recalls that they played a game involving drinking orange and apple juice. In the beginning there were two identical bottles. One contained a gallon of orange juice, the other a gallon of apple juice. The game was played in turns, starting with turn zero. In even-numbered turns (turn 0, 2, 4, ...) the current player drank half of the remaining orange juice. In odd-numbered turns (turn 1, 3, 5, ...) the current player drank half of the remaining apple juice. The winner of the game is the player who drank the greatest total amount of liquid during the game. If multiple players are tied for the greatest amount, there is no winner.

For example, consider a game consisting of five turns. Suppose that the players to drink were, in order, Elly, Kriss, Stancho, Elly, and Stancho. (That is, Elly and Stancho both drank twice: Elly in turns 0 and 3, Stancho in turns 2 and 4.) In this game, Elly drank 0.75 gallons of liquid (0.5 gallons of orange juice and 0.25 of apple juice), Kriss drank 0.5 gallons of apple juice, and Stancho drank 0.375 gallons of orange juice (0.25 gallons in turn 2 and another 0.125 gallons in turn 4). In this game Elly would be the winner.

Elly knows all the people who played the game yesterday, and for each of them the number of times they drank. However, she remembers nothing about the order in which the players drank.

You are given a vector <string> players, containing the names of all players. If a player's name is contained X times in players that means that he or she drank exactly X times during the game. Determine all people who could have possibly won the game (for some particular order of turns). Return their names as a lexicographically sorted vector <string>. The return value should only contain each of the names once.
Definition
    
Class:
EllysJuice
Method:
getWinners
Parameters:
vector <string>
Returns:
vector <string>
Method signature:
vector <string> getWinners(vector <string> players)
(be sure your method is public)
    

Notes
-
A sequence of distinct strings is sorted if each element is lexicographically smaller than all the ones following it.
-
string A is lexicographically smaller than string B if A contains smaller character at the first index where they differ. If there is no index where they differ, the shorter one is lexicographically smaller. For example "ariadne" is smaller than "elly", "abc" is smaller than "abd", "aaa" is smaller than "aaaaa", and "czzzzzzz" is smaller than "kaaaaaaa".
Constraints
-
players will contain between 1 and 8 elements, inclusive.
-
Each element of players will contain between 1 and 20 characters, inclusive.
-
Each element of players will consist only of lowercase English letters ('a'-'z').
Examples
0)

    
{ "elly", "kriss", "stancho", "elly", "stancho" }
Returns: {"elly", "stancho" }
Elly would win for the order given in the problem statement. If Stancho and Elly swapped all their turns, Stancho would win the game. Kriss cannot win.
1)

    
{"torb", "elly", "stancho", "kriss"}
Returns: { }
In any valid game two of the four players would be tied for the lead (with half a gallon each).
2)

    
{"elly", "elly", "elly", "elly", "elly"}
Returns: {"elly" }
Since she was the only player, apparently she won.
3)

    
{ "ariadne", "elly", "ariadne", "stancho", "stancho", "kriss", "stancho", "elly" }
Returns: {"ariadne", "elly", "stancho" }
Although Stancho has drunk three times, there are orderings in which someone else wins.
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

class EllysJuice {
public:
  vector <string> getWinners(vector <string> players) {
		vector<string> ans;
		int N = players.size();
		do {
			map<string,float> mymap;
			for(int i=0; i<N; ++i)
				mymap[players[i]]+= 1.0/float(1<<((i/2)+1));
			
			float mymax = -1.0;
			string roundwinner = "";
			bool draw = false;
			for (map<string,float>::iterator it=mymap.begin(); it!=mymap.end(); ++it){
				 if(it->second==mymax)
				 	draw = true;
				 if(it->second>mymax){
				 	mymax = it->second;
				 	roundwinner = it->first;
				 	draw = false;
				 }
			}
			
			if( draw==false && find(ans.begin(), ans.end(), roundwinner) == ans.end() )
				ans.push_back(roundwinner);
		} while ( next_permutation(players.begin(),players.end()) );
		
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
