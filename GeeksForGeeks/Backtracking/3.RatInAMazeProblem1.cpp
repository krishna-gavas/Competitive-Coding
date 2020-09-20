// Rat in a Maze Problem - I

// Question:
// Consider a rat placed at (0, 0) in a square matrix of order N*N. It has to reach the destination at (N-1, N-1). 
// Find all possible paths that the rat can take to reach from source to destination. The directions in which the 
// rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it 
// is blocked and cannot be crossed while value 1 at a cell in the matrix represents that it can be traveled through.

// Input: N = 4, m[][] = {{1, 0, 0, 0},
//                        {1, 1, 0, 1}, 
//                        {1, 1, 0, 0},
//                        {0, 1, 1, 1}}
// Output: DDRDRR DRDDRR

// Your Task:  
// You don't need to read input or print anything. Complete the function printPath() which takes N and 2d array 
// m[][] as input parameters and returns a sorted list of paths.
// Note:  In case of no path, return an empty list. The driver will output -1 automatically.

// Solution:
// printPath(): create a vector of string named res to store the result
//     call the mazeHelp(m,n,res,0,0,"") function and finally return res

// mazeHelp(m,n,res,x,y,str):
//     if(x and y are not valid and m[x][y] is 0 or 2) then return
//     if(x and y both reach at last cell) then push str to res and return
//     make m[x][y] = 2 in order to avoid cycle
//     call mazeHelp(m,n,res,x+1,y,str+'D') for down,left,right and up direction

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX 5

void mazeHelp(int m[MAX][MAX], int n,vector<string> &res,int x, int y,string str){
    if(x<0 || x>=n || y<0 || y>=n || m[x][y]==0 || m[x][y]==2)
        return;
    if(x == n-1 && y == n-1){
        res.push_back(str);
        return;
    }
    m[x][y] = 2;
    mazeHelp(m,n,res,x+1,y,str+'D');
    mazeHelp(m,n,res,x,y-1,str+'L');
    mazeHelp(m,n,res,x,y+1,str+'R');
    mazeHelp(m,n,res,x-1,y,str+'U');
    m[x][y] = 1;
}

vector<string> printPath(int m[MAX][MAX], int n) {
    vector<string> res;
    mazeHelp(m,n,res,0,0,"");
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}

