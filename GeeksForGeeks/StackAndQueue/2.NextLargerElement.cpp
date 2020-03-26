// Next larger element
// 1) Push the first element to stack.
// 2) Pick rest of the elements one by one and follow the following steps in loop.
//  a) Mark the current element as next.
//  b) If stack is not empty, then pop an element from stack and compare it with next.
//  c) If next is greater than the popped element, then next is the next greater element for the popped element.
//  d) Keep popping from the stack while the popped element is smaller than next.next becomes the next greater element for all such popped elements
//  e) Finally, push the next in the stack.
// 3) After the loop in step 2 is over, pop all the elements from stack and print -1 as next element for them.

#include <iostream>
#include <stack>
using namespace std;

void nextLarger(long long arr[], int n){
    stack <long long int> s;
    long long  B[n];
    long long int next,ele;

    for(int i=n-1;i>=0;i--){
        next = arr[i];
        while(!s.empty() && next > s.top()){              
            s.pop();
        }
        if(s.empty())
            B[i] = -1;
        else 
            B[i] = s.top();

        s.push(next);
    }

    for(int i=0;i<n;i++)
        cout<<B[i]<<" ";
    cout<<"\n";
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    long long int arr[N];

	    for(int i=0;i<N;i++)
	        cin>>arr[i];

        nextLarger(arr, N);
	}
	return 0;
}