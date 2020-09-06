// Topological sort

// Question:
// Given a Directed Graph. Find any Topological Sorting of that Graph.

// Input:
// The first line of input takes the number of test cases then T test cases follow . Each test case contains 
// two lines. The first  line of each test case  contains two integers E and V representing no of edges and the 
// number of vertices. Then in the next line are E  pairs of integers u, v representing an edge from u to v in 
// the graph.

// Output:
// For each test case output will be 1 if the topological sort is done correctly else it will be 0.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function topoSort() which takes 
// the adjacency list of the Graph and the number of vertices (N) as inputs are returns an array consisting of a 
// the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them.

// Example:
// Input
// 2
// 6 6
// 5 0 5 2 2 3 4 0 4 1 1 3
// 3 4
// 3 0 1 0 2 0

// Output:
// 1
// 1

// Solution:
// topoSort(int V, vector<int> g[]): Create a result array using dynamic memory allocation(since C/C++ cannot return pointer to a local variable).
//     create an array to store indegree of all nodes and initialize count to 0.
//     Create a queue and push all the nodes to it whose inDegree is 0.
//     while(q is not empty): pop the front of q and store it in start, res[k++] = start.
//         for(it = g[start].begin() to g[start].end()): increment indegree[*it] and if(indegree[*it] == 0) then push *it to q.
//         increment count.
//     return res.

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool check(int V,int res[], vector<int> g[]){
    vector<int> map(V, -1);
    for(int i=0;i<V;i++)
        map[res[i]]++;
    for(int i=0;i<V;i++)
        for(int v: g[i])
            if(map[i] > map[v])
                return false;
    return true;
}

int* topoSort(int V, vector<int> g[])
{
    int *res = new int[V];
    vector<int> :: iterator it;
    queue<int> q;
    int indegree[V],count=0,start,k=0;
    for (int i = 0; i < V; i++)
        indegree[i] = 0;
    for (int i = 0; i < V; i++)
        for(it = g[i].begin(); it != g[i].end(); it++)
            indegree[*it]++;

    for (int i = 0; i < V; i++)
        if(indegree[i] == 0)
            q.push(i);

    while(!q.empty()){
        start = q.front();
        q.pop();
        res[k++] = start;
        for(it = g[start].begin(); it != g[start].end(); it++){
            indegree[*it]--;
            if(indegree[*it] == 0)
                q.push(*it);
        }
        count++;
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int V,E;
        cin>>V>>E;
        vector<int> adj[V];

        for(int i=0;i<E;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }

        int *res = topoSort(V, adj);
        cout<<check(V, res, adj)<<endl;
        
    }
    return 0;
}

