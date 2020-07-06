// Search in a Rotated Array

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