// Inversion of Array(using Mergesort technique)

// Question:
// Given an array of positive integers. The task is to find inversion count of array.

// Inversion Count : For an array, inversion count indicates how far (or close) the array is from being sorted. If 
// array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is 
// the maximum. 
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

// Input:
// The first line of input contains an integer T denoting the number of test cases. The first line of each test 
// case is N, the size of array. The second line of each test case contains N elements.

// Output:
// Print the inversion count of array.

// Example:
// Input:
// 1
// 5
// 2 4 1 3 5

// Output:
// 3

// Solution:
// In Merge procedure if element(A[j]) in right array is smaller than A[i] in left array
// then add (number of elements from i to mid ) to inversion count
#include <iostream>
#include <algorithm>
using namespace std;

long long int counter;

void Merge(long long A[], long long L,long long mid, long long R){
    long long B[R+1];
    long long i=L,j=mid+1,k=L;
    while(i <= mid && j <= R){
        if(A[i] <= A[j])
            B[k++] = A[i++];
        else{
            B[k++] = A[j++];
            counter += mid - i + 1;
        }
    }
    while(i <= mid)
        B[k++] = A[i++];
    while(j <= R)
        B[k++] = A[j++];
        
    for(long long i=L;i<=R;i++)
        A[i] = B[i];
}

void MergeSort(long long A[], long long L, long long R){
    if(L < R){
        long long mid = (L+R)/2;
        MergeSort(A,L,mid);
        MergeSort(A,mid+1,R);
        Merge(A,L,mid,R);
    }
}

long long int inversionCount(long long A[], long long N)
{
    counter = 0;
    MergeSort(A,0,N-1);
    return counter;
}

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}