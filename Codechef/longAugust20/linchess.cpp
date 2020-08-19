// Chef and Linear Chess 

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,min=INT_MAX,out;
		long int K;
        cin>>N>>K;
        long int P[N];
        for(int i=0;i<N;i++){
            cin>>P[i];
			if(P[i] < K && (K % P[i]) == 0){
				int temp = K / P[i];
				if(temp < min){
					min = temp;
					out = P[i];
				}
			}
        }
		if(min == INT_MAX)
			cout<<-1<<"\n";
		else 
			cout<<out<<"\n";
	}
	return 0;
}