/*

Problem Statement
    
Some people like to have a particular custom signature following their emails or posts on online message boards. These signatures usually contain the handle by which they are known, but then are decorated by various punctuation marks to make them look more interesting. You, as administrator of a popular message board, would like to allow such decorations in people's signatures while enforcing a rule that the signature they use contains their name. In order to do this, you allow people to set up a series of rules to apply to their handles to automatically generate their signatures.
You will be given a user's handle as a string, which will be made up of upper- and lower-case letters, numbers or underscores ('_'). You will also be given two vector <string>s representing a series of formatting commands. Each element in commands is "prepend", "append" or "surround". Each element of decorations is a series of punctuation characters (out of ,./;'<>?:"\|[]{}-=_+!@#$%^&*()~` ) to use. The ith element of commands corresponds to the ith element of decorations.
Each instruction should be executed as follows:
For a "prepend" command, put the decoration at the beginning of the name.
For an "append" command, put the decoration at the end of the name.
For a "surround" command, put the decoration at the beginning of the name and backwards at the end of the name.
The instructions should be executed in the order in which they appear, so if name is "Bob", commands is {"surround", "append", "prepend"}, and decorations is {"-=", "(", ")"} name would progressively go from "Bob" to "-=Bob=-" to "-=Bob=-(" to ")-=Bob=-(".
Definition
    
Class:
SignatureDecorator
Method:
applyDecoration
Parameters:
string, vector <string>, vector <string>
Returns:
string
Method signature:
string applyDecoration(string name, vector <string> commands, vector <string> decorations)
(be sure your method is public)
    

Constraints
-
name will be between 1 and 50 characters long, inclusive.
-
commands and decorations and will have between 0 and 50 elements, inclusive.
-
commands and decorations will have the same number of elements.
-
Each element of decorations will have between 1 and 50 characters, inclusive.
-
Each element of decorations will contain only the following characters: ,./;'<>?:"\|[]{}-=_+!@#$%^&*()~`
-
Each element of commands will be either "prepend", "append", or "surround".
-
name will be made up of only upper- or lower-case letters, numbers, and underscores ('_').
Examples
0)

    
"Bob"
{"surround", "append", "prepend"}
{"-=", "(", ")"}
Returns: ")-=Bob=-("
The example from the problem statement.
1)

    
"Super_Man_01"
{}
{}
Returns: "Super_Man_01"

2)

    
"4BcD3FgHIjklMN0pqrS7uVWxYZ_"
{"append", "prepend", "surround"}
{"`{[(", ")]}'", ",.;<>?:|-=_+!@#$%^&*~"}
Returns: ",.;<>?:|-=_+!@#$%^&*~)]}'4BcD3FgHIjklMN0pqrS7uVWxYZ_`{[(~*&^%$#@!+_=-|:?><;.,"

3)

    
"RacEcaR"
{"surround"}
{"([{/"}
Returns: "([{/RacEcaR/{[("
Turning the punctuation around backwards doesn't mean flipping individual characters.
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


class SignatureDecorator {
public:
  string applyDecoration(string name, vector <string> commands, vector <string> decorations) {
		
		string ans = name;
		for(int i=0; i<commands.size(); ++i){
			if(commands[i]=="surround"){
				ans = decorations[i] + ans;
				reverse(decorations[i].begin(), decorations[i].end());
				ans = ans + decorations[i];
			}
			else if(commands[i]=="append")
				ans = ans + decorations[i];
			else if(commands[i]=="prepend")
				ans = decorations[i] + ans;
		}
		return ans;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
