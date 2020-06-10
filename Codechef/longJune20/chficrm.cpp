// Chef and Icecream

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,flag=0;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
            cin>>a[i];
        int c5=0,c10=0,c15=0;
        for(int i=0;i<N;i++){
            if(a[i] == 5)
                c5++;
            else if(a[i] == 10){
                if(c5 > 0){
                    c5--;
                    c10++;
                }
                else{
                    flag = 1;
                    break;
                }
            }
            else if(a[i] == 15){
                if(c10 > 0){
                    c10--;
                    c15++;
                }
                else if(c5 > 1){
                    c5 -= 2;
                    c15++;
                }
                else{
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1)
            cout<<"NO\n";
        else 
            cout<<"YES\n";
	}
	return 0;
}