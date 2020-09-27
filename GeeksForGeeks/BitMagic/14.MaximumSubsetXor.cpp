// Maximum Subset XOR

// Question:
// Given a set of positive integers. The task is to complete the function maxSubarrayXOR which returns an integer 
// denoting the maximum XOR subset value in the given set.

// Input Format:
// The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test 
// case contains two lines. The first line of input contains an integer N denoting the size of the array A[]. Then 
// in the next line are N space separated values of the array.

// Output Format:
// For each test case in a new line output will be the maximum XOR subset value in the given set.

// Your Task:
// You need to complete the function maxSubarrayXOR.

// Example:
// Input:
// 2
// 3
// 2 4 5
// 3
// 9 8 5
// Output:
// 7
// 13

// Solution:
// maxSubarrayXOR(A,n): return XOR(A,0,n,0)

// XOR(A,a,n,i): 
//     if(i == n) return a
//     else return max(XOR(s,a^s[i],n,i+1), XOR(s,a,n,i+1)) (i.e maximum of including ith element and not including it)

#include <iostream>
using namespace std;
 
#define INT_BITS 32
int maxSubarrayXOR(int [], int n);
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];

       cout<<maxSubarrayXOR(a,n)<<endl;
    }
}

int XOR(int s[],int a,int n,int i){
    if(i==n)
        return a;
    else 
        return max(XOR(s,a^s[i],n,i+1), XOR(s,a,n,i+1));
}

int maxSubarrayXOR(int A[], int n)
{
    return XOR(A,0,n,0);
}
