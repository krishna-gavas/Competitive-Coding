// Leaders in an array

// Question:
// Given an array of positive integers. Your task is to find the leaders in the array.
// Note: An element of array is leader if it is greater than or equal to all the elements to its right side. Also, 
// the rightmost element is always a leader. 

// Input:
// The first line of input contains an integer T denoting the number of test cases. The description of T test cases 
// follows.
// The first line of each test case contains a single integer N denoting the size of array.
// The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

// Output:
// Print all the leaders.

// Example:
// Input:
// 3
// 6
// 16 17 4 3 5 2
// 5
// 1 2 3 4 0
// 5
// 7 4 5 7 3
// Output:
// 17 5 2
// 4 0
// 7 7 3

// Solution:
// Leader is an element such that all elements right to it are either smaller or equal
// access element in reverse order and compare it with max
// if it is greater than max then push it to stack
#include <iostream>
#include <stack>
using namespace std;
 
vector<int> leaders(int A[], int N){
    int max = A[N-1];
    stack<int> S;
    vector<int> out;
    
    for(int i=N-1;i>=0;i--){
        if(A[i] >= max){
            S.push(A[i]);
            max = A[i];
        }
    }
    
    while(!S.empty()){
        out.push_back(S.top());
        S.pop();
    }
    return out;
}


int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        
        //calling leaders() function
        vector<int> v = leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}