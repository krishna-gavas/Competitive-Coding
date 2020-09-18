// Bleak Numbers

// Question:
// Given an integer, check whether it is Bleak or not.
// A number ‘n’ is called Bleak if it cannot be represented as sum of a positive number x and set bit count in x, 
// i.e., x + countSetBits(x) is not equal to n for any non-negative number x.

// Example 1:
// Input: 4
// Output: 1

// Example 2:
// Input: 3
// Output: 0

// Your Task:
// You don't need to read or print anything. Your task is to complete the function is_bleak() which takes n as input 
// parameter and returns 1 if n is not a Bleak number otherwise returns 0.

#include<iostream>
#include<bitset>
using namespace std;

class Solution
{
public:
	int is_bleak(int n)
	{
	    int bleak = 1;
	    for(int i=1; i<n; i++){
	        bitset<16> num(i);
	        if(i + num.count() == n){
	            bleak = 0;
	            break;
	        }
	    }
	    return bleak;
	}
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}