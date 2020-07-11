// Chef and Card Game

#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
        int N;
        long long int chefp=0,mortyp=0,pow1,pow2,num;
        cin>>N;
        long int A[N],B[N];
        for(int i=0;i<N;i++){
            cin>>A[i]>>B[i];
            if(A[i] > 9){
                num = A[i];
                pow1 = 0;
                while(num > 0){
                    pow1 += num % 10;
                    num = num / 10;
                }
            }
            else 
                pow1 = A[i];

            if(B[i] > 9){
                num = B[i];
                pow2 = 0;
                while(num > 0){
                    pow2 += num % 10;
                    num = num / 10;
                }
            }
            else 
                pow2 = B[i];

            if(pow1 > pow2)
                chefp++;
            else if(pow2 > pow1)
                mortyp++;
            else{
                chefp++;
                mortyp++;
            }
        }
        if(chefp > mortyp)
            cout<<0<<" "<<chefp<<"\n";
        else if(mortyp > chefp)
            cout<<1<<" "<<mortyp<<"\n";
        else 
            cout<<2<<" "<<mortyp<<"\n";
    }
    return 0;
}