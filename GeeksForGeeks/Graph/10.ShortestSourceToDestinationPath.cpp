// Shortest Source to Destination Path

// Question:
// Given a boolean 2D matrix (0-based index), find whether there is path from (0,0) to (x,y) and if there is one 
// path, print the minimum no of steps needed to reach it, else print -1 if the destination is not reachable. 
// You may move in only four direction ie up, down, left and right. The path can only be created out of a cell 
// if its value is 1.

// Input:
// The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. 
// Each test case contains two lines . The first line of each test case contains two integers n and m denoting 
// the size of the matrix. Then in the next line are n*m space separated values of the matrix. The following 
// line after it contains two integers x and y denoting the index of the destination.

// Output:
// For each test case print in a new line the min no of steps needed to reach the destination.

// Example:
// Input:
// 2
// 3 4
// 1 0 0 0 1 1 0 1 0 1 1 1
// 2 3
// 3 4
// 1 1 1 1 0 0 0 1 0 0 0 1
// 0 3
// Output:
// 5
// 3

// Solution:
// Create a vis matrix and initialize it with false. if A[x][y] or A[0][0] is 0 then print -1 and continue with next test case.
// Create a map<pair<int,int>,int> to store distance and a queue<pair<int, int> > for BFS traversal.
// make mp[{0,0}] = 0 , push (0,0) to queue and make vis[0][0] = true.
// while(q is not empty): vali = q.front().first , valj = q.front().second and pop front of q.
//     if(vali == x && valj == y) then out = mp[{vali, valj}] and break out of the loop. 
//     if( A[vali-1][valj]==1 and vis[vali-1][valj]== false)(i.e Top neighbor is valid) then 
//         push (vali-1,valj) to q, make vis[vali-1][valj] = true and mp[{vali-1,valj}] = mp[{vali,valj}] + 1.
//     perform similar operation for bottom, right and left neighbour.
// print out.

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,M,x,y,out=-1;
        cin>>N>>M;
        int A[N][M];
        bool vis[N][M];
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++){
                cin>>A[i][j];
                vis[i][j] = false;
            }
        cin>>x>>y;
        if (A[x][y]==0 || A[0][0]==0){
            cout<<"-1\n"; 
            continue; 
        }
        map<pair<int,int>,int> mp;
        queue<pair<int, int> > q;
        mp[{0,0}] = 0;
        q.push({0,0});
        vis[0][0] = true;
        while(!q.empty()){

            int vali = q.front().first, valj = q.front().second;
            q.pop();
            if(vali == x && valj == y){
                out = mp[{vali,valj}];
                break;
            }
            if((vali-1) >= 0 && A[vali-1][valj]==1 && vis[vali-1][valj]== false){    // Top
                q.push({vali-1,valj});
                vis[vali-1][valj] = true;
                mp[{vali-1,valj}] = mp[{vali,valj}] + 1;
            }
            if((vali+1) < N && A[vali+1][valj]==1 && vis[vali+1][valj]== false){    // Bottom
                q.push({vali+1,valj});
                vis[vali+1][valj] = true;
                mp[{vali+1,valj}] = mp[{vali,valj}] + 1;
            }
            if((valj+1) < M && A[vali][valj+1]==1 && vis[vali][valj+1]== false){   // Right
                q.push({vali,valj+1});
                vis[vali][valj+1] = true;
                mp[{vali,valj+1}] = mp[{vali,valj}] + 1;
            }
            if((valj-1) >= 0 && A[vali][valj-1]==1 && vis[vali][valj-1]== false){    // Left
                q.push({vali,valj-1});
                vis[vali][valj-1] = true;
                mp[{vali,valj-1}] = mp[{vali,valj}] + 1;
            }
        }
        cout<<out<<endl;
    }
    return 0;
}