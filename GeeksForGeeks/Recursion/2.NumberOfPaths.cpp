// Number of paths(using DP)


#include <iostream>
using namespace std;

int numberOfPaths(int m, int n){
    if(m==1 || n==1)
        return 1;
    return numberOfPaths(m-1,n) + numberOfPaths(m,n-1);
}

int main() {
    int T;
    cin>>T;
    while(T--){
        int M,N,out;
        cin>>M>>N;
        cout<<numberOfPaths(M,N)<<endl;
    }
    return 0;
}
