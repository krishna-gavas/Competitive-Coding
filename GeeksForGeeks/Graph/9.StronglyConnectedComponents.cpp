// Strongly Connected Components (Kosaraju's Algo)

// kosaraju(N, g): Create an empty stack and 2 vectors vis1,vis2 and initialize them with false.
//     Do a DFS on the original graph, keeping track of the finish times of each vertex. This can be done with a stack.
//     Reverse the original graph g and store it in tg.
//     Do DFS on the reversed graph, with the vertex on top of the stack and keep marking the vertices visited, 
//     When DFS finishes, all vertices visited will form one Strongly Connected Component hence increment count.

// myDFS(g,N,i,vis): make vis[i] = true. 
//     for(it = g[i].begin() to g[i].end()): if(vis[*it] is false) then call myDFS(g,N,*it,vis).
//     push i to stack.

// revDFS(tg,N,i,vis): make vis[i] = true.
//     for(it = tg[i].begin() to tg[i].end()): if(vis[*it] is false) then call revDFS(tg,N,*it,vis).


#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

stack <int> st;

void myDFS(vector<int> g[], int N, int i,bool vis[]){
    vis[i] = true;
    vector<int> :: iterator it;
    for(it = g[i].begin(); it != g[i].end(); it++){
        if(!vis[*it]){
            myDFS(g,N,*it,vis);
        }
    }
    st.push(i);
}

void revDFS(vector<int> tg[], int N, int i,bool vis[]){
    vis[i] = true;
    vector<int> :: iterator it;
    for(it = tg[i].begin(); it != tg[i].end(); it++){
        if(!vis[*it]){
            revDFS(tg,N,*it,vis);
        }
    }
}

int  kosaraju(int N, vector<int> g[]){
    stack <int> newst;
    st = newst;
    bool *vis1 = new bool[N];
    bool *vis2 = new bool[N];
    for (int i = 0; i < N; i++){
        vis1[i] = false;
        vis2[i] = false;
    }
    for(int i=0;i<N;i++){
        if(!vis1[i])
            myDFS(g,N,i,vis1);

    }

    vector<int> tg[N];
    vector<int> :: iterator it;
    int count=0;
    // Reverse the graph g and store it in tg
    for(int i=0;i<N;i++){
        for(it = g[i].begin(); it != g[i].end(); it++){
            tg[*it].push_back(i);
        }
    }
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis2[node]){
            count++;
            revDFS(tg,N,node,vis2);
        }
    }
    return count;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int V,E,m,n;
        cin>>V>>E;
        vector<int> adj[V];
        for(int i=0;i<E;i++){
            cin>>m>>n;
            adj[m].push_back(n);
        }
        cout<<kosaraju(V, adj)<<endl;
    }
    return 0;
}