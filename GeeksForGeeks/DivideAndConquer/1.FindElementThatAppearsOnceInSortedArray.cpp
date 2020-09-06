// Find the element that appears once in sorted array

// Question:
// Given a sorted array A, size N, of integers; every element appears twice except for one. Find that element 
// that appears once in array.

// Input:
// The first line of input consists of T, the number of the test cases. T testcases follow. Each testcase contains 
// two lines of input.
// The first line of each test case contains the size of the array, and the second line has the elements of the array.

// Output:
// For each testcase, in a new line, print the number that appears only once in the array.

// Example:
// Input:
// 1
// 11
// 1 1 2 2 3 3 4 50 50 65 65
// Output:
// 4

#include <iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        long int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        for(int i=0;i<N;i=i+2){
            if(A[i] != A[i+1]){
                cout<<A[i]<<endl;
                break;
            }
        }
    }
    return 0;
}