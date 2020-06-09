// Detect cycle in an undirected graph


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool isCyclic(vector<int> g[], int V)
{
    vector<int> res;
    vector<int> :: iterator it;
    queue<int> q;
    int flag[V],count=0,start;
    for (int i = 0; i < V; i++) 
        flag[i] = -1;
    q.push(0);
    flag[0] = 0;
    while(!q.empty() || count < V){
        if(q.empty()){
            q.push(start+1);
        }
        start = q.front();
        res.push_back(start);
        flag[start] = 1;
        q.pop();
        count++;
        for(it = g[start].begin(); it != g[start].end(); it++){
            if(flag[*it] == 0)
                return true;
            else if(flag[*it] == -1){
                q.push(*it);
                flag[*it] = 0;
            }
        }
    }
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
            adj[v].push_back(u);
        }

        cout<<isCyclic(adj, V)<<endl;
    }
    return 0;
}

