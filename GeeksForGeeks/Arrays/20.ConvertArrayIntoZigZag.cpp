// Convert array into Zig-Zag fashion

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int arr[N];

	    for(int i=0;i<N;i++)
	        cin>>arr[i];
       

        for(int i=0;i<N-1;i++){
            if(i%2 == 0){
                if(arr[i] > arr[i+1])
                    swap(arr[i],arr[i+1]);
            }
            else
            {
                if(arr[i] < arr[i+1])
                    swap(arr[i],arr[i+1]);
            }
            
        }

        for(int i=0;i<N;i++)
	        cout<<arr[i]<<" ";
        cout<<endl;
	}
	return 0;
}