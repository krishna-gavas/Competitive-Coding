// Get minimum element from stack

// Question:
// You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.

// Input:
// push(2)
// push(3)
// pop()
// getMin()
// push(1)
// getMin()
// Output: 3 2 1

// Your Task:
// You are required to complete the three methods push() which take one argument an integer 'x' to be pushed into 
// the stack, pop() which returns a integer poped out from the stack and getMin() which returns the min element from 
// the stack. (-1 will be returned if for pop() and getMin() the stack is empty.)

// Solution:
// Push(x) : Inserts x at the top of stack.

// If stack is empty, insert x into the stack and make minEle equal to x.
// If stack is not empty, compare x with minEle. Two cases arise:
// If x is greater than or equal to minEle, simply insert x.
// If x is less than minEle, insert (2*x – minEle) into the stack and make minEle equal to x.

// Pop() : Removes an element from top of stack.

// Remove element from top. Let the removed element be y. Two cases arise:
// If y is greater than or equal to minEle, the minimum element in the stack is still minEle.
// If y is less than minEle, the minimum element now becomes (2*minEle – y), 
// update (minEle = 2*minEle – y). Now retrieve previous minimum from current minimum and its value in stack.

#include <iostream>
#include <stack>
using namespace std;

class _stack{
    stack<int> s;
    int minEle;
    public :
        int getMin();
        int pop();
        void push(int);
};

int _stack :: getMin()
{
    if(s.empty())
        return -1;
    else 
        return minEle;
}

int _stack ::pop()
{
    if(s.empty())
        return -1;
    int y = s.top();
    s.pop();
    if(y < minEle){
        minEle = 2*minEle - y;
        return (minEle + y)/2;
    }
    else{
        return y;
    }
}

void _stack::push(int x)
{
    if(s.empty()){
        minEle = x;   
        s.push(x);
    }
    else if(x < minEle){
        s.push(2*x - minEle);
        minEle = x;      
    }
    else
        s.push(x);
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    _stack *a = new _stack();
	    int Q;
	    cin>>Q;
        while(Q--){
            int QueryType = 0;
            cin>>QueryType;
            if(QueryType == 1){
                int x;
                cin>>x;
                a->push(x);
            }
            else if(QueryType == 2)
                cout<<a->pop()<<" ";
            else if(QueryType == 3)
                cout<<a->getMin()<<" ";
        }
        cout<<"\n";
        
	}
	return 0;
}