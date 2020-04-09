// Sell All the Cars 

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,max;
	    long int profit = 0;
        cin>>N;
        long int P[N];
        for(int i=0;i<N;i++)
            cin>>P[i];

        sort(P, P+N, greater<int>());

        for(int i=0;i<N;i++){
            max = P[i];
            if(max - i > 0)
                profit = profit + (max - i);
        }
        
        cout<<profit%1000000007<<"\n";
	}
	return 0;
}