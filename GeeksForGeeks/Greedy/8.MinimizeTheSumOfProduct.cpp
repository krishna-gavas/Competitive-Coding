// Minimize the sum of product

// Question:

// You are given two arrays, A and B, of equal size N. The task is to find the minimum value of 
// A[0] * B[0] + A[1] * B[1] +…+ A[N-1] * B[N-1], where shuffling of elements of arrays A and B is allowed.

// Input:
// The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each 
// test case contains three lines. The first line contains an integer N denoting the size of the arrays. In 
// the second line are N space separated values of the array A[], and in the last line are N space separated 
// values of the array B[].

// Output:
// For each test case, print the minimum sum.

// Example:
// Input:
// 2
// 3 
// 3 1 1
// 6 5 4
// 5
// 6 1 9 5 4
// 3 4 8 2 4
// Output:
// 23 
// 80

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N;
        long long int sum=0;
        cin>>N;
        int A[N],B[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        for(int i=0;i<N;i++)
            cin>>B[i];
        sort(A,A+N);
        sort(B,B+N);
        for(int i=0,j=N-1;i<N;i++,j--){
            sum = sum + (A[i] * B[j]);
        }
        cout<<sum<<endl;
    }
    return 0;
}
