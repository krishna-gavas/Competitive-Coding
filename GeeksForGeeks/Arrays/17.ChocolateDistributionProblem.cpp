// Chocolate Distribution Problem

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,M,min,dif;
	    cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
        cin>>M;
        sort(arr,arr+N);
        min = arr[N-1];

        for(int i=0;i<=(N-M);i++){
            dif = arr[i+M-1] - arr[i];
            if(dif < min)
                min = dif;
        }

        cout<<min<<endl;

	}
	return 0;
}