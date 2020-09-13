// Rotten Oranges

// Question:
// Given a matrix of dimension r*c where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
// 0 : Empty cell 
// 1 : Cells have fresh oranges 
// 2 : Cells have rotten oranges

// So, we have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can 
// rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. If 
// it is impossible to rot every orange then simply return -1.

// Input:
// The first line of input contains an integer T denoting the number of test cases. Each test case contains two 
// integers r and c, where r is the number of rows and c is the number of columns in the array a[]. Next line 
// contains space separated r*c elements each in the array a[].

// Output:
// Print an integer which denotes the minimum time taken to rot all the oranges (-1 if it is impossible).

// Example:
// Input:
// 2
// 3 5
// 2 1 0 2 1 1 0 1 2 1 1 0 0 2 1 
// 3 5
// 2 1 0 2 1 0 0 1 2 1 1 0 0 2 1

// Output:
// 2
// -1

#include <iostream>
#include <queue>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int r,c,count=0,count0=0,count2=0,old2,new2;
	    cin>>r>>c;
	    int A[r][c];
        queue<int> q1;
        queue<int> q2;
	    for(int i=0;i<r;i++)
            for(int j=0;j<c;j++){
	            cin>>A[i][j];
                if(A[i][j] == 2){
                    count2++;
                    q1.push(i);
                    q2.push(j);
                }
                else if(A[i][j] == 0)
                    count0++;
            }
        old2 = count2;
        new2 = 0;
        while(old2--){
            int x,y;
            x = q1.front();
            y = q2.front();
            q1.pop();
            q2.pop();
            if(x > 0 && A[x-1][y] == 1){
                q1.push(x-1);
                q2.push(y);
                A[x-1][y] = 2;
                new2++;
                count2++;
            }
            if(x < r-1 && A[x+1][y] == 1){
                q1.push(x+1);
                q2.push(y);
                A[x+1][y] = 2;
                new2++;
                count2++;
            }
            if(y > 0 && A[x][y-1] == 1){
                q1.push(x);
                q2.push(y-1);
                A[x][y-1] = 2;
                new2++;
                count2++;
            }
            if(y < c-1 && A[x][y+1] == 1){
                q1.push(x);
                q2.push(y+1);
                A[x][y+1] = 2;
                new2++;
                count2++;
            }
            if(old2 == 0 && new2 != 0){
                old2 = new2;
                new2 = 0;
                count++;
            }
        }
        if(count0 + count2 == r*c)
            cout<<count<<"\n";
        else
            cout<<-1<<"\n";
	}
	return 0;
}