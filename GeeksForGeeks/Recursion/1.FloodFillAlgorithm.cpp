// Flood fill Algorithm(Using BFS)

// Create a 2D vector(similar to 2D array) Mat of order N*M.
// Create a queue of pair<int row, int col> and push pair(x,y) to it.
// initialize oldVal = Mat[x][y] and make Mat[x][y] = K.
// while(q is not empty): initialize x = q.front().first , y = q.front().second and pop front of queue.
//     if(x <0 || x >= N || y<0 || y >= M) then pop  front of queue and continue. 
//     make Mat[x][y] = K.
//     if(x>0 && Mat[x-1][y] == oldVal) then push pair(x-1, y) to q and make Mat[x-1][y] = K.
//     if(x<(N-1) && Mat[x+1][y] == oldVal) then push pair(x+1, y) to q and make Mat[x+1][y] = K.
//     if(y>0 && Mat[x][y-1] == oldVal) then push pair(x, y-1) to q and make Mat[x][y-1] = K.
//     if(y<(M-1) && Mat[x][y+1] == oldVal) then push pair(x, y+1) to q and make Mat[x][y+1] = K.

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,M,x,y,K,X;
        cin>>N>>M;
        vector<vector<int> > Mat(N, vector<int> (M));
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++){
                cin>>X;
                Mat[i][j] = X;
            }
        cin>>x>>y>>K;
        
        queue<pair <int,int> > q;
        int oldVal = Mat[x][y];
        Mat[x][y] = K;
        q.push(make_pair(x, y));

        while(!q.empty()){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            if(x <0 || x >= N || y<0 || y >= M){
                q.pop();
                continue;
            }
            Mat[x][y] = K;
            if(x>0 && Mat[x-1][y] == oldVal){
                q.push(make_pair(x-1, y));
                Mat[x-1][y] = K;
            }
            if(x<(N-1) && Mat[x+1][y] == oldVal){
                q.push(make_pair(x+1, y));
                Mat[x+1][y] = K;
            }
            if(y>0 && Mat[x][y-1] == oldVal){
                q.push(make_pair(x, y-1));
                Mat[x][y-1] = K;
            }
            if(y<(M-1) && Mat[x][y+1] == oldVal){
                q.push(make_pair(x, y+1));
                Mat[x][y+1] = K;
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                cout<<Mat[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
}