// Find the element that appears once in sorted array

#include <iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        long int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        for(int i=0;i<N;i=i+2){
            if(A[i] != A[i+1]){
                cout<<A[i]<<endl;
                break;
            }
        }
    }
    return 0;
}