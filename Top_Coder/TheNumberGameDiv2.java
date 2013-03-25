/*

Problem Statement
    
Manao has recently invented a brand new single-player game called The Number Game.  The player starts with a number A. Also, another number B is chosen. Note that neither A nor B contain a zero digit in their base 10 representation.  The player's goal is to obtain B from A. In each move, the player can either reverse his current number, or he can divide it by 10 (using integer division). For example, if the current number is 12849, the player can either reverse it to obtain 94821, or he can divide it by 10 to obtain 1284. (Note that we always round down when using integer division.)  You are given two ints A and B. If it is possible to obtain B from A, return the minimum number of moves necessary to reach this goal. Otherwise, return -1.
Definition
    
Class:
TheNumberGameDiv2
Method:
minimumMoves
Parameters:
int, int
Returns:
int
Method signature:
int minimumMoves(int A, int B)
(be sure your method is public)
    

Constraints
-
A will be between 1 and 999,999,999, inclusive.
-
B will be between 1 and 999,999,999, inclusive.
-
A and B will not contain a zero digit in base 10 representation.
-
A and B will be distinct.
Examples
0)

    
25
5
Returns: 2
Initially, the player has number 25 and needs to obtain 5. He can reverse the number and obtain 52, then divide it by 10 and obtain 5.
1)

    
5162
16
Returns: 4
To obtain 16 from 5162 in four moves, the player can perform the following sequence of moves: 
Reverse the number and obtain 2615.
Divide 2615 by 10 and obtain 261.
Reverse 261 and obtain 162.
Divide 162 by 10 and obtain 16.
Note that this is not the only possible sequence of four moves which leads to the goal.
2)

    
334
12
Returns: -1
There is no way to obtain 12 from 334.
3)

    
218181918
9181
Returns: 6

4)

    
9798147
79817
Returns: -1

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class TheNumberGameDiv2
{
  public String reverse(String str) {
		StringBuilder sb = new StringBuilder();
	 	for(int i=str.length()-1;i>=0;i--)
  			sb.append(str.charAt(i));
  		return sb.toString();
	}

  public int minimumMoves(int A, int B)
	{
		String sA = Integer.toString(A);
		String sB = Integer.toString(B);
		if( sA.contains(sB) ){
			int start = sA.indexOf(sB);
			//trim lower part
			int cnt = sA.length()-start-sB.length();	//divide
			sA = sA.substring(0,start+sB.length());
			//tri higher part
			cnt += 1;		//reverse
			sA = reverse(sA);
			cnt += start;	//divide
			sA = sA.substring(0,start+1);
			if(reverse(sA).equals(sB))
				cnt += 1;		//reverse
			return cnt;
		}
		else if ( sA.contains(reverse(sB)) ){
			int start = sA.indexOf(reverse(sB));
			//trim lower part
			int cnt = sA.length()-start-sB.length();	//divide
			sA = sA.substring(0,start+sB.length());
			//tri higher part
			cnt += 1;		//reverse
			sA = reverse(sA);
			cnt += start;	//divide
			sA = sA.substring(0,start+1);
			if(reverse(sA).equals(sB))
				cnt += 1;		//reverse
			return cnt;
		}
		else
			return -1;
	}
	

}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
