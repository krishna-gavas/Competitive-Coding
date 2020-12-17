// Kth smallest element(using Heapsort)

// Question:
// Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest 
// element in the given array. It is given that all array elements are distinct.

// Input:
// The first line of input contains an integer T, denoting the number of testcases. Then T test cases follow. Each 
// test case consists of three lines. First line of each testcase contains an integer N denoting size of the array. 
// Second line contains N space separated integer denoting elements of the array. Third line of the test case 
// contains an integer K.

// Output:
// Corresponding to each test case, print the kth smallest element in a new line.

// Example:
// Input:
// 2
// 6
// 7 10 4 3 20 15
// 3
// 5
// 7 10 4 20 15
// 4
// Output:
// 7
// 15

#include <iostream>
#include <algorithm>
using namespace std;

int kthSmallest(int *, int, int, int);
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        cout<<kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}// } Driver Code Ends


//User function template for C++

void heapify(int A[], int n, int i){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int large = i;
    if(l < n && A[l] > A[i])
        large = l;
    if(r < n && A[r] > A[large])
        large = r;
    if(large != i){
        swap(A[i], A[large]);
        heapify(A, n, large);
    }
}

void buildHeap(int A[], int n){
    for(int i=(n/2)-1;i>=0;i--)
        heapify(A, n, i);
}


int heapSort(int A[], int n, int k){
    buildHeap(A, n);
    for(int i=n-1;i>=0;i--){
        if(i == k-1)
            return A[0];
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
    return 0;
}

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function
int kthSmallest(int A[], int l, int r, int k) {
    int n = r+1;
    heapSort(A, n, k);
}