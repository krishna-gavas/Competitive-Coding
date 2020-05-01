// Coronavirus Spread

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,min,max;
        cin>>N;
        int X[N];
        for(int i=0;i<N;i++)
            cin>>X[i];

        min = N;
        max = 0;
        int count = 1;
        for(int i=1;i<N;i++){
            if(X[i] - X[i-1] <= 2){
                count++;
            }
            else{
                if(count < min)
                    min = count;
                if(count > max)
                    max = count;
                count = 1;
            }
        }
        if(count < min)
            min = count;
        if(count > max)
            max = count;
        cout<<min<<" "<<max<<"\n";
        
	}
	return 0;
}