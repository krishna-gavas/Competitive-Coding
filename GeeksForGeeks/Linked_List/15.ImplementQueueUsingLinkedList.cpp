// Implement Queue using Linked List

// Question:
// Implement a Queue using Linked List. 
// A Query Q is of 2 Types
// (i) 1 x   (a query of this type means  pushing 'x' into the queue)
// (ii) 2     (a query of this type means to pop an element from the queue and print the poped element)

// Input:
// Q = 5
// Queries = 1 2 1 3 2 1 4 2
// Output: 2 3

// Your Task:
// Complete the function push() which takes an integer as input parameter and pop() which will remove 
// and return an element(-1 if queue is empty).

#include <iostream>
using namespace std;

struct QueueNode{
    int data;
    struct QueueNode* next;

    QueueNode(int x){
        data = x;
        next = NULL;
    }
};

struct MyQueue{
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() { front = rear = NULL;}
};

void MyQueue:: push(int x)
{
    struct QueueNode *newNode = new QueueNode(x);
    if(front == NULL && rear == NULL){
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

int MyQueue :: pop()
{
    
    if(front == NULL)
        return -1;
    if(front == rear){
        int val = front->data;
        front = rear = NULL;
        return val;
    }
    else{
        struct QueueNode *temp = front;
        int val = front->data;
        front = front->next;
        free(temp);
        return val;
    }
    
}


int main() {
	int T;
	cin>>T;
	while(T--){
        MyQueue *sq = new MyQueue();
	    
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