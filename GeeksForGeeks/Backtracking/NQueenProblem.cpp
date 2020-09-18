// N-Queen Problem

// Solution:
//  NQueen(board,i,n,res):
//     if(i == n) then push the positions of queen for all n columns into result vector
//         return false inorder to check all possible configurations
//     for(j=0 to n)
//         if board[i][j] is safe then place the queen at board[i][j]
//             check if queen can be placed for next row if yes then return true else remove queen from i,j and backtrack
//     return false

// isSafe(board,i,j,n): check for all rows till i whether board[row][j] = 1 if so return false
//     check for all columns till j whether board[i][column] = 1 if so return false
//     similarly check for left and right diagonal if board[x][y] = 1 then return false
//     finally return true

#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int board[][10], int i, int j, int n){
    // row
    for(int r=0;r<i;r++){
        if(board[r][j] == 1)
            return false;
    }
    //column
    for(int c=0;c<j;c++){
        if(board[i][c] == 1)
            return false;
    }
    int x=i,y=j;
    //left diagonal
    while(x>=0 && y>=0){
        if(board[x][y] == 1)
            return false;
        x--;
        y--;
    }
    x=i;
    y=j;
    // right diagonal
    while(x>=0 && y<n){
        if(board[x][y] == 1)
            return false;
        x--;
        y++;
    }
    return true;
}

bool NQueen(int board[][10], int i, int n,vector<vector<int> > &res){
    if(i == n){
        vector<int> vec;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(board[r][c] == 1){
                    vec.push_back(c+1);
                }
            }
        }
        res.push_back(vec);
        return false;
    }

    for(int j=0;j<n;j++){
        if(isSafe(board,i,j,n)){
            board[i][j] = 1;

            bool nextQueen = NQueen(board,i+1,n,res);
            // check if queen can be placed for next row if yes return true
            if(nextQueen)
                return true;
            // else remove queen from i,j and backtrack
            board[i][j] = 0;
        }
    }
    return false;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;

        int board[10][10] = {0};
        vector<vector<int> > res;
        NQueen(board,0,N,res);
        if(res.size() != 0){
            for(int i=0;i<res.size();i++){
                cout<<"[";
                for(int j=0;j<N;j++){
                    cout<<res[i][j]<<" ";
                }
                cout<<"] ";
            }
        }
        else 
            cout<<-1;
        
        cout<<"\n";
	}
	return 0;
}