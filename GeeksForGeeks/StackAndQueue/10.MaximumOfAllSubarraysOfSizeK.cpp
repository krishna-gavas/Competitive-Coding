// Maximum of all subarrays of size k

#include <iostream>
#include <deque>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,K,max=0,j=0;
        cin>>N>>K;
        int A[N],B[N-K+1];
        deque <int> dq;
        deque <int> pos;
        for(int i=0;i<N;i++){
            cin>>A[i];
            if(A[i] > max){
                dq.clear();
                pos.clear();
                dq.push_back(A[i]);
                pos.push_back(i);
            }
            else{
                while(dq.back() < A[i]){
                    dq.pop_back();
                    pos.pop_back();
                }
                dq.push_back(A[i]);
                pos.push_back(i);
                if(pos.front() <= i-K){
                    dq.pop_front();
                    pos.pop_front();
                }
            }
            max = dq.front();
            cout<<max<<endl;
            if(i >= K-1)
                B[j++] = max;
        }

        for(int i=0;i<N-K+1;i++)
            cout<<B[i]<<" ";
        cout<<"\n";
	}
	return 0;
}