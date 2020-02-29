#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,count1=0,count2=0,rem,s,flag=0;
	    cin>>N;
        char S[2*N];
        rem = N;
        s = 2*N;
        for(int i=0;i<2*N;i++){
            cin>>S[i];
            if(i%2 == 0){
                if((count1  - count2) > rem || (count2  -count1) > rem){
                    s = i;
                    break;
                }
                if(S[i] == '1')
                    count1++;
                rem--;
            }
            else if(S[i] == '1')
                    count2++;
        }
        cout<<s<<"\n";

	}
	return 0;
}