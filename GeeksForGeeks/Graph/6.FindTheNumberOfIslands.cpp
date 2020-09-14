// Find the number of islands

//Question:
// Given a Matrix consisting of 0s and 1s. Find the number of islands of connected 1s present in the matrix. 
// Note: A 1 is said to be connected if it has another 1 around it (either of the 8 directions).

// Input:
// The first line of input will be the number of testcases T, then T test cases follow. The first line of each
//  testcase contains two space separated integers N and M. Then in the next line are the NxM inputs of the 
//  matrix A separated by space .

// Output:
// For each testcase in a new line, print the number of islands present.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findIslands() which 
// takes the matrix A and its dimensions N and M as inputs and returns the number of islands of connected 1s 
// present in the matrix. A 1 is said to be connected if it has another 1 around it (either of the 8 directions).

// Example(To be used only for expected output) :
// Input
// 2
// 3 3
// 1 1 0 0 0 1 1 0 1
// 4 4
// 1 1 0 0 0 0 1 0 0 0 0 1 0 1 0 0

// Output
// 2
// 2

// Solution: (just find the count of connected components)

// findIslands: create a matrix vis of size N*M and initialize it to 0, also initialize count=0
//     for(i=0 to N)
//         for(j=0 to M)
//             if(A[i][j] == 1 && vis[i][j] == 0) then increment count and call dfs(A,N,M,i,j,vis)
//     return count

// dfs: make vis[i][j] = 1
//     check if left of A[i][j] is 1 and if it is not visited then call dfs(A,N,M,i,j-1,vis)
//     similarly call dfs for right,top,bottom,left-top,left-bottom,right-top and right-bottom


#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void dfs(vector<int> A[], int N, int M,int i,int j,vector<vector<int> > &vis){
    vis[i][j] = 1;
    if((j-1) >= 0 && A[i][j-1]==1 && vis[i][j-1]==0)
        dfs(A,N,M,i,j-1,vis);
    if((j+1) < M && A[i][j+1]==1 && vis[i][j+1]==0)
        dfs(A,N,M,i,j+1,vis);
    if((i-1) >= 0 && A[i-1][j]==1 && vis[i-1][j]==0)
        dfs(A,N,M,i-1,j,vis);
    if((i+1) < N && A[i+1][j]==1 && vis[i+1][j]==0)
        dfs(A,N,M,i+1,j,vis);
    if((i-1) >= 0 && (j-1) >= 0 && A[i-1][j-1]==1 && vis[i-1][j-1]==0)
        dfs(A,N,M,i-1,j-1,vis);
    if((i+1) < N && (j-1) >= 0 && A[i+1][j-1]==1 && vis[i+1][j-1]==0)
        dfs(A,N,M,i+1,j-1,vis);
    if((i-1) >= 0 && (j+1) < M && A[i-1][j+1]==1 && vis[i-1][j+1]==0)
        dfs(A,N,M,i-1,j+1,vis);
    if((i+1) < N && (j+1) < M && A[i+1][j+1]==1 && vis[i+1][j+1]==0)
        dfs(A,N,M,i+1,j+1,vis);
}

int findIslands(vector<int> A[], int N, int M) {
    vector<vector<int> > vis(N, vector<int>(M, 0));
    int count=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(A[i][j] == 1 && vis[i][j] == 0){
                dfs(A,N,M,i,j,vis);
                count++;
            }
        }
    }
    return count;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,M;
        cin>>N>>M;
        vector<int> A[N];
        for(int i=0;i<N;i++){
            vector<int> temp(M);
            A[i] = temp;
            for(int j=0;j<M;j++){
                cin>>A[i][j];
            }
        }
        cout<<findIslands(A, N, M)<<endl;    
    }
    return 0;
}

