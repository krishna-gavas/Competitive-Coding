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
// Initialize buy,sell and flag to 0 and initialize cur = arr[0]
// for(i=1 to N):
//     cur = arr[i]
//     if(arr[i] > cur) then increment sell and make flag = 1
//     else if(buy == sell) then make buy = sell = i
//     else then print (buy,sell) and make buy = sell = i

#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int> > stockBuySell(vector<int> A, int N){
        int buy=0,sell=0,flag=0;
        vector<vector<int> > ans;
        for(int i=1;i<N;i++){
            if(A[i] >= A[i-1] && A[i] != A[buy]){
                sell++;
                flag = 1;
            }
            else if(buy == sell){
                buy = i;
                sell = i;
            }
            else{
                vector<int> vec;
                vec.push_back(buy);
                vec.push_back(sell);
                ans.push_back(vec);

                buy = i;
                sell = i;
            }
        }
        if(flag == 0)
            return ans;
        else if(buy != N-1 && sell == N-1){
            vector<int> temp;
            temp.push_back(buy);
            temp.push_back(sell);
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            for (int i=0; i<ans.size(); ++i){
                cout<<"("<<ans[i][0]<<" "<<ans[i][1]<<") ";
            }
        }cout<<endl;
    }
    return 0;
}