// BFS of Graph
// Time: O(N+E)
// Space: O(N)

// Question:
// Given a directed graph. The task is to do Breadth First Search of this graph.

// Input:
// The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases 
// follow. Each test case consists of two lines. Description of testcases is as follows: The First line of each 
// test case contains two integers 'N' and 'E'  which denotes the no of vertices and no of edges respectively. 
// The Second line of each test case contains 'E'  space separated pairs u and v denoting that there is a edge 
// from u to v .

// Output:
// For each testcase, print the BFS of the graph starting from 0.

// Note: The expected output button always produces BFS starting from node 0.

// User Task:
// You don't need to read input or print anything. Your task is to complete the function bfs() takes the Graph and 
// the number of vertices as its input and returns a list containing the BFS traversal of the graph starting from 
// the 0th vertex.

// Example:
// Input:
// 2
// 5 4
// 0 1 0 2 0 3 2 4
// 3 2
// 0 1 0 2

// Output:
// 0 1 2 3 4    // BFS from node 0
// 0 1 2

// Solution:
// bfs(g, N): Create a queue and push first node to it and make visited[first node] = true.
//     while(queue is not empty): pop front of queue and store it in start, push start to result vector.
//         for(i=0 to size of g[start]): 
//             if(vis[g[start][i]] is false) then male vis[g[start][i]] = true and push g[start][i] to queue.
//     return result vector.

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


vector <int> bfs(vector<int> g[], int N)
{
    vector<int> res;
    queue<int> q;
    bool *vis = new bool[N];
    memset(vis, false, N);
    q.push(0);
    vis[0] = true;
    while(!q.empty()){
        int start = q.front();
        res.push_back(start);
        q.pop();
        for(int i=0; i <g[start].size();i++){
            if(!vis[g[start][i]]){
                vis[g[start][i]] = true;
                q.push(g[start][i]);
            }
        }
    }
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

        vector<int> res = bfs(g, N);
        for(int i=0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}

