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

int main() {
	int T;
	cin>>T;
	while(T--){
	    int X,K,div,pri,flag=0;
        cin>>X>>K;
        for(int j=X;j<X*X;j++){
            div = 0; pri = 0;
            if(isPrime(j))
                continue;
            for (int i = 1; i <= sqrt(j); i++) { 
                if (j % i == 0) { 
                    if (j / i == i) 
                        div++;        
                    else  
                        div = div + 2; 
                } 
            }
            if(X == div){
                for (int i = 1; i <= sqrt(j); i++){
                    if (j % i == 0){
                        if(isPrime(i) && isPrime(j/i))
                            pri = pri + 2;
                        else if(isPrime(i))
                            pri++;
                    }
                }
                cout<<j<<" "<<div<<" "<<pri<<endl;
                if(pri == K){
                    flag = 1;
                    // break;
                }
            }
        }
        if(flag == 1)
            cout<<"1\n";
        else 
            cout<<"0\n";
	}
	return 0;
}