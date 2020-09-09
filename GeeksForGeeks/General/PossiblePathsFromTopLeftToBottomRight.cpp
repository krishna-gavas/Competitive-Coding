// Count all possible paths from top left to bottom right

// Question
// The task is to count all the possible paths from top left to bottom right of a mXn matrix with the constraints 
// that from each cell you can either move only to right or down.

// Input: 
// First line consists of T test cases. First line of every test case consists of N and M, denoting the number of 
// rows and number of column respectively.

// Output: 
// Single line output i.e count of all the possible paths from top left to bottom right of a mXn matrix. Since 
// output can be very large number use %10^9+7.

// Example:
// Input:
// 1
// 3 3
// Output:
// 6

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,M;
	    cin>>N>>M;
        long int DP[N][M];
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(i==0 || j==0)
                    DP[i][j] = 1;
                else{
                    DP[i][j] = DP[i-1][j] + DP[i][j-1];
                    DP[i][j] = DP[i][j] % 1000000007;
                }    
            }
        }

		cout<<DP[N-1][M-1] % 1000000007<<endl;
		
	}
	return 0;
}