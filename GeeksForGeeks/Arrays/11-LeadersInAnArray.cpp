// Leaders in an array
// Leader is an element such that all elements right to it are either smaller or equal
// access element in reverse order and compare it with max
// if it is greater than max then push it to stack
#include <iostream>
#include <stack>
using namespace std;
 
int main ()  
{  
	long int T;
	cin>>T; 
	while(T--){
	    long int N;
	    cin>>N;
	    int arr[N],flag=0;
	    stack <int> S;  

	    for(int i=0;i<N;i++)
	        cin>>arr[i];

		int max = arr[N-1];

		for(int i=N-1;i>=0;i--){
			if(arr[i] >= max){
				S.push(arr[i]);
				max = arr[i];
			}
		}

		while(flag == 0)
			if(S.empty())
				flag = 1;
			else{
				cout<<S.top()<<" ";
				S.pop();
			}
		cout<<endl;
	}    
    return 0;  
} 