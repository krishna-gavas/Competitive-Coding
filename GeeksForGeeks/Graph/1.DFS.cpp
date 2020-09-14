// DFS of Graph
// Time: O(N+E)
// Space: O(N)

// Question:
// Given a connected undirected graph. Perform a Depth First Traversal of the graph.
// Note: Use recursive approach.

// Input:
// The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases 
// follow. Each test case consists of two lines. Description of testcases is as follows: The First line of each 
// test case contains two integers 'N' and 'E'  which denotes the no of vertices and no of edges respectively. 
// The Second line of each test case contains 'E'  space separated pairs u and v denoting that there is a edge 
// from u to v .

// Output:
// For each testcase, print the nodes while doing DFS starting from node 0.

// Your task:
// You don't need to read input or print anything. Your task is to complete the function dfs() which takes the Graph 
// and the number of vertices as inputs and returns a list containing the DFS Traversal of the graph starting from 
// the 0th node.

// Example:
// Input:
// 2
// 5 4
// 0 1 0 2 0 3 2 4
// 4 3
// 0 1 1 2 0 3

// Output:
// 0 1 2 4 3   
// 0 1 2 3

// Solution:
// dfs(g, N): Create a vector to store the result. Create a visited array and initialize it to false.
//     call myDFS(g,N,0,res,vis) and return the result vector

// myDFS(g,N,i,res,vis): make visited[i] = true, push i to result vector.
//     traverse the vector g[i] and if any of its adjacent nodes are unvisited then call myDFS(g,N,*it,res,vis).

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void myDFS(vector<int> g[], int N, int i,vector<int> &res,bool vis[]){
    vis[i] = true;
    res.push_back(i);
    vector<int> :: iterator it;
    for(it = g[i].begin(); it != g[i].end(); it++){
        if(!vis[*it]){
            myDFS(g,N,*it,res,vis);
        }
    }
}

vector <int> dfs(vector<int> g[], int N)
{
    vector<int> res;
    bool *vis = new bool[N];
    // memset(vis, false, sizeof(vis));
    for (int i = 0; i < N; i++) 
        vis[i] = false;
    myDFS(g,N,0,res,vis);
    return res;
} 

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,E;
        cin>>N>>E;
        vector<int> g[N];
        bool vis[N];

        memset(vis, false, sizeof(vis));

        for(int i=0;i<E;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> res = dfs(g, N);
        for(int i=0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}

