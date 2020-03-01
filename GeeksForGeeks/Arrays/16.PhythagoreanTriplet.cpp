// Pythagorean Triplet(using meet in the middle algorithm)

#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,flag=0;
	    cin>>N;
	    int arr[N],sq[N];
        unordered_set <int> B ; 

	    for(int i=0;i<N;i++){
	        cin>>arr[i];
            sq[i] = arr[i] * arr[i];
            B.insert(sq[i]);
        }    
        sort(sq,sq+N);

        for(int i=(N-1);i>0;i--){
            int a = sq[i];
            for(int j=1;j<i;j++){
                if((B.find(sq[j]) != B.end()) && (B.find((a-sq[j])) != B.end())){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }
        if(flag == 0)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;

	}
	return 0;
}