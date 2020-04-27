// Strange Number

#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n) 
{ 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i <= sqrt(n); i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true;
}

int strangeNum(int X, int K){
    if(K == 1)
        return 1;
    int flag = 0,res;
    for(int i=2;i<=sqrt(X);i++){
        if(X % i == 0){
            X = X / i;
            flag = 1;
            if(isPrime(i))
                K--;
        }
    }
    if(flag == 1)
        res = strangeNum(X, K);
    else 
        return 0;
    return res;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int X,K,out;
        cin>>X>>K;
        out = strangeNum(X,K);
        cout<<out<<"\n";

	}
	return 0;
}