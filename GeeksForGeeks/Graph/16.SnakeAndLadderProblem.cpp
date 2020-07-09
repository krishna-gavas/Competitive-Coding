// Snake and Ladder Problem

// initialize board[] to -1 and vis[] to false, while inputing a,b store board[a-1] = b-1.
// mark vis[0] as true, create an object s(0,0) of type Qentry and push s to q.
// while(q is not empty): store front of q in qe, pop front of q and vertex = qe.vertex.
//     if(vertex is N-1) then break.
//     for(i = vertex+1 to vertex+6): 
//         if(vis[i] == false) then vis[i] = true
//             cell.distance = qe.distance + 1
//             if(board[i] != -1) then cell.vertex = board[i] else cell.vertex = i.
//             push cell to q.
// print qe.distance.

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Qentry {
    int vertex;
    int distance;
};

int main(){
    int T;
    cin>>T;
    while(T--){
        int N=30,K,a,b;
        cin>>K;
        int board[30];
        bool vis[30];
        for(int i=0;i<N;i++){
            board[i] = -1;
            vis[i] = false;
        }
        for(int i=0;i<K;i++){
            cin>>a>>b;
            board[a-1] = b-1;
        }

        queue <Qentry> q;
        vis[0] = true;
        Qentry s,qe;
        s.distance = 0;
        s.vertex = 0;
        q.push(s);

        while(!q.empty()){
            qe = q.front();
            q.pop();
            int vertex = qe.vertex;

            if(vertex == N-1)
                break;
                
            for(int i = vertex+1; i <= (vertex+6) && i < N; i++){
                if(vis[i] == false){
                    vis[i] = true;
                    Qentry cell;
                    cell.distance = qe.distance + 1;
                    if(board[i] != -1)
                        cell.vertex = board[i];
                    else 
                        cell.vertex = i;
                    q.push(cell);
                }
            }
        }
        cout<<qe.distance<<endl;
    }
    return 0;
}