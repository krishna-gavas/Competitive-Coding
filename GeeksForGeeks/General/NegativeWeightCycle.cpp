// Negative weight cycle(using Bellman Ford Algorithm)

// Question:
// Given a graph, the task is to check if it contains a negative weight cycle or not.

// Input:
// The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. 
// Each test case contains 2 lines the first line contains two space separated integers v and e denoting the no of 
// vertices and no of edges respectively. Then in the next line are 3*e space separated values x,y,z denoting an 
// edge from x to y with a weight of z.

// Output:
// For each test case in a new line print 0 if there is no negative weight cycle else print 1.

// Example:
// Input:
// 2
// 5 8
// 0 1 -1 0 2 4 1 2 3 1 3 2 1 4 2 3 2 5 3 1 1 4 3 -3
// 3 3
// 0 1 -5 1 2 -6 2 0 -9
// Output:
// 0
// 1

// Solution:
// BellmanFord(): create an array dis[] to store distance and initialize it with INT_MAX, make dis[0] = 0
//     iterate over the graph for V-1 times
//         for every iteration relax all edges as follows:
//             if (dis[u] != INT_MAX && dis[u] + w < dis[v]) 
//                 dis[v] = dis[u] + w;
//     after completing V-1 iteration, iterate one more time and check whether we get any difference in edge weight 
//     if so then the graph contains negative weight cycle else not


#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool BellmanFord(int V, int E, vector<pair<int, pair<int, int> > > &graph) {
    int dis[V];

    for(int i=0;i<V;i++){
        dis[i] = INT_MAX;
    }
    dis[0] = 0;

    for (int i = 0; i < V - 1; i++) {  
        for(int j=0;j<E;j++){
            int u = graph[j].second.first;
            int v = graph[j].second.second;
            int w = graph[j].first;
            if (dis[u] != INT_MAX && dis[u] + w < dis[v]) 
                dis[v] = dis[u] + w;
        }
    } 
    for(int j=0;j<E;j++){
        int u = graph[j].second.first;
        int v = graph[j].second.second;
        int w = graph[j].first;
        if (dis[u] != INT_MAX && dis[u] + w < dis[v]) 
            return true;
    }
    return false;
}

int main() {
	int T;
	cin>>T;
	while(T--){
        int V,E;
        cin>>V>>E;
        vector<pair<int, pair<int, int> > > graph;
        int i=0;
        while(i++ < E){
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            graph.push_back({w,{u,v}});
        }
        cout<<BellmanFord(V, E, graph)<<endl;
    }
    return 0;
}