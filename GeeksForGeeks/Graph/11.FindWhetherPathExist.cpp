// Find whether path exist

// Question:
// Given a N X N matrix (M) filled with 1, 0, 2, 3. The task is to find whether there is a path possible from 
// source to destination, while traversing through blank cells only. You can traverse up, down, right and left.

// A value of cell 1 means Source.
// A value of cell 2 means Destination.
// A value of cell 3 means Blank cell.
// A value of cell 0 means Blank Wall.
// Note: there is only single source and single destination.

// Input:
// The first line of input is an integer T denoting the no of testcases. Then T test cases follow. Each test case consists of 2 lines. The first line of each test case contains an integer N denoting the size of the square matrix. Then in the next line are N*N space separated values of the matrix (M).

// Output:
// For each test case in a new line print 1 if the path exist from source to destination else print 0.

// Example:
// Input:
// 2
// 4
// 3 0 0 0 0 3 3 0 0 1 0 3 0 2 3 3 
// 3
// 0 3 2 3 0 0 1 0 0

// Output:
// 1
// 0

// Solution:
// Create a vis matrix and initialize it with false and initialize out = 0.
// Create a queue<pair<int, int> > for BFS traversal.
// push (a,b) to queue and make vis[a][b] = true.
// while(q is not empty): vali = q.front().first , valj = q.front().second and pop front of q.
//     if(vali == x && valj == y) then out = 1 and break out of the loop. 
//     if( (A[vali-1][valj]==3 || A[vali-1][valj]==2) and vis[vali-1][valj]== false)(i.e Top neighbor is valid) then 
//         push (vali-1,valj) to q, make vis[vali-1][valj] = true .
//     perform similar operation for bottom, right and left neighbour.
// print out.

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,a,b,x,y,out=0;
        cin>>N;
        int A[N][N];
        bool vis[N][N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>A[i][j];
                vis[i][j] = false;
                if(A[i][j] == 1){
                    a = i;
                    b = j;
                }
                if(A[i][j] == 2){
                    x = i;
                    y = j;
                }
            }
        }
        queue<pair<int, int> > q;
        q.push(make_pair(a,b));
        vis[a][b] = true;
        while(!q.empty()){

            int vali = q.front().first, valj = q.front().second;
            q.pop();
            if(vali == x && valj == y){
                out = 1;
                break;
            }
            if((vali-1) >= 0 && (A[vali-1][valj]==3 || A[vali-1][valj]==2) && vis[vali-1][valj]== false){    // Top
                q.push(make_pair(vali-1,valj));
                vis[vali-1][valj] = true;
            }
            if((vali+1) < N && (A[vali+1][valj]==3 || A[vali+1][valj]==2) && vis[vali+1][valj]== false){    // Bottom
                q.push(make_pair(vali+1,valj));
                vis[vali+1][valj] = true;
            }
            if((valj+1) < N && (A[vali][valj+1]==3 || A[vali][valj+1]==2) && vis[vali][valj+1]== false){   // Right
                q.push(make_pair(vali,valj+1));
                vis[vali][valj+1] = true;
            }
            if((valj-1) >= 0 && (A[vali][valj-1]==3 || A[vali][valj-1]==2) && vis[vali][valj-1]== false){    // Left
                q.push(make_pair(vali,valj-1));
                vis[vali][valj-1] = true;
            }
        }
        cout<<out<<endl;
    }
    return 0;
}