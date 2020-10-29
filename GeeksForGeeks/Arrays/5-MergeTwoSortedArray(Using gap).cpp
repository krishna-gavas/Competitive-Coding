//Merge Two sorted array without extra space(Using gap approach)

// Question:
// Given two sorted arrays arr1[] and arr2[] in non-decreasing order with size n and m. The task is to merge 
// the two sorted arrays into one sorted array (in non-decreasing order).

// Input:
// First line contains an integer T, denoting the number of test cases. First line of each test case contains two space separated integers X and Y, denoting the size of the two sorted arrays. Second line of each test case contains X space separated integers, denoting the first sorted array P. Third line of each test case contains Y space separated integers, denoting the second array Q.

// Output:
// For each test case, print (X + Y) space separated integer representing the merged array.

// Example:
// Input:
// 2
// 4 5
// 1 3 5 7
// 0 2 6 8 9
// 2 3
// 10 12
// 5 18 20

// Output:
// 0 1 2 3 5 6 7 8 9
// 5 10 12 18 20

// Solution:
// Create a varaiable called gap whose initial value is (X+Y+1)/2
// while(gap >= 1):
// 	for(i=0;i+gap<X+Y;i++): 
// 		if(A[i+gap] < A[i]) swap(A[i],A[i+gap])
// 	update gap = (gap+1)/2

#include <iostream>
using namespace std;

class Solution{
public:
    
	void merge(int a1[], int a2[], int n, int m) {
	    int i=n-1, j=0;
	    while(i >= 0 && j < m){
	        if(a1[i] > a2[j])
	            swap(a1[i],a2[j]);
	        i--;
	        j++;
	    }
	    sort(a1,a1+n);
	    sort(a2,a2+m);
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}