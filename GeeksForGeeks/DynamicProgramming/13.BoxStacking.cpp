// Box Stacking


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int maxHeight(int height[],int width[],int length[],int n)
{
    //Your code here
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,sum;
        cin>>N;
        int A[1000],B[1000],C[10001];
        for(int i=0;i<N;i++){
            int a,b,c;
            cin>>a>>b>>c;
            A[i] = a;
            B[i] = b;
            C[i] = c;
        }
        cout<<maxHeight(A,B,C,N)<<"\n";
	}
	return 0;
}