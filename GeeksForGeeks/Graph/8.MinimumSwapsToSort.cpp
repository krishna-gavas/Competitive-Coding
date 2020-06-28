// Minimum Swaps to Sort


#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void Swap(int A[],int i ,int t){
	int z=0;
	
    z=A[i];
	A[i]=A[t];
    A[t]=z;
}

int minSwaps(int A[], int N){
    int count = 0,min,begin=0,minIndex;
    for(int i=begin;i<N-1;i++){
        min = A[i];
        minIndex = i;
        for(int j=i+1;j<N;j++){
            if(A[j] < min){
                min = A[j];
                minIndex = j;
            }
        }
        if(i != minIndex){
            Swap(A,i,minIndex);
            count++;
        }
    }
    return count;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        cout<<minSwaps(A,N)<<endl;
    }
}