// Longest Common Prefix in an Array

// Initialize count=0, flag=0, min=1000 and input N.
// input array of strings and also find string with minimum length and store it in str and its length in min.
// for(i=0 to min):
//     for(j=0 to N): if(arr[j][i] != str[i]) then flag=1 and break from loop 
//     increment count
// if count = 0 then print -1 else print str.substr(0,count)


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