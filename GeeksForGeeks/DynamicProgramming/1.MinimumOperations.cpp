// Minimum Operations

// Initialize count as 0
// while(N > 0): 
//     if(N is 1) then increment count and break from the loop
//     if(N is odd) then increment count
//     divide N by 2 and increment count

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,count=0;
        cin>>N;
        while(N > 0){
            if(N == 1){
                count++;
                break;
            }
            if(N%2 == 1)
                count++;
            N = N/2;
            count++;
        }
        cout<<count<<"\n";
	}
	return 0;
}