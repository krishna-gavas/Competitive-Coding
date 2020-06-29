// Minimum Cost Path

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