// Detect cycle in an directed graph(using Topological sort)

// isCyclic(int V, vector<int> g[]): create an array to store indegree of all nodes and initialize count to 0.
//     Create a queue and push all the nodes to it whose inDegree is 0.
//     while(q is not empty): pop the front of q and store it in start, push start to result vector.
//         for(it = g[start].begin() to g[start].end()): increment indegree[*it] and if(indegree[*it] == 0) then push *it to q.
//         increment count.
//     if(count != V) return true else return false.

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool isCyclic(int V, vector<int> g[])
{
    vector<int> res;
    vector<int> :: iterator it;
    queue<int> q;
    int indegree[V],count=0,start;
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
        res.push_back(start);
        for(it = g[start].begin(); it != g[start].end(); it++){
            indegree[*it]--;
            if(indegree[*it] == 0)
                q.push(*it);
        }
        count++;
    }
    if(count != V)
        return true;
    else 
        return false;
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

        cout<<isCyclic(V, adj)<<endl;
        // vector<int> res = isCyclic(V, adj);
        // for(int i=0;i<res.size();i++)
        //     cout<<res[i]<<" ";
        // cout<<endl;
    }
    return 0;
}

