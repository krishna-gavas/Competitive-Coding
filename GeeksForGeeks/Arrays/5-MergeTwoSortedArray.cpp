//Merge Two sorted array without extra space
#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    long int X,Y;
	    cin>>X>>Y;
	    long int P[X],Q[Y];

	    for(long int i=0;i<X;i++)
	        cin>>P[i];

		for(long int j=0;j<Y;j++)
	        cin>>Q[j];
		
		for(long int i=0;i<X;i++){
			for(long int j=0;j<Y;j++){
				if((P[i] > Q[j]) && (j != Y-1))
					continue;
				else if((P[i] > Q[j]) && (j == Y-1)){
					int temp = P[i];
					P[i] = Q[0];
					for(int k=0;k<Y-1;k++)
						Q[k] = Q[k+1];
					Q[Y-1] = temp;
					j = Y;
				}
				else if(P[i] < Q[0])
					j = Y;
				else{
					int temp = P[i];
					P[i] = Q[0];
					for(int k=0;k<j-1;k++)
						Q[k] = Q[k+1];
					Q[j-1] = temp;
					j = Y;
				}
			}
		}

		for(long int i=0;i<X;i++)
	        cout<<P[i]<<" ";

		for(long int i=0;i<Y;i++)
	        cout<<Q[i]<<" ";
		
		cout<<endl;
	}
	return 0;
}