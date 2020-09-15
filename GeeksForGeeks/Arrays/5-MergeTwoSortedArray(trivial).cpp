//Merge Two sorted array without extra space(Trivial approach)

// Question:
// Given two sorted arrays Arr1[] and Arr2[] in non-decreasing order with size N and M. The task is to merge the 
// two sorted arrays into one sorted array (in non-decreasing order).
// Note:  DO NOT use extra space. We need to modify existing arrays as following.

// Input:
// N = 4, M = 5
// Arr1[] = {1, 3, 5, 7}
// Arr2[] = {0, 2, 6, 8, 9}
// Output: 0 1 2 3 5 6 7 8 9	

// Your Task:
// Complete the function merge() which takes two arrays arr1, arr2 and two integer n, m, as input parameters and 
// returns void. You don't to print answer or take inputs.

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int X,Y;
	    cin>>X>>Y;
	    long int P[X],Q[Y];

	    for(long int i=0;i<X;i++)
	        cin>>P[i];

		for(long int j=0;j<Y;j++)
	        cin>>Q[j];
		
		for(long int i=0;i<X;i++){
			for(long int j=0;j<Y;j++){
				if((P[i] > Q[j]) && (j != Y-1))
					continue;
				else if((P[i] > Q[j]) && (j == Y-1)){
					int temp = P[i];
					P[i] = Q[0];
					for(int k=0;k<Y-1;k++)
						Q[k] = Q[k+1];
					Q[Y-1] = temp;
					j = Y;
				}
				else if(P[i] < Q[0])
					j = Y;
				else{
					int temp = P[i];
					P[i] = Q[0];
					for(int k=0;k<j-1;k++)
						Q[k] = Q[k+1];
					Q[j-1] = temp;
					j = Y;
				}
			}
		}

		for(long int i=0;i<X;i++)
	        cout<<P[i]<<" ";

		for(long int i=0;i<Y;i++)
	        cout<<Q[i]<<" ";
		
		cout<<endl;
	}
	return 0;
}