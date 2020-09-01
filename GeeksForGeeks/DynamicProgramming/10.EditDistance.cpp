// Edit Distance

// EditDistance:
//     Create a DP table
//     for(i=0 to m)
//         for(j=0 to n)
//             if(it is first row) then DP[i][j] = j
//             else if(it is first column) then DP[i][j] = i
//             else if(s1[i-1] == s2[j-1]) then DP[i][j] = DP[i-1][j-1]
//             else then DP[i][j] = min(DP[i][j-1],DP[i-1][j],DP[i-1][j-1]) + 1
//     return len

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int EditDistance(string s1, string s2, int m, int n){
    int DP[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0)
                DP[i][j] = j;
            else if(j==0)
                DP[i][j] = i;
            else if(s1[i-1] == s2[j-1])
                DP[i][j] = DP[i-1][j-1];
            else 
                DP[i][j] = min(DP[i-1][j-1], min(DP[i][j-1],DP[i-1][j])) + 1;
        }
    }
    return DP[m][n];
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,M;
        cin>>N>>M;
        string str1,str2;
        cin>>str1>>str2;
        cout<<EditDistance(str1,str2,N,M)<<"\n";
	}
	return 0;
}