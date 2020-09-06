// Squares in N*N Chessboard

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,squares;
	    cin>>N;
        squares = (N * (N+1) * (2*N + 1))/6;
		cout<<squares<<"\n";
	}
	return 0;
}