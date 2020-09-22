// Largest Number formed from an Array

// Question:
// Given a list of non negative integers, arrange them in such a manner that they form the largest number possible.
// The result is going to be very large, hence return the result in the form of a string.

// Input: 
// N = 5
// Arr[] = {3, 30, 34, 5, 9}
// Output: 9534330

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function printLargest() which takes 
// the array of strings arr[] as parameter and returns a string denoting the answer.

// Solution:
// printLargest(): store arr size in n and initialize a result string to empty
//     sort the array of strings with a comparator
//     append the contents of arr to result string 
//     return res

// comparator(s1,s2): create 2 strings first = s1+s2 and second = s2+s1 
//     for(i=0 to first.size()):
//         if(first[i] > second[i]) then return true 
//         else if(first[i] < second[i]) then return false 
//     if the control reaches here means both strings are same so return false

#include <iostream>
#include <string>
#include <vector> 
using namespace std;

class Solution{
public:
	static bool comparator(string s1, string s2){
	    string first = s1+s2;
	    string second = s2+s1;
	    for(int i=0;i<first.size();i++){
	        if(first[i] > second[i])
	            return true;
	        else if(first[i] < second[i])
	            return false;
	    }
	    return false;
	}
	string printLargest(vector<string> &arr) {
	    int n = arr.size();
	    string res = "";
	    sort(arr.begin(),arr.end(),comparator);
	    for(int i=0;i<n;i++)
	        res.append(arr[i]);
	    
	    return res;
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}