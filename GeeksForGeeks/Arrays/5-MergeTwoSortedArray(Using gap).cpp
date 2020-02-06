//Merge Two sorted array without extra space(Using gap approach)
#include <iostream>
using namespace std;

int nextGap(int n){
	if(n<=1)
		return 0;
	return n/2 + n%2;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int X,Y;
	    cin>>X>>Y;
	    long int A[X+Y];

	    for(int i=0;i<X+Y;i++)
	        cin>>A[i];

		int gap = nextGap(X+Y);

		while(gap){
			for(int i=0;i+gap<X+Y;i++){
				if(A[i+gap] < A[i])
					swap(A[i],A[i+gap]);
			}
			gap = nextGap(gap);
		}

		for(int i=0;i<X+Y;i++)
	        cout<<A[i]<<" ";
		
		cout<<endl;
	}
	return 0;
}