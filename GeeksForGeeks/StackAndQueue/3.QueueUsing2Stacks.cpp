// Queue using two Stacks

// Question:
// Implement a Queue using 2 stacks s1 and s2 .
// A Query Q is of 2 Types
// (i) 1 x (a query of this type means  pushing 'x' into the queue)
// (ii) 2   (a query of this type means to pop element from queue and print the poped element)

// Input:
// 5
// 1 2 1 3 2 1 4 2

// Output: 
// 2 3

// Your Task:
// You are required to complete the two methods push which take one argument an integer 'x' to be pushed into the 
// queue and pop which returns a integer poped out from other queue(-1 if the queue is empty). The printing is done 
// automatically by the driver code.

// Solution:
// Create 2 stacks s1 and s2.
// push(x): 
//     while(s2 is not empty) pop s2.top() and push it to s1.
//     push x to s1.

// pop():
//     if both s1 and s2 are empty return -1.
//     if(s2 is empty)
//         while(s1 is not empty) pop s1.top() and push it to s2.
//     val = s2.top(), pop s2.top() and return val.


#include <iostream>
#include <stack>
using namespace std;

class StackQueue{
    private: 
        stack<int> s1;
        stack<int> s2;

    public:
        void push(int B);
        int pop(); 
};

void StackQueue :: push(int x)
 {
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    s1.push(x);
 }

int StackQueue :: pop()
{
    int val;
    if(s1.empty() && s2.empty())      
        return -1;

    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }  
    }
    val = s2.top();
    s2.pop();
    return val; 
}

int main() {
	int T;
	cin>>T;
	while(T--){

        StackQueue *sq = new StackQueue();
	    int Q;
	    cin>>Q;
        while(Q--){
            int QueryType = 0;
            cin>>QueryType;
            if(QueryType == 1){
                int a;
                cin>>a;
                sq->push(a);
            }
            else if(QueryType == 2)
                cout<<sq->pop()<<" ";
        }
        cout<<"\n";
	}
	return 0;
}