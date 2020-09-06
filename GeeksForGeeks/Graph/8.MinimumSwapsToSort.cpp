// Minimum Swaps to Sort

// Question:
// Given an array of integers. Find the minimum number of swaps required to sort the array in non-decreasing order.

// Input:
// The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. 
// Each test case contains an integer N denoting the no of element of the array A[ ]. In the next line are N 
// space separated values of the array A[ ] .

// Output:
// For each test case in a new line output will be an integer denoting  minimum umber of swaps that are  
// required to sort the array.

// User Task:
// You don't need to read input or print anything. Your task is to complete the function minSwaps() which takes 
// the array arr[] and its size N as inputs and returns an integer denoting the minimum number of swaps required 
// to sort the array. If the array is already sorted, return 0. 

// Example(To be used only for expected output):
// Input:
// 2
// 5
// 1 5 4 3 2
// 4
// 8 9 16 15

// Output:
// 2
// 1

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void Swap(int A[],int i ,int t){
	int z=0;
	
    z=A[i];
	A[i]=A[t];
    A[t]=z;
}

int minSwaps(int A[], int N){
    int count = 0,min,begin=0,minIndex;
    for(int i=begin;i<N-1;i++){
        min = A[i];
        minIndex = i;
        for(int j=i+1;j<N;j++){
            if(A[j] < min){
                min = A[j];
                minIndex = j;
            }
        }
        if(i != minIndex){
            Swap(A,i,minIndex);
            count++;
        }
    }
    return count;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        cout<<minSwaps(A,N)<<endl;
    }
}