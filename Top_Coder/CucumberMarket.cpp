/*

Problem Statement
    
Cucumber Boy is young and loves cucumbers. Therefore, Cucumber Boy will go to the cucumber market to buy some cucumbers.

Different cucumbers may have different costs. For each i, buying the i-th cucumber (0-based index) costs price[i] yen.

Cucumber Boy's mother gave him budget yen. However, he does not understand money well.
He just chooses some k unique cucumbers he likes. If the total price of the chosen cucumbers is not greater than budget yen, he can buy them, otherwise he cannot.

You are given the vector <int> price, the int budget and the int k. Your method must return "YES" (quotes for clarity) if Cucumber Boy can buy any set of k unique cucumbers, and "NO" if there is some set of k cucumbers that is too expensive for him.
Definition
    
Class:
CucumberMarket
Method:
check
Parameters:
vector <int>, int, int
Returns:
string
Method signature:
string check(vector <int> price, int budget, int k)
(be sure your method is public)
    

Constraints
-
price will contain between 1 and 9 elements, inclusive.
-
Each element of price will be between 1 and 1000, inclusive.
-
budget will be between 1 and 10000, inclusive.
-
k will be between 1 and the number of elements in price, inclusive.
Examples
0)

    
{1000,1,10,100}
1110
3
Returns: "YES"
There are 4 choices.
If he chooses cucumbers 0, 1, and 2, the total price will be 1000+1+10 = 1011 yen.
If he chooses cucumbers 0, 1, and 3, the total price will be 1000+1+100 = 1101 yen.
If he chooses cucumbers 0, 2, and 3, the total price will be 1000+10+100 = 1110 yen.
If he chooses cucumbers 1, 2, and 3, the total price will be 1+10+100 = 111 yen.
The result is "YES", because Cucumber Boy can buy any set of k unique cucumbers.
1)

    
{1000,1,10,100}
1109
3
Returns: "NO"
This case is the same as the example 0, except for the value of budget.

If he chooses cucumbers 0, 2, and 3, the total price will be 1000+10+100 = 1110 yen.
1110 yen is greater than the budget therefore the result is "NO".
2)

    
{33,4}
33
1
Returns: "YES"

3)

    
{1,1,1,1,1,1}
2
4
Returns: "NO"

4)

    
{1000,1000,1000,1000,1000,1000,1000,1000,1000}
10000
9
Returns: "YES"

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/


#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class CucumberMarket{
  public:
	string check(vector <int> price, int budget, int k){
		  sort (price.begin(), price.end());
		  int sum = 0;
		  for(int i=0; i<k; ++i){
		  	sum += price[price.size()-1-i];
		  	if (sum>budget){
		  		return "NO";
		  	}
		  } 
		  return "YES";
	}
};
