// Implementing Dijkstra

// dijkstra(g, s, V): dist contains shortest distance from src to i, vis contains true for visited nodes, initialize dist[src] = 0.
//     Pick the minimum distance vertex from the set of unvisited verticesand Mark the picked vertex as processed.
//     Update dist value of the adjacent vertices of the picked vertex as follows: 
//     if(dist[u] + g[u][v] < dist[v]) then  dist[v] = dist[u] + g[u][v].
//     return dist.

// minDistance(dist, vis, V): for(v=0 to V)
//     if (vis[v] == false && dist[v] <= min) then min = dist[v] and min_index = v
//     return min_index.

#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void printSolution(vector<int> dist, int n){
    for(int i=0;i<n;i++)
        cout<<dist[i]<<" ";
} 

int minDistance(vector<int> dist, bool vis[],int V) 
{ 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (vis[v] == false && dist[v] <= min){
            min = dist[v];
            min_index = v; 
        }  
    return min_index; 
}

vector<int> dijkstra(vector<vector<int> > g, int src, int V)
{
    vector<int> dist;       
    bool vis[V];     
    for (int i = 0; i < V; i++){
        dist.push_back(INT_MAX);
        vis[i] = false; 
    }
  
    dist[src] = 0; 
  
    for (int count = 0; count < V - 1; count++) { 
        int u = minDistance(dist, vis, V); 
  
        vis[u] = true; 
  
        for (int v = 0; v < V; v++){
            if (!vis[v] && g[u][v] && dist[u] != INT_MAX 
                && dist[u] + g[u][v] < dist[v]) 
                dist[v] = dist[u] + g[u][v]; 
        }
    } 
    return dist;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int V,s;
        cin>>V;
        vector<vector<int> > g(V);
        for(int i=0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                cin>>g[i][j];
            }
        }

        cin>>s;
        vector<int> res = dijkstra(g, s, V);
        printSolution(res, V);
        cout<<endl;    
    }
    return 0;
}

