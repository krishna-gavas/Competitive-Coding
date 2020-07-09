// Minimize the sum of product


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--){
        int N;
        long long int sum=0;
        cin>>N;
        int A[N],B[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        for(int i=0;i<N;i++)
            cin>>B[i];
        sort(A,A+N);
        sort(B,B+N);
        for(int i=0,j=N-1;i<N;i++,j--){
            sum = sum + (A[i] * B[j]);
        }
        cout<<sum<<endl;
    }
    return 0;
}
