/*

Problem Statement
    
NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.

Fox Ciel has a cube and some colored stickers. You are given a String[] sticker, where the i-th element is the color of the i-th sticker. Ciel wants to choose six of these stickers and apply one on each of the cube's faces. Each pair of adjacent faces must have different colors. Two faces are considered adjacent if they share an edge.

If this is possible, return "YES", otherwise, return "NO" (all quotes for clarity).
Definition
    
Class:
CubeStickers
Method:
isPossible
Parameters:
String[]
Returns:
String
Method signature:
String isPossible(String[] sticker)
(be sure your method is public)
    

Constraints
-
sticker will contain between 6 and 50 elements, inclusive.
-
Each element of sticker will contain between 1 and 10 lowercase letters ('a'-'z'), inclusive.
Examples
0)

    
{"cyan","magenta","yellow","purple","black","white","purple"}
Returns: "YES"
One of the possible ways is shown in the following picture:
 
1)

    
{"blue","blue","blue","blue","blue","blue","blue","blue","blue","blue"}
Returns: "NO"

2)

    
{"red","yellow","blue","red","yellow","blue","red","yellow","blue"}
Returns: "YES"

3)

    
{"purple","orange","orange","purple","black","orange","purple"}
Returns: "NO"

4)

    
{"white","gray","green","blue","yellow","red","target","admin"}
Returns: "YES"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class CubeStickers
{
  public String isPossible(String[] sticker)
	{
		if(sticker.length<6)
			return "NO";
		
		Map<String, Integer> map = new HashMap<String, Integer>();
		for (String color : sticker){
			if(map.containsKey(color))
				map.put(color, map.get(color)+1);
			else
				map.put(color, 1);
		}
		System.out.println(map.toString());
		
		if(map.size()==3 && Collections.min(map.values())>1)
			return "YES";
		
		if(map.size()==4){
			//at least 3 colors that have number >= 3
			//or 2 colors that have number >=2 and 2 colors that has number >=1
			int two = 0; int one = 0;
			int mymin = Collections.min(map.values());
			Iterator it = map.entrySet().iterator();
		    while (it.hasNext()) {
		        Map.Entry pairs = (Map.Entry)it.next();
		        if(((Integer) pairs.getValue()).intValue() > 1)
		        	++two;
		        if(((Integer) pairs.getValue()).intValue() == 1)
		        	++one;
		    }
		    if( two>=3 || (two>=2 && one>=2) )
		    	return "YES";
		    else
		    	return "NO";
		}
		
		if(map.size()>4)
			return "YES";
		else
			return "NO";
	}
	
<%:testing-code%>
}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
