// Number of pairs

// Question:
// Given two arrays X[] and Y[] of size M and N respectively. Find number of pairs such that xy > yx where x is an 
// element from X[] and y is an element from Y[].

// Input:
// M = 3, N = 2
// X[] = {2, 1, 6}, Y = {1, 5}
// Output: 3

// Solution:
// Create a frequency array which stores count from 0 to 4 , sort array Y and initialize count to 0.
// for(i=0 to M): count = count + Solve(X[i],Y,freq,M,N)
// print count.

// Solve(val,Y,freq,M,N): if(val is 0) return 0 and if(val is 1) return freq[0].
// 	pos = upper_bound(Y, Y+N, val) - Y.
// 	res = res + N - pos and res = res + freq[0] + freq[1].
// 	if(val is 2) then res = res - (freq[3] + freq[4])
// 	if(val is 3) then res = res + freq[2]
// 	return res.

#include <iostream>
#include <algorithm>
using namespace std;

long long Solve(int val,int Y[],int freq[],int M,int N){
    long long int pos=0,res=0;
    if(val == 0)
        return 0;
    if(val == 1)
        return freq[0];
        
    pos = upper_bound(Y,Y+N,val) - Y;
    
    res = res + (N - pos) + freq[0] + freq[1];
    
    if(val == 2)
        res = res - (freq[3] + freq[4]);
    if(val == 3)
        res = res + freq[2];
        
    return res;
}


long long countPairs(int X[], int Y[], int M, int N)
{
   int freq[5] = {0};
   long long int count = 0;
   for(int i=0;i<N;i++){
       if(Y[i] < 5)
        freq[Y[i]]++;
   }
   sort(Y,Y+N);
   
   for(int i=0;i<M;i++){
       count = count + Solve(X[i],Y,freq,M,N);
   }
   return count;
}



// { Driver Code Starts.
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		cout<<countPairs(a, b, M, N)<<endl;
	}
}  // } Driver Code Ends