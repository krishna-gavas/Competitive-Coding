// Longest Common Prefix in an Array

#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,count=0,flag=0,min=1000;
        cin>>N;
        string arr[N],str;
        for(int i=0;i<N;i++){
            cin>>arr[i];
            int len = arr[i].length();
            if(len < min){
                min = len;
                str = arr[i];
            }
        }
        
        for(int i=0;i<min;i++){
            for(int j=0;j<N;j++){
                if(arr[j][i] == str[i]){
                    // Nothing here
                }
                else{
                    flag = 1;
                    break;
                }               
            }
            if(flag == 1)
                break;
            count++;
        }
        if(count==0)
            cout<<-1<<endl;
        else
            cout<<str.substr(0,count)<<endl;
           
	}
	return 0;
}