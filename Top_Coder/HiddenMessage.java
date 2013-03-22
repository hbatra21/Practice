/*

Problem Statement
    
Some texts contain hidden messages. In the context of this problem, the hidden message of a text is composed of the first letter from each word in the text, in the order they appear.
Given a String text, consisting of only lowercase letters and spaces, return the hidden message. A word is a maximal sequence of consecutive letters. There may be multiple spaces between words. Also, text may contain only spaces.
Definition
    
Class:
HiddenMessage
Method:
getMessage
Parameters:
String
Returns:
String
Method signature:
String getMessage(String text)
(be sure your method is public)
    

Constraints
-
text will contain between 1 and 50 characters, inclusive.
-
Each character of text will be either a lowercase letter ('a'-'z'), or a space (' ').
Examples
0)

    
"compete online design event rating"
Returns: "coder"
Taking the first letter from each word yields the return "coder".
1)

    
"  c    o d     e      r    "
Returns: "coder"
Watch out for the leading spaces.
2)

    
"round  elimination during  onsite  contest"
Returns: "redoc"
"coder" written backwards.
3)

    
" "
Returns: ""
Since there are no words here, the empty string must be returned.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class HiddenMessage
{
  public String getMessage(String text)
	{
		StringBuilder sb = new StringBuilder();
		String[] words = text.split("\\s+");
		
		System.out.println(words.length);
		for(String w : words){
			char[] chars = w.toCharArray();
			if(chars.length>0)
				sb.append(chars[0]);
		}
		return sb.toString();
	}
	
<%:testing-code%>
}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
