// Path in Matrix


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int static N;

int findLongestFromACell(int i, int j, int A[N][N], int DP[N][N]) 
{ 
    if (i < 0 || i >= n || j < 0 || j >= n) 
        return 0; 
  
    if (DP[i][j] != -1) 
        return DP[i][j]; 
  
    // To store the path lengths in all the four directions 
    int x = INT_MIN, y = INT_MIN, z = INT_MIN, w = INT_MIN; 
  
    // Since all numbers are unique and in range from 1 to n*n, 
    // there is atmost one possible direction from any cell 
    if (j < n - 1 && ((A[i][j] + 1) == A[i][j + 1])) 
        x = 1 + findLongestFromACell(i, j + 1, A, DP); 
  
    if (j > 0 && (A[i][j] + 1 == A[i][j - 1])) 
        y = 1 + findLongestFromACell(i, j - 1, A, DP); 
  
    if (i > 0 && (A[i][j] + 1 == A[i - 1][j])) 
        z = 1 + findLongestFromACell(i - 1, j, A, DP); 
  
    if (i < n - 1 && (A[i][j] + 1 == A[i + 1][j])) 
        w = 1 + findLongestFromACell(i + 1, j, A, DP); 

    return DP[i][j] = max(x, max(y, max(z, max(w, 1)))); 
}

int PathInMatrix(int A[N][N], int N){
    int sum = 0;
    int DP[N][N];
    memset(DP,-1,sizeof(DP));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(DP[i][j] == -1)
                findLongestFromACell(i, j, A, DP);
            sum = max(sum,DP[i][j]);
        }
    }
    return sum;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    N = 0;
        cin>>N;
        int A[N][N]
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                cin>>A[i][j];
        cout<<PathInMatrix(A,N)<<"\n";
	}
	return 0;
}