// Detect cycle in an undirected graph

// Question:
// Given a Undirected Graph. Check whether it contains a cycle or not. 

// Input:
// The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' testcases 
// follow. Each testcase consists of two lines. Description of testcases are as follows: The First line of each 
// testcase contains two integers 'N' and 'M' which denotes the no of vertices and no of edges respectively. 
// The Second line of each test case contains 'M'  space separated pairs u and v denoting that there is a 
// bidirectional  edge from u to v .

// Output:
// The method should return 1 if there is a cycle else it should return 0.

// User task:
// You don't need to read input or print anything. Your task is to complete the function isCyclic which takes 
// the Graph and the number of vertices as inputs and returns true if the given undirected graph contains any 
// cycle. Else, it returns false.

// Example:
// Input:
// 3
// 2 1
// 0 1
// 4 3
// 0 1 1 2 2 3
// 5 4
// 0 1 2 3 3 4 4 2

// Output:
// 0
// 0
// 1

// Solution:
// isCyclic(g, V): Create a result vector to store bfs traversal, Create a queue and push first element to it.
//     create a flag array(-1 means not in queue, 0 means in queue and 1 means visited) of size V and initialize it to -1.
//     initialize flag[first element] = 0;
//     while(queue is not empty or all Nodes are not yet visited): pop front of q and store it to start, push start to result vector and make flag[start] = 1.
//         for(it = g[start].begin() to g[start].end()): if(flag[*it] == 0) return true
//             else if(flag[*it] == -1) then push *it to q and make flag[*it] = 0.
//     return false;

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
        vector<int> g[V];

        for(int i=0;i<E;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        cout<<isCyclic(g, V)<<endl;
    }
    return 0;
}

