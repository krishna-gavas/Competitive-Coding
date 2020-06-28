// Find whether path exist

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