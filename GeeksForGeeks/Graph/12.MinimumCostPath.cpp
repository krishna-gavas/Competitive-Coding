// Minimum Cost Path

// Question:
// Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse 
// through that cell, we need to find a path from top left cell to bottom right cell by which total cost incurred 
// is minimum. You can move in 4 directions : up, down, left an right.

// Note : It is assumed that negative cost cycles do not exist in input matrix.

// Input:
// The first line of input will contain number of testcases T. Then T test cases follow. Each test case contains 
// 2 lines. The first line of each test case contains an integer N denoting the size of the grid. Next line of 
// each test contains a single line containing N*N space separated integers depicting the cost of respective cell 
// from (0,0) to (N,N).

// Output:
// For each test case output a single integer depecting the minimum cost to reach the destination.

// Example:
// Input:
// 2
// 5
// 31 100 65 12 18 10 13 47 157 6 100 113 174 11 33 88 124 41 20 140 99 32 111 41 20
// 2
// 42 93 7 14

// Output:
// 327
// 63

// Solution:
// Create a dist matrix to store minimum distance from (0,0) to (i,j) and initialize it with INT_MAX and store dis[0][0]=A[0][0];
// Create a queue<pair<int,int> > and push (0,0) to it.
// while(q is not empty):  vali = q.front().first , valj = q.front().second and pop front of q.
//     for(i=0 to 4): k = vali+x[i] and l = valj+y[i] where x contains {-1,1,0,0} and y contains {0,0,1,-1}.
//         if(k and l are within the range and dis[k][l]>(dis[vali][valj]+A[k][l]))
//             dis[k][l] = (dis[vali][valj]+A[k][l]) and push (k,l) to q.
// print dis[N-1][N-1].


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,vali,valj,k,l;
        cin>>N;
        int A[N][N];
        int dis[N][N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>A[i][j];
                dis[i][j]=INT_MAX;
            }
        }
        int x[4] = {-1,1,0,0};
        int y[4] = {0,0,1,-1};
        dis[0][0]=A[0][0];

        queue<pair<int,int> >q;
        q.push(make_pair(0,0));

        while(!q.empty()){
            vali = q.front().first;
            valj = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                k = vali+x[i];
                l = valj+y[i];
                if( k>=0 && k<N && l>=0 && l<N &&  dis[k][l]>(dis[vali][valj]+A[k][l])){
                    dis[k][l]=dis[vali][valj]+A[k][l];
                    q.push(make_pair(k,l));    
                }   
            }
        }
        cout<<dis[N-1][N-1]<<endl;

    }
    return 0;
}