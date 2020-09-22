// Convert array into Zig-Zag fashion

// Question:
// Given an array Arr (distinct elements) of size N. Rearrange the elements of array in zig-zag fashion. The 
// converted array should be in form a < b > c < d > e < f. The relative order of elements is same in the output 
// i.e you have to iterate on the original array only.

// Input:
// N = 7
// Arr[] = {4, 3, 7, 8, 6, 2, 1}
// Output: 3 7 4 8 2 6 1

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function zigZag() which takes the 
// array of integers arr and n as parameters and returns void. You need to modify the array itself.

// Solution: 
// zigZag(): 
//     for(i=0 to n-1):
//         if(i is even and arr[i] > arr[i+1]) then swap(arr[i],arr[i+1])
//         else if(i is odd and arr[i] < arr[i+1]) then swap(arr[i],arr[i+1])
//     return

#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:	
	void zigZag(int arr[], int n) {
	    for(int i=0;i<n-1;i++){
	        if(i%2 == 0 && arr[i] > arr[i+1])
	            swap(arr[i],arr[i+1]);
	        else if(i%2 == 1 && arr[i] < arr[i+1])
	            swap(arr[i],arr[i+1]);
	    }
	    return;
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.zigZag(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}