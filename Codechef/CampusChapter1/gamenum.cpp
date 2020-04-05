// Another game of numbers

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long long int A,B,C,max=0,maxVal=0;
        int bitA,bitB;
        cin>>A>>B;
        bitA = log2(A) + 1;
        bitB = log2(B) + 1;
        if(bitA > bitB){
            for(int i=0;i<bitA;i++){
                unsigned lsbs = B & ((1 << 1) - 1);
                B = (B >> 1)|(lsbs << (bitA - 1));
                C = A^B;
                if(C > maxVal){
                    maxVal = C;
                    max = i+1;
                }
            }
        }
        else{
            for(int i=0;i<bitB;i++){
                unsigned lsbs = B & ((1 << 1) - 1);
                B = (B >> 1)|(lsbs << (bitB - 1));
                C = A^B;
                if(C > maxVal){
                    maxVal = C;
                    max = i+1;
                }
            }
        }
        cout<<max<<" "<<maxVal<<"\n";
	}
	return 0;
}