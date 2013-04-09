import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class RandomColoringDiv2
{
  public int getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2)
	{
		int cnt = 0;
		for(int r=0; r<maxR; ++r){
			for(int g=0; g<maxG; ++g){
				for(int b=0; b<maxB; ++b){
					if( Math.abs(r-startR)<=d2 && Math.abs(g-startG)<=d2 && Math.abs(b-startB)<=d2){
						if(Math.abs(r-startR)>=d1 || Math.abs(g-startG)>=d1 || Math.abs(b-startB)>=d1)
							++cnt;
					}
				}
			}
		}
		return cnt;
	}
	
	
<%:testing-code%>
}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
