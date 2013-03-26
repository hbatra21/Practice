/*

Problem Statement
    
Rabbits often feel lonely, so one group of rabbits decided to get together and hold a beauty contest to determine who among them has the most beautiful ears. The rules are as follows. Each rabbit submits one vote. If a rabbit votes for himself/herself, that vote is considered invalid and thrown away. In the end, the rabbit who receives the most valid votes is the winner.  You are given a String[] names and a String[] votes. The i-th rabbit is named names[i], and he/she voted for the rabbit named votes[i]. All rabbits have distinct names. Return the name of the rabbit who received the most valid votes. If there is a tie for most votes, return an empty String instead.
Definition
    
Class:
RabbitVoting
Method:
getWinner
Parameters:
String[], String[]
Returns:
String
Method signature:
String getWinner(String[] names, String[] votes)
(be sure your method is public)
    

Notes
-
Rabbit names are case-sensitive. See example 4 for clarification.
Constraints
-
names will contain between 2 and 50 elements, inclusive.
-
Each element of names will contain between 1 and 50 characters, inclusive.
-
Each character in names will be a letter ('A'-'Z', 'a'-'z').
-
All elements of names will be distinct.
-
votes will contain the same number of elements as names.
-
Each element of votes will be the same as one of the elements of names.
Examples
0)

    
{ "Alice", "Bill", "Carol", "Dick" }
{ "Bill", "Dick", "Alice", "Alice" }
Returns: "Alice"
2 votes for Alice, 1 for Bill, 0 for Carol, and 1 for Dick. Alice got the most.
1)

    
{ "Alice", "Bill", "Carol", "Dick" }
{ "Carol", "Carol", "Bill", "Bill" }
Returns: ""
Bill and Carol are tied with 2 votes each.
2)

    
{ "Alice", "Bill", "Carol", "Dick" }
{ "Alice", "Alice", "Bill", "Bill" }
Returns: "Bill"
Alice's vote for herself is invalid. 1 valid vote for Alice, 2 for Bill.
3)

    
{ "Alice", "Bill" }
{ "Alice", "Bill" }
Returns: ""
All votes are invalid.
4)

    
{ "WhiteRabbit", "whiterabbit", "whiteRabbit", "Whiterabbit" }
{ "whiteRabbit", "whiteRabbit", "whiteRabbit", "WhiteRabbit" }
Returns: "whiteRabbit"
These four are different names.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class RabbitVoting
{
  public String getWinner(String[] names, String[] votes)
	{
		Map<String, Integer> map = new HashMap<String, Integer>();
		for(int i=0; i<votes.length; ++i){
			if(!votes[i].equals(names[i])){
				if(map.containsKey(votes[i]))
					map.put(votes[i], map.get(votes[i])+1);
				else
					map.put(votes[i], 1);
			}
		}
		int imax = -1;
		String ans = "";
		for (String key : map.keySet()) {
			if(map.get(key)>imax){
    			imax = map.get(key);
    			ans = key;
    		}
    		else if (map.get(key)==imax)
    			ans = "";
		}
		
		return ans;
	}
	

}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
