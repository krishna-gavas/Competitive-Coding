// Alien Dictionary

// Question:
// Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. 
// Find the order of characters in the alien language.
// Note: Many orders may be possible for a particular test case, thus you may return any valid order.

// Input:
// The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test 
// case contains an integer N and k denoting the size of the dictionary. Then in the next line are sorted space 
// separated values of the alien dictionary.

// Output:
// For each test case in a new line output will be 1 if the order of string returned by the function is correct 
// else 0 denoting incorrect string returned.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findOrder() which takes 
// the string array dict[], its size N and the integer K as inputs and returns a string denoting the order of 
// characters in the alien language.

// Example:
// Input:
// 2
// 5 4
// baa abcd abca cab cad
// 3 3
// caa aaa aab

// Output:
// 1
// 1

// Solution:
// findOrder(str[], N, K): Create a adjacency list and a visited array.
//     Build Graph:
//     for(i=0 to N):
//         for(j=0 to str[i].length): vis[str[i][j]-'a'] = 0.
//         if(i > 0): w1 = str[i-1], w2 = str[i] and len = min(length of w1, length of w2).
//             for(j=0 to len): c1 = w1[j], c2 = w2[j]
//                 if(c1 != c2) then adj[c1-'a'].push_back(c2-'a') and break out of the loop.
    
//     Topological Sort:
//     create an array to store indegree of all nodes and initialize count to 0.
//     Create a queue and push all the nodes to it whose inDegree is 0.
//     while(q is not empty): pop the front of q and append it to string res.
//         for(it = g[start].begin() to g[start].end()): increment indegree[*it] and if(indegree[*it] == 0) then push *it to q.
//         increment count.
//     return res.


#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string order;

string findOrder(string str[], int N, int K) {
    vector<int> adj[K];
    int vis[K];
    for(int i=0;i<K;i++){
        vis[i] = -1;
    }

    // Build Graph
    for(int i=0;i<N;i++){
        for(int j=0;j<str[i].length();j++)
            vis[str[i][j]-'a'] = 0;

        if(i > 0){
            string w1 = str[i-1], w2 = str[i];
            int len = min(w1.length(), w2.length());
            for(int j=0;j<len;j++){
                char c1 = w1[j], c2 = w2[j];
                if(c1 != c2){
                    adj[c1-'a'].push_back(c2-'a');
                    break;
                }
            }
        }
    }
    
    // Topological Sort
    string res;
    vector<int> :: iterator it;
    queue<int> q;
    int indegree[K],count=0,start,k=0;
    for (int i = 0; i < K; i++)
        indegree[i] = 0;
    for (int i = 0; i < K; i++)
        for(it = adj[i].begin(); it != adj[i].end(); it++)
            indegree[*it]++;

    for (int i = 0; i < K; i++)
        if(indegree[i] == 0)
            q.push(i);
    
    while(!q.empty()){
        start = q.front();
        q.pop();
        res = res + char(start + 'a');
        for(it = adj[start].begin(); it != adj[start].end(); it++){
            indegree[*it]--;
            if(indegree[*it] == 0)
                q.push(*it);
        }
        count++;
    }
    return res;
    
    cout<<res<<endl;
    return res;
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

bool f(string a, string b){
    int p1=0,p2=0;
    for(int i=0;i < min(a.size(), b.size()) && p1 == p2;i++){
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
    }
    if(p1 == p2 && a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N>>K;
        string str[N];
        for(int i=0;i<N;i++)
            cin>>str[i];
        string ss = findOrder(str, N, K);
        order = "";

        for(int i=0;i<ss.size();i++)
            order = order + ss[i];

        string temp[N];
        copy(str,str+N,temp);
        sort(temp, temp+N, f);

        bool f = true;
        for(int i=0;i<N;i++)
            if(str[i] != temp[i])
                f = false;

        cout<<f<<endl;

    }
    return 0;
}