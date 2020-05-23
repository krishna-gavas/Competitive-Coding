// Count the Triplets (using index array approach)

// Initialize count and flag to 0.
// make an index array to store elements as index values as index[arr[i]] = 1.
// for(i=0 to N-1):
// 	for(j=i+1 to N):
// 		if((index[arr[i]+arr[j]])==1): increment count and make flag = 1.
// if(flag == 1) then print count else print -1.

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int N,count=0,flag=0;
	    cin>>N;
	    long int arr[N];
		int* index = (int*)calloc(1000000, sizeof(int));
	    for(long int i=0;i<N;i++){
	        cin>>arr[i];
			index[arr[i]] = 1;
		}
		for(long int i=0;i<N-1;i++){
			for(long int j=i+1;j<N;j++){
				if((index[arr[i]+arr[j]])==1){
					count = count + 1;
					flag = 1;
				}
			}
		}
		if(flag==1)
			cout<<count<<endl;
		else
			cout<<-1<<endl;
		free(index);
	}
	return 0;
}