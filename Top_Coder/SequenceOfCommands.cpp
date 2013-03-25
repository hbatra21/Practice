/*

Problem Statement
    
You are standing on some arbitrary point in the infinite plane.
You are given a vector <string> commands that contains the commands you have to execute. Each character of each element of commands is one command. The commands must be executed in the given order: first you execute all commands in the first element of commands one by one, then those in the second element, etc.
There are only three types of commands: 'S' means "step forward", 'L' means "turn 90 degrees to the left", and 'R' means "turn 90 degrees to the right". All your steps have the same length.
You will be executing the commands forever: after you execute the last character of the last element of commands, you will always start from the beginning again.
We say that your path is bounded if there is some positive real number R such that while executing the infinite sequence of steps you will never leave the circle with radius R steps and center at your starting location.
Given the vector <string> commands, your method should determine whether your path will be bounded or not. Return the string "bounded" (quotes for clarity) if the path is bounded and "unbounded" if it is not.
Definition
    
Class:
SequenceOfCommands
Method:
whatHappens
Parameters:
vector <string>
Returns:
string
Method signature:
string whatHappens(vector <string> commands)
(be sure your method is public)
    

Constraints
-
commands will contain between 1 and 50 elements, inclusive.
-
Each element in commands will contain between 1 and 50 characters, inclusive.
-
Each character in each element of commands will be one of 'S', 'L', and 'R'.
Examples
0)

    
{"L"}
Returns: "bounded"
You are standing on the same spot forever, and in each step you take a turn 90 degrees to the left. This path is clearly bounded.
1)

    
{"SRSL"}
Returns: "unbounded"
Imagine that you start executing the commands facing to the north. While following this sequence you will repeatedly execute the following steps: make a step to the north, rotate right, make a step to the east, and rotate left (to face north again).
Given enough time, this path will take you arbitrarily far away from the spot where you started, hence it is unbounded.
2)

    
{"SSSS","R"}
Returns: "bounded"
While executing this sequence of commands, you will be walking along the boundary of a small square.
3)

    
{"SRSL","LLSSSSSSL","SSSSSS","L"}
Returns: "unbounded"

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


class SequenceOfCommands {
public:
  string whatHappens(vector <string> commands) {
		int x=0, y=0,rot=0;
		for(int i=0; i<commands.size(); ++i){
			for(int j=0; j<commands[i].size(); ++j){
				if (commands[i][j] == 'L')
					rot = (rot-90)%360;
				else if (commands[i][j] == 'R')
					rot = (rot+90)%360;
				else if (commands[i][j] == 'S'){
					if(rot==0)
						++x;
					else if(rot==90)
						--y;
					else if(rot==180)
						--x;
					else if(rot==270)
						++y;
				}
			}
		}
		
		if(rot==0){
			if(x==0 && y==0)
				return "bounded";
			else
				return "unbounded";
		}
		else
			return "bounded";
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
