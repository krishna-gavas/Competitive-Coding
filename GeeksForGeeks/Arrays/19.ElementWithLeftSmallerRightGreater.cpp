// Element with left side smaller and right side greater

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,ele = 0,max,min;
	    cin>>N;
	    int A[N],B[N];

	    for(int i=0;i<N;i++){
	        cin>>A[i];
            B[i] = A[i];
        }
        max = A[0];
        sort(B,B+N);

        for(int i=0;i<N;i++){
            if(A[i] > max)
                max = A[i];
            if(A[i] == B[i] && A[i] >= max && i!=0 && i!=(N-1)){
                min = A[i];
                for(int j=N-1;j>i;j--){
                    if(A[j] < min)
                        min = A[j];
                }
                if(A[i] <= min){
                    ele = A[i];
                    break;
                }
            }
        }
        if(ele == 0)
            cout<<-1<<endl;
        else 
            cout<<ele<<endl;

	}
	return 0;
}