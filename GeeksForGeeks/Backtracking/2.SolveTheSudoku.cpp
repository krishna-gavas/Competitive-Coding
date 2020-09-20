// Solve the Sudoku 

// Question:
// Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (mat[][]). The task to print a 
// solved Sudoku. For simplicity you may assume that there will be only one unique solution.

// Solution:
// solveSudoku(): initialize row and col to -1 and isEmpty to true
//     for every cell check whether board[i][j] == 0 if so then row=i,col=j,isEmpty=false and break out of the loop 
//     if(board is completed) return true 
//     for(num=1 to 9):
//         if(isSafe(board,row,col,num)) board[row][col] = num
//             if(solveSudoku(board)) then return true else board[row][col] = 0 and backtrack
//     return false 

// isSafe():
//     check for all rows r if(board[r][col] == num) if so then return false
//     check for all columns c if(board[row][c] == num) if so then return false
//     calculate roeStart and columnStart 
//     for every cell check whether board[i][j] == num if so then return false 
//     finally return true


#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int board[9][9], int row, int col, int num){
    // row
    for(int r=0;r<9;r++){
        if(board[r][col] == num)
            return false;
    }
    //column
    for(int c=0;c<9;c++){
        if(board[row][c] == num)
            return false;
    }
    int rowStart = row - (row % 3);
    int colStart = col - (col % 3);

    for(int i=rowStart;i<rowStart+3;i++){
        for(int j=colStart;j<colStart+3;j++){
            if(board[i][j] == num)
                return false;
        }
    }

    return true;
}

bool solveSudoku(int board[9][9]){
    int row=-1,col=-1;
    bool isEmpty = true;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j] == 0){
                isEmpty = false;
                row = i;
                col = j;
                break;
            }
        }
        if(!isEmpty)
            break;
    }
    if(isEmpty)
        return true;
    
    for(int num=1;num<=9;num++){
        if(isSafe(board,row,col,num)){
            board[row][col] = num;
            if(solveSudoku(board))
                return true;
            else
                board[row][col] = 0;
        }
    }
    return false;
}

void printSudoku(int board[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j];
        }
        cout<<"\n";
    }
}

int main() {
	int T;
	cin>>T;
	while(T--){
        int board[9][9];
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                cin>>board[i][j];
        bool res = solveSudoku(board);
        if(res){
            printSudoku(board);
        }
        else 
            cout<<-1<<"\n";
	}
	return 0;
}