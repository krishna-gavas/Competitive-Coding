// Minimum Spanning Tree

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int spanningTree(int V, int E, vector<vector<int>> &graph) {
    
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