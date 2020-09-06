// Binary Search

// Question:
// Given a sorted array of integers and a key to be searched in the array. Print the position of the key in 
// the array, if present. If it's not present in the array, report it. 

// Input:
// The first line contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test 
// case consists of 3 lines. First line of each test case contains an integer N denoting the size of the array. 
// Second line of each test case consists of 'N' space separated integers denoting the elements of the array A[]. 
// The third line contains a key 'k' .

// Output:
// Prints the position of the key if its present in the array else print -1 if the key is not present in the array.

// User Task:
// You don't need to read input or print anything. Your task is to complete the function bin_search() which takes 
// the array A[], key k and the leftmost and the rightmost index in the array (left and right respectively) and 
// returns the position where the key k occurs in the array. If it's not present, return -1.

// Example:
// Input:
// 2
// 5
// 1 2 3 4 5 
// 4
// 5
// 11 22 33 44 55
// 445

// Output:
// 3
// -1

#include <iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,K,left,right,mid,flag=0;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        cin>>K;
        left = 0;
        right = N-1;
        while(left <= right){
            mid = (left + right)/2;
            if(A[mid] == K){
                flag = 1;
                cout<<mid<<endl;
                break;
            }
            else if(A[mid] < K)
                left = mid+1;
            else if(A[mid] > K)
                right = mid-1;
        }
        if(flag==0)
            cout<<-1<<endl;
    }
    return 0;
}
