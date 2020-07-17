// Minimum Spanning Tree

// spanningTree(V, E, graph): Create parent array to store parent of particular node, key array to store minimum weight and initialize it to infinity.
//     also create an array mstSet to store visited nodes and initialize it to false, initialize cost=0.
//     make key[0] = 0 and parent[0] = -1 since it is source vertex.
//     for(count=0 to V-1): u = minKey(key, mstSet, V) and make mstSet[u] = true.
//         for(v=0 to V): 
//             if(v is not visited and graph[u][v] < key[v]) then parent[v] = u and key[v] = graph[u][v].
//     for(i=0 to V): cost = cost + graph[i][parent[i]].
//     return cost. 

// minKey(key, mstSet, V): initialize min to infinity.
//     for(v=0 to V):
//         if(v is not visited and key[v] < min) then min = key[v] and min_index = v.
//     return min_index.

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int minKey(int key[], bool mstSet[], int V){
    int min = INT_MAX , min_index;
    for(int v=0; v<V; v++){
        if(mstSet[v] == false && key[v] < min){
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int spanningTree(int V, int E, vector<vector<int> > &graph) {
    int parent[V],key[V],cost=0;
    bool mstSet[V];

    for(int i=0;i<V;i++){
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    for(int count=0; count < V-1; count++){
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for(int v=0; v<V; v++){
            if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }

        }
    }
    for(int i=1; i<V; i++)
        cost = cost + graph[i][parent[i]];

    return cost;
}

int main() {
	int T;
	cin>>T;
	while(T--){
        int V,E;
        cin>>V>>E;
        vector<vector<int> > graph(V, vector<int>(V, INT_MAX));
        int i=0;
        while(i++ < E){
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }
        cout<<spanningTree(V, E, graph)<<endl;
    }
    return 0;
}