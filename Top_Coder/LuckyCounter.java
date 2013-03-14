/*

Problem Statement
    
Suppose that we're given a moment of time written as HH:MM, where HH is the hour and MM is the minutes. Let's say that this moment is lucky if it is formatted AB:AB, AA:BB or AB:BA, where both occurrences of A stand for the same digit and both occurrences of B also stand for the same digit. It is allowed for the digits represented by A and B to be the same as well.  You are given a String[] moments, where each element represents a single moment of time. Return how many of these time moments are lucky.
Definition
    
Class:
LuckyCounter
Method:
countLuckyMoments
Parameters:
String[]
Returns:
int
Method signature:
int countLuckyMoments(String[] moments)
(be sure your method is public)
    

Constraints
-
moments will contain between 1 and 50 elements, inclusive.
-
Each element of moments will be formatted "HH:MM" (quotes for clarity), where HH is between 00 and 23, inclusive, and MM is between 00 and 59, inclusive.
Examples
0)

    
{"12:21", "11:10"}
Returns: 1
12:21 is lucky, while 11:10 is not.
1)

    
{"00:00", "00:59", "23:00"}
Returns: 1
Only 00:00 is lucky here (note that it is formatted AB:AB, AA:BB and AB:BA at the same time).
2)

    
{"12:34"}
Returns: 0

3)

    
{"12:11", "22:22", "00:01", "03:30", "15:15", "16:00"}
Returns: 3

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class LuckyCounter
{
  public int countLuckyMoments(String[] moments)
	{
		int ans = 0;
		for(String s : moments){
			char[] chars = s.toCharArray();
			if(chars[0]==chars[1] && chars[3]==chars[4])//AABB
				++ans;
			else if(chars[0]==chars[3] && chars[1]==chars[4])//ABAB
				++ans;
			else if(chars[0]==chars[4] && chars[1]==chars[3])//ABBA
				++ans;
			else if(chars[0]==chars[1] && chars[1]==chars[3] && chars[3]==chars[4] )//AAAA
				++ans;
		}
		return ans;
	}
	
<%:testing-code%>
}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
