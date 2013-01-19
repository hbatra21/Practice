/*

Problem Statement
    
Fox Ciel has a new favorite string operation that works as follows: She takes two copies of some string X, and inserts one copy somewhere into the other copy of the same string. (She can also insert it at the beginning or, equivalently, at the end.) This operation is called expansion of the string X. For example, if X = "Ciel", she can expand it to "CielCiel", "CCieliel", "CiCielel", or "CieCiell".   You are given two strings: S and T. Return "Yes" (quotes for clarity) if T can be obtained by expanding S exactly once. Otherwise, return "No".
Definition
    
Class:
FoxAndHandleEasy
Method:
isPossible
Parameters:
string, string
Returns:
string
Method signature:
string isPossible(string S, string T)
(be sure your method is public)
    

Constraints
-
S will contain between 1 and 50 characters, inclusive.
-
T will contain between 1 and 50 characters, inclusive.
-
Both S and T will contain uppercase and lowercase letters only ('A'-'Z' and 'a'-'z').
Examples
0)

    
"Ciel"
"CieCiell"
Returns: "Yes"
She can insert "Ciel" between "Cie" and "l".
1)

    
"Ciel"
"FoxCiel"
Returns: "No"
Each string obtained by expanding S="Ciel" has exactly 8 letters.
2)

    
"FoxCiel"
"FoxFoxCielCiel"
Returns: "Yes"

3)

    
"FoxCiel"
"FoxCielCielFox"
Returns: "No"

4)

    
"Ha"
"HaHaHaHa"
Returns: "No"

5)

    
"TheHandleCanBeVeryLong"
"TheHandleCanBeVeryLong"
Returns: "No"

6)

    
"Long"
"LongLong"
Returns: "Yes"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/


#include <string>
#include <algorithm>
using namespace std;

class FoxAndHandleEasy{
  public:
	string isPossible(string S, string T){
		
		if (T.size() != 2*S.size())
			return "No";

		for (int i=0; i<S.size(); ++i){
			string sztmp = S.substr(0,i) + S + S.substr(i,S.size()-i);
			if (sztmp == T)
				return "Yes";
		}
		return "No";
	}
};
