// The Maths Teacher

#include <iostream>
#include <math.h>
using namespace std;

bool IsPowerOfTwo(int x)
{
    return (x != 0) && ((x & (x - 1)) == 0);
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int X,cur=1,flag=0;
        cin>>X;
        if(X == 1 || X == 2){
            cout<<"Yes\n";
            continue;
        }      
        if(IsPowerOfTwo(X) || IsPowerOfTwo((X*3)+1))
            cout<<"Yes\n";
        else
            cout<<"No\n";   
	}
	return 0;
}