#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int N,S,flag=0,start=0,stop=0;
	    cin>>N>>S;
	    long int arr[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	        
	    for(int i=0;i<N;i++){
	        long int sum = arr[i];  
            if(sum==S){
                start = i+1;
	            stop = i+1;
                flag = 1;
	        }        
	        for(int j=i+1;j<N;j++){
	            
                sum = sum + arr[j];
	            if(sum==S){
	                start = i+1;
	                stop = j+1;
                    flag = 1;
	                break;
	            }
            
	        }
	        if(flag==1)
	            break;
	    }
	    if(start==0 && stop==0)
	        cout<<-1<<endl;
	    else
	        cout<<start<<" "<<stop<<endl;
	}
	return 0;
}