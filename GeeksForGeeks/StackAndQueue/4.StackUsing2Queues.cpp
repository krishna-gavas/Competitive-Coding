// Stack using two queues

// Question:
// Implement a Stack using two queues q1 and q2.

// Input:
// push(2)
// pop()
// pop()
// push(3)
// Output: 2 -1

// Your Task:
// Since this is a function problem, you don't need to take inputs. You are required to complete the two methods push() 
// which takes an integer 'x' as input denoting the element to be pushed into the stack and pop() which returns the 
// integer poped out from the stack(-1 if the stack is empty).

// Solution:
// Create 2 queues q1 and q2.
// push(x):
//     while(q2 is not empty) pop q2.front() and push it to q1.
//     push x to q1.

// pop();
//     if both q1 and q2 are empty return -1.
//     while(q2 is not empty) pop q2.front() and push it to q1.
//     initialize len = q1.size().
//     while(len > 1) pop q1.front() and push it to q2 and decrement len.
//     val = q1.front(), pop q1.front() and return val.
    

#include <iostream>
#include <queue>
using namespace std;

class QueueStack{
    private: 
        queue<int> q1;
        queue<int> q2;

    public:
        void push(int B);
        int pop(); 
};

void QueueStack :: push(int x){
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
    q1.push(x);
}

int QueueStack :: pop(){
    int val;
    if(q1.empty() && q2.empty())      
        return -1;

    if(!q2.empty()){
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }    
    }
    int len = q1.size();
    while(len > 1){
        q2.push(q1.front());
        q1.pop();
        len--;
    }
    val = q1.front();
    q1.pop();
    return val;
}

int main() {
	int T;
	cin>>T;
	while(T--){

        QueueStack *qs = new QueueStack();
	    int Q;
	    cin>>Q;
        while(Q--){
            int QueryType = 0;
            cin>>QueryType;
            if(QueryType == 1){
                int a;
                cin>>a;
                qs->push(a);
            }
            else if(QueryType == 2)
                cout<<qs->pop()<<" ";
        }
        cout<<"\n";
	}
	return 0;
}