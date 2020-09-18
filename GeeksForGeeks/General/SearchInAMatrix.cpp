// Search in a Matrix

// Question:
// Given a matrix mat[] of size n x m, where every row and column is sorted in increasing order, and a number x is 
// given. The task is to find whether element x is present in the matrix or not.
// Expected Time Complexity : O(m + n)

// Input:
// The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. 
// Each test case consists of three lines. First line of each test case consist of two space separated integers N 
// and M, denoting the number of element in a row and column respectively. Second line of each test case consists of 
// N*M space separated integers denoting the elements in the matrix in row major order. Third line of each test 
// case contains a single integer x, the element to be searched.

// Output:
// Corresponding to each test case, print in a new line, 1 if the element x is present in the matrix, 
// otherwise simply print 0.

// Example:
// Input:
// 2
// 3 3
// 3 30 38 44 52 54 57 60 69
// 62
// 1 6
// 18 21 27 38 55 67
// 55

// Output:
// 0
// 1

// Solution:
// for(i=0 to N):
//     if(last element of ith row is >= X) then do a binary search from j=0 to M on ith row


#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,M,X,flag=0;
	    cin>>N>>M;
        int A[N][M];
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                cin>>A[i][j];
        cin>>X;

        for(int i=0;i<N;i++){
            if(A[i][M-1] >= X){
                int L=0,R=M-1,mid;
                while(L <= R){
                    mid = (R + (R-L))/2;
                    if(A[i][mid] == X){
                        flag = 1;
                        break;
                    }
                    else if(A[i][mid] < X)
                        L = mid + 1;
                    else 
                        R = mid - 1;
                }
            }
        }	
		cout<<flag<<"\n";
	}
	return 0;
}