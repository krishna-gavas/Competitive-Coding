// Binary Search

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
            else if(A[mid] < K)
                left = mid+1;
            else if(A[mid] > K)
                right = mid-1;
        }
        if(flag==0)
            cout<<-1<<endl;
    }
    return 0;
}
