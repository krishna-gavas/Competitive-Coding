// Strongly Connected Components (Kosaraju's Algo)

// Question:
// Given a graph with N nodes and M directed edges. Your task is to complete the function kosaraju() which returns 
// an integer denoting the number of strongly connected components in the graph.

// Input:
// The first line of input contains an integer T. Then T test cases follow. Each test case contains two integers 
// N and M. In the next line there are M space-separated values u,v denoting an edge from u to v.

// Output:
// For each test case in a new line output will an integer denoting the no of strongly connected components present 
// in the graph.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function kosaraju() which takes 
// the number of vertices V and adjacency list of the graph as inputs and returns an integer denoting the number 
// of strongly connected components in the given graph.

// Example:
// Input:
// 2
// 5 5
// 1 0 0 2 2 1 0 3 3 4
// 3 3
// 0 1 1 2 2 0

// Output:
// 3
// 1

// Solution:
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