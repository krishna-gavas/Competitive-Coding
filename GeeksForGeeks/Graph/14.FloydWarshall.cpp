// Floyd Warshall

// V is the number of Vertices and A[][] is the adjacency matrix.
// for(k=0 to V):
//     for(i=0 to V):
//         for(j=0 to V): 
//             if(A[i][j] > A[i][k] + A[k][j]) then A[i][j] = A[i][k] + A[k][j]

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int V;
        cin>>V;
        int A[V][V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                cin>>A[i][j];
            }
        }
        for(int k=0;k<V;k++){     
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                    if(A[i][j] > A[i][k] + A[k][j])
                        A[i][j] = A[i][k] + A[k][j];
                }
            }
        }
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(A[i][j] == 10000000)
                    cout<<"INF ";
                else 
                    cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}