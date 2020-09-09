// Maximum of all subarrays of size k

// Question:
// Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.

// Input:
// The first line of input contains an integer T denoting the number of test cases. The first line of each test case 
// contains a single integer N denoting the size of array and the size of subarray K. The second line contains N 
// space-separated integers A1, A2, ..., AN denoting the elements of the array.

// Output:
// Print the maximum for every subarray of size k.

// Example:
// Input:
// 2
// 9 3
// 1 2 3 1 4 5 2 3 6
// 10 4
// 8 5 10 7 9 4 15 12 90 13

// Output:
// 3 3 4 5 5 5 6
// 10 10 10 15 15 90 90

#include <iostream>
#include <deque>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,K,max=0,j=0;
        cin>>N>>K;
        int A[N],B[N-K+1];
        deque <int> dq;
        deque <int> pos;
        for(int i=0;i<N;i++){
            cin>>A[i];
            if(A[i] > max){
                dq.clear();
                pos.clear();
                dq.push_back(A[i]);
                pos.push_back(i);
            }
            else{
                while(dq.back() < A[i]){
                    dq.pop_back();
                    pos.pop_back();
                }
                dq.push_back(A[i]);
                pos.push_back(i);
                if(pos.front() <= i-K){
                    dq.pop_front();
                    pos.pop_front();
                }
            }
            max = dq.front();
            cout<<max<<endl;
            if(i >= K-1)
                B[j++] = max;
        }

        for(int i=0;i<N-K+1;i++)
            cout<<B[i]<<" ";
        cout<<"\n";
	}
	return 0;
}