// Find the number of islands

//Question:
// Given a Matrix consisting of 0s and 1s. Find the number of islands of connected 1s present in the matrix. 
// Note: A 1 is said to be connected if it has another 1 around it (either of the 8 directions).

// Input:
// The first line of input will be the number of testcases T, then T test cases follow. The first line of each
//  testcase contains two space separated integers N and M. Then in the next line are the NxM inputs of the 
//  matrix A separated by space .

// Output:
// For each testcase in a new line, print the number of islands present.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findIslands() which 
// takes the matrix A and its dimensions N and M as inputs and returns the number of islands of connected 1s 
// present in the matrix. A 1 is said to be connected if it has another 1 around it (either of the 8 directions).

// Example(To be used only for expected output) :
// Input
// 2
// 3 3
// 1 1 0 0 0 1 1 0 1
// 4 4
// 1 1 0 0 0 0 1 0 0 0 0 1 0 1 0 0

// Output
// 2
// 2

// Solution:
// findIslands(vector<int> A[],N,M): Create a stack to store (i,j) values and create a map to store (i,j) values of visited nodes.
//     Create a matrix vis(-1 for unvisited, 0 for stack, 1 for visited) and initialize count1 to number of 1's in A. 
//     posi and posj contains i,j values of first occurence of 1. push (posi,posj) to stack and make vis[posi][posj] = 0.
//     while(stack is not empty or count < count1):
//         if(stack is empty): increment island, tempi = mp.begin()->first.first, tempj = mp.begin()->first.second
//             push (tempi,tempj) to stack and make vis[tempi][tempj] = 0.
//         vali = s.top().first , valj = s.top().second, pop from stack, increment count, erase mp(vali,valj) and vis[vali][valj] = 1.
//         if(left of A[vali][valj] is 1 and its vis value is -1) then push left element to stack and make its vis value 0.
//         do similarly for right,top,bottom,left-top,left-bottom,right-top,right-bottom.
//     return island+1


#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int findIslands(vector<int> A[], int N, int M) {
    stack<pair<int,int> > s;
    map<pair<int, int> , int> mp;
    int count1=0,count=0,flag=0,island=0,posi,posj;
    int vis[N][M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            vis[i][j] = -1;
            if(A[i][j] == 1){
                count1++;
                mp.insert(make_pair(make_pair(i,j), 1));
                if(flag == 0){
                    posi = i;
                    posj = j;
                }
            }
        }
    }
    s.push(make_pair(posi,posj));
    vis[posi][posj] = 0;
    while(!s.empty() || count < count1){
        if(s.empty()){
            island++;
            int tempi = mp.begin()->first.first;
            int tempj = mp.begin()->first.second;
            s.push(make_pair(tempi,tempj));
            vis[tempi][tempj] = 0;
        }
        int vali = s.top().first;
        int valj = s.top().second;
        s.pop();
        count++;
        mp.erase(make_pair(vali,valj));
        vis[vali][valj] = 1;
        if((valj-1) >= 0 && A[vali][valj-1]==1 && vis[vali][valj-1]==-1){    // Left
            s.push(make_pair(vali,valj-1));
            vis[vali][valj-1] = 0;
        }
        if((valj+1) < M && A[vali][valj+1]==1 && vis[vali][valj+1]==-1){   // Right
            s.push(make_pair(vali,valj+1));
            vis[vali][valj+1] = 0;
        }
        if((vali-1) >= 0 && A[vali-1][valj]==1 && vis[vali-1][valj]==-1){    // Top
            s.push(make_pair(vali-1,valj));
            vis[vali-1][valj] = 0;
        }
        if((vali+1) < N && A[vali+1][valj]==1 && vis[vali+1][valj]==-1){    // Bottom
            s.push(make_pair(vali+1,valj));
            vis[vali+1][valj] = 0;
        }
        if((vali-1) >= 0 && (valj-1) >= 0 && A[vali-1][valj-1]==1 && vis[vali-1][valj-1]==-1){    // Top-Left
            s.push(make_pair(vali-1,valj-1));
            vis[vali-1][valj-1] = 0;
        }
        if((vali+1) < N && (valj-1) >= 0 && A[vali+1][valj-1]==1 && vis[vali+1][valj-1]==-1){   // Bottom-Left
            s.push(make_pair(vali+1,valj-1));
            vis[vali+1][valj-1] = 0;
        }
        if((vali-1) >= 0 && (valj+1) < M  && A[vali-1][valj+1]==1 && vis[vali-1][valj+1]==-1){    // Top-Right
            s.push(make_pair(vali-1,valj+1));
            vis[vali-1][valj+1] = 0;
        }
        if((vali+1) < N && (valj+1) < M  && A[vali+1][valj+1]==1 && vis[vali+1][valj+1]==-1){    // Bottom-Right
            s.push(make_pair(vali+1,valj+1));
            vis[vali+1][valj+1] = 0;
        }
    }
    return island+1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,M;
        cin>>N>>M;
        vector<int> A[N];
        for(int i=0;i<N;i++){
            vector<int> temp(M);
            A[i] = temp;
            for(int j=0;j<M;j++){
                cin>>A[i][j];
            }
        }
        cout<<findIslands(A, N, M)<<endl;    
    }
    return 0;
}

