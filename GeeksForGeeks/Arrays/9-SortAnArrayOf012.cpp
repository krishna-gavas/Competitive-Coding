// Sort an array of 0's, 1's and 2's

// Question:
// Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.

// Input:
// The first line contains an integer 'T' denoting the total number of test cases. Then T testcases follow. Each 
// testcases contains two lines of input. The first line denotes the size of the array N. The second lines contains 
// the elements of the array A separated by spaces.

// Output: 
// For each testcase, print the sorted array.

// Example:
// Input :
// 2
// 5
// 0 2 1 2 0
// 3
// 0 1 0

// Output:
// 0 0 1 2 2
// 0 0 1

// Solution:
// Maintain 3 variables low, high and mid
// low - all elements before low are 0
// mid - all elements between low and mid are 1
// high - all elements after high are 2
// for(mid = 0 to high):
// 	if(arr[mid] == 0) then swap(arr[mid],arr[low]) and increment both low and mid 
// 	else if(arr[mid] == 2) then swap(arr[mid],arr[high]) and decrement high
// 	else increment mid

#include <iostream>
#include <algorithm>
using namespace std;

void sort012(int A[], int N)
{
    int low=0,mid=0,high=N-1;
    for(mid=0; mid <= high; ){
        if(A[mid] == 0){
            swap(A[mid], A[low]);
            low++;
            mid++;
        }
        else if(A[mid] == 2){
            swap(A[mid], A[high]);
            high--;
        }
        else
            mid++;
    }
}

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}
