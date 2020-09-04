// Implement Stack using Linked List

// Question:
// Let's give it a try! You have a linked list and you have to implement the functionalities 
// push and pop of stack using this given linked list. Your task is to use the class as shown in the comments 
// in the code editor and complete the functions push() and pop() to implement a stack.

// Input: 
// push(2)
// push(3)
// pop()
// push(4) 
// pop()
// Output: 3, 4

// Input: 
// pop()
// push(4)
// push(5)
// pop()
// Output: -1, 5

// Your Task: You are required to complete two methods push() and pop(). The push() method takes one argument, 
// an integer 'x' to be pushed into the stack and pop() which returns an integer present at the top and 
// popped out from the stack. If the stack is empty then return -1 from the pop() method.

#include <iostream>
using namespace std;

struct StackNode
{
    int data;
    struct StackNode *next;
    StackNode(int x)
    {
        data = x;
        next = NULL;
    }
};

class MyStack {
    private:
    StackNode *top;
    public :
        void push(int);
        int pop();
        MyStack()
        {
            top = NULL;
        }
};

void MyStack ::push(int x) {
    struct StackNode *newNode = new StackNode(x);
    newNode->next = top;
    top = newNode;
}

int MyStack ::pop() {
    if(top == NULL)
        return -1;
    struct StackNode *temp = top;
    int val = top->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
	int T;
	cin>>T;
	while(T--){
        MyStack *sq = new MyStack();
	    
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
            else if(QueryType == 2){
                cout<<sq->pop()<<" ";
            }
        }
        cout<<"\n";
	}
	return 0;

}