// Implement Stack using Linked List

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