// Chef and Strings

#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
        int N,skip=0;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++){
            cin>>A[i];
            if(i != 0)
                skip += abs(A[i] - A[i-1]) - 1;
        }
        cout<<skip<<endl;
    }
    return 0;
}