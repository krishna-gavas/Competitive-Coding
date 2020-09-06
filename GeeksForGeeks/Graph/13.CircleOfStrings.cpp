// Circle of strings

// Question:
// Given an array of strings A[], determine if the strings can be chained together to form a circle. A
// string X can be chained together with another string Y if the last character of X is same as first
// character of Y. If every string of the array can be chained, it will form a circle.

// For eg for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings can be 
// chained as "for", "rig", "geek" and "kaf"

// Input
// The first line of input contains an integer T denoting the number of test cases. Then T test cases
// follow. 
// The first line of each test case contains a positive integer N, denoting the size of the array.
// The second line of each test case contains a N space seprated strings, denoting the elements of the
// array A[].

// Output
// If chain can be formed, then print 1, else print 0.

// Examples
// Input
// 2
// 3
// abc bcd cdf
// 4
// ab bc cd da

// Output
// 0
// 1

// Solution:
// Create an adjacency list to store first and last character of the string and create 2 vectors to store indegree and outdegree.
// if(in==out && Kosaraju(adj,in)==1) print 1 else print 0.
// 
// kosaraju(N, in): initialize N=26, Create an empty stack and 2 vectors vis1,vis2 and initialize them with false.
//     Do a DFS on the original graph, keeping track of the finish times of each vertex. This can be done with a stack.
//     Reverse the original graph g and store it in tg.
//     Do DFS on the reversed graph, with the vertex on top of the stack and keep marking the vertices visited, 
//     When DFS finishes, all vertices visited will form one Strongly Connected Component hence increment count.

// myDFS(g,N,i,vis): make vis[i] = true. 
//     for(it = g[i].begin() to g[i].end()): if(vis[*it] is false) then call myDFS(g,N,*it,vis).
//     push i to stack.

// revDFS(tg,N,i,vis): make vis[i] = true.
//     for(it = tg[i].begin() to tg[i].end()): if(vis[*it] is false) then call revDFS(tg,N,*it,vis).

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

stack <int> st;

void myDFS(vector<int> g[], int N, int i,bool vis[]){
    vis[i] = true;
    vector<int> :: iterator it;
    for(it = g[i].begin(); it != g[i].end(); it++){
        if(!vis[*it]){
            myDFS(g,N,*it,vis);
        }
    }
    st.push(i);
}

void revDFS(vector<int> tg[], int N, int i,bool vis[]){
    vis[i] = true;
    vector<int> :: iterator it;
    for(it = tg[i].begin(); it != tg[i].end(); it++){
        if(!vis[*it]){
            revDFS(tg,N,*it,vis);
        }
    }
}

int Kosaraju(vector<int> g[],vector<int>&in){
    int N = 26;
    stack <int> newst;
    st = newst;
    bool *vis1 = new bool[N];
    bool *vis2 = new bool[N];
    for (int i = 0; i < N; i++){
        vis1[i] = false;
        vis2[i] = false;
    }
    for(int i=0;i<N;i++){
        if(in[i])
            myDFS(g,N,i,vis1);

    }

    vector<int> tg[N];
    vector<int> :: iterator it;
    int count=0;
    // Reverse the graph g and store it in tg
    for(int i=0;i<N;i++){
        for(it = g[i].begin(); it != g[i].end(); it++){
            tg[*it].push_back(i);
        }
    }
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis2[node]){
            count++;
            revDFS(tg,N,node,vis2);
        }
    }
    return count;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<int> adj[26];
        vector<int>in(26,0),out(26,0);
        string str;
        for(int i=0;i<N;i++){
            cin>>str;
            int len = str.length();
            adj[str[0]-'a'].push_back(str[len-1]-'a');
            out[str[0]-'a']++;
            in[str[len-1]-'a']++;
        }
        if(in==out && Kosaraju(adj,in)==1)
            cout<<"1\n";
        else
            cout<<"0\n";
    }
    return 0;
}