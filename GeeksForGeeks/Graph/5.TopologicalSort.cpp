// Topological sort

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

