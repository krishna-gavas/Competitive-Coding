// Stock buy and sell

// Question:
// The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the 
// stock so that in between those days your profit is maximum.

// Input: 
// First line contains number of test cases T. First line of each test case contains an integer value N denoting the 
// number of days, followed by an array of stock prices of N days. 

// Output:
// For each testcase, output all the days with profit in a single line. And if there is no profit then print 
// "No Profit".

// Example
// Input:
// 3
// 7
// 100 180 260 310 40 535 695
// 4
// 100 50 30 20
// 10
// 23 13 25 29 33 19 34 45 65 67

// Output:
// (0 3) (4 6)
// No Profit
// (1 4) (5 9)

// Solution:
// Initialize start,end and flag to 0 and initialize cur = arr[0]
// for(i=1 to N):
//     cur = arr[i]
//     if(arr[i] > cur) then increment end and make flag = 1
//     else if(start == end) then make start = end = i
//     else then print (start,end) and make start = end = i

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,start=0,end=0,cur,flag=0;
	    cin>>N;
	    int arr[N];

	    for(int i=0;i<N;i++)
	        cin>>arr[i];
        cur = arr[0];
        for(int i=1;i<N;i++){
            cur = arr[i];
            if(arr[i] > cur){
                end++;
                flag = 1;
            }
            else if(start == end){
                start = i;
                end = i;
            }
            else{
                cout<<"("<<start<<" "<<end<<") ";
                start = i;
                end = i;
            }
        }

        if(flag == 0)
            cout<<"No Profit";
        else if(start != N-1 && end == N-1)
            cout<<"("<<start<<" "<<end<<") ";
        cout<<endl;

	}
	return 0;
}