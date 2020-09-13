// Detect cycle in an directed graph(using Topological sort)

// Question:
// Given a Directed Graph. Check whether it contains any cycle or not.

// Input: The first line of the input contains an integer 'T' denoting the number of test cases. 
// Then 'T' test cases follow. Each test case consists of two lines. Description of testcases is as follows: 
// The First line of each test case contains two integers 'N' and 'M'  which denotes the no of vertices and 
// no of edges respectively. The Second line of each test case contains 'M'  space separated pairs u and v 
// denoting that there is an uni-directed  edge from u to v .

// Output:
// The method should return 1 if there is a cycle else it should return 0.

// User task:
// You don't need to read input or print anything. Your task is to complete the function isCyclic which takes 
// the Graph and the number of vertices and inputs and returns true if the given directed graph contains a cycle. 
// Else, it returns false.

// Example:
// Input:
// 3
// 2 2
// 0 1 0 0
// 4 3
// 0 1 1 2 2 3
// 4 3
// 0 1 2 3 3 2
// Output:
// 1
// 0
// 1

// Solution:
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
        vector<int> g[V];

        for(int i=0;i<E;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
        }

        cout<<isCyclic(V, g)<<endl;
    }
    return 0;
}

