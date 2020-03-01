// Stock buy and sell

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,start=0,end=0,cur,flag=0;
	    cin>>N;
	    int arr[N];

	    for(int i=0;i<N;i++)
	        cin>>arr[i];
        cur = arr[0];
        for(int i=1;i<N;i++){
            if(arr[i] > cur){
                cur = arr[i];
                end++;
                flag = 1;
            }
            else if(start == end){
                cur = arr[i];
                start = i;
                end = i;
            }
            else{
                cur = arr[i];
                cout<<"("<<start<<" "<<end<<") ";
                start = i;
                end = i;
            }
        }

        if(flag == 0)
            cout<<"No Profit";
        else if(start != N-1 && end == N-1)
            cout<<"("<<start<<" "<<end<<") ";
        cout<<endl;

	}
	return 0;
}