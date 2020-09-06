// Search in a Rotated Array

// Question:
// Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element K. 
// The task is to find the index of the given element K in the array A.

// Input:
// The first line of the input contains an integer T, denoting the total number of test cases. Then T test cases follow. 
// Each test case consists of three lines. First line of each test case contains an integer N denoting the size of 
// the given array. Second line of each test case contains N space separated integers denoting the elements of the 
// array A. Third line of each test case contains an integer K denoting the element to be searched in the array.

// Output:
// Corresponding to each test case, output the index of the element found in the array.  If element is not present, 
// then output -1.

// Example:
// Input:
// 3
// 9
// 5 6 7 8 9 10 1 2 3
// 10
// 3
// 3 1 2
// 1
// 4
// 3 5 1 2
// 6

// Output:
// 5
// 1
// -1

// Solution:
// Initialize left=0 and right = N-1.
// while(left <= right):  mid = (left + right)/2 and if(A[mid] == K) then print mid.
//     else if(A[left..mid] is sorted)
//         if(K lies between A[left..mid]) then right = mid-1 else left = mid+1.
//     else (i.e A[mid+1..right] is sorted)
//         if(K lies between A[mid+1..right]) then left = mid+1 else right = mid-1.

#include <iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,K,left,right,mid,flag=0;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        cin>>K;
        left = 0;
        right = N-1;
        while(left <= right){
            mid = (left + right)/2;
            if(A[mid] == K){
                flag = 1;
                cout<<mid<<endl;
                break;
            }
            else if(A[left] <= A[mid]){  
                if(K >= A[left] && K <= A[mid])
                    right = mid-1;
                else
                    left = mid+1;
            }
            else{
                if(K >= A[mid] && K <= A[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        if(flag==0)
            cout<<-1<<endl;
    }
    return 0;
}
