// Number of paths(using DP)

// Question:
// The problem is to count all the possible paths from top left to bottom right of a MxN matrix with the constraints 
// that from each cell you can either move to right or down.

// Input:
// The first line of input contains an integer T, denoting the number of test cases. The first line of each test case 
// is M and N, M is number of rows and N is number of columns.

// Output:
// For each test case, print the number of paths.

// Example:
// Input
// 2
// 3 3
// 2 8

// Output
// 6
// 8

#include <iostream>
using namespace std;

int numberOfPaths(int m, int n){
    if(m==1 || n==1)
        return 1;
    return numberOfPaths(m-1,n) + numberOfPaths(m,n-1);
}

int main() {
    int T;
    cin>>T;
    while(T--){
        int M,N,out;
        cin>>M>>N;
        cout<<numberOfPaths(M,N)<<endl;
    }
    return 0;
}
