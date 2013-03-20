/*

Problem Statement
    
A palindrome is a string that reads the same from left to right as it does from right to left.

You are given a String s. The length of s is even. Each character of s is either 'o', 'x', or '?' Your task in this problem is to replace each occurrence of '?' in s with either 'o' or 'x' so that s becomes a palindrome. You are also given ints oCost and xCost. Replacing '?' with 'o' costs oCost, and replacing '?' with 'x' costs xCost.

Return the minimum cost of replacing '?'s by 'x's and 'o's that turns s into a palindrome. If it is impossible to obtain a palindrome, return -1 instead.
Definition
    
Class:
MinCostPalindrome
Method:
getMinimum
Parameters:
String, int, int
Returns:
int
Method signature:
int getMinimum(String s, int oCost, int xCost)
(be sure your method is public)
    

Notes
-
You are not allowed to change an 'x' into an 'o' or vice versa.
Constraints
-
s will contain between 2 and 20 characters, inclusive.
-
The length of s will be even.
-
Each character of s will be either 'o' or 'x' or '?'.
-
oCost will be between 1 and 50, inclusive.
-
xCost will be between 1 and 50, inclusive.
Examples
0)

    
"oxo?xox?"
3
5
Returns: 8
The only way to produce a palindrome is to replace s[3] with 'x' and s[7] with 'o'. The first replacement costs 5, the second costs 3, so the total cost is 3+5=8.
1)

    
"x??x"
9
4
Returns: 8
There are two ways to produce a palindrome here. The cheaper one is to change both '?'s to 'x's. This costs 4+4=8. Note that you are required to replace all '?'s.
2)

    
"ooooxxxx"
12
34
Returns: -1
There is no '?' character, and s is not a palindrome. We have no way to change it into a palindrome.
3)

    
"oxoxooxxxxooxoxo"
7
4
Returns: 0
There is no '?' character, and s is already a palindrome. Making no replacements does not cost anything.
4)

    
"?o"
6
2
Returns: 6

5)

    
"????????????????????"
50
49
Returns: 980

6)

    
"o??oxxo?xoox?ox??x??" 
3
10
Returns: 38

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class MinCostPalindrome
{
  public int getMinimum(String s, int oCost, int xCost)
	{
		int qmCount = s.length() - s.replaceAll("\\?", "").length();
		int ans = Integer.MAX_VALUE;
		for(int i=0; i<(1<<qmCount); ++i){
			int qmidx=0;
			char[] array = s.toCharArray();
			int cost = 0;
			for(int j=0; j<s.length(); ++j){
				if(array[j]=='?'){
					if( ((i>>qmidx)&1) == 1 ){
						array[j] = 'o';
						cost += oCost;
					}
					else{
						array[j] = 'x';
						cost += xCost;
					}
					++qmidx;
				}
			}
			
			boolean flag = true;
			for(int j=0; j<s.length()/2 ; ++j){
				if(array[j]!=array[s.length()-1-j])
					flag = false;
			}
						
			if(flag)
				ans = Math.min(ans,cost);
		}
		return (ans==Integer.MAX_VALUE)?-1:ans;
	}
	
<%:testing-code%>
}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
