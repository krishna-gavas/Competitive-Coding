// Flattening a Linked List(Not submitted)

// Question:
// Given a Linked List of size N, where every node represents a linked list and contains two pointers of its type:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
// Note: The flattened list will be printed using the bottom pointer instead of next pointer.

// Input:
// 5 -> 10 -> 19 -> 28
// |     |     |     | 
// 7     20    22   35
// |           |     | 
// 8          50    40
// |                 | 
// 30               45
// Output:  5-> 7-> 8- > 10 -> 19-> 20->
// 22-> 28-> 30-> 35-> 40-> 45-> 50.
// Note: | represents the bottom pointer.

// Your Task:
// You need to complete the function flatten() that takes head of the list as parameter and returns the 
// root of flattened list. The printing is done by the driver code.

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


void Insert(struct Node** head, int newdata){
    struct Node *newNode = new Node(newdata);    
    if(*head == NULL)
        *head = newNode;
    else{
        struct Node *temp = *head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

int getNthFromLast(struct Node *head, int n){
    struct Node *temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    if(n > count)
     return -1;
    count = count - n;
    struct Node *temp1 = head;
    for(int i=0;i<count;i++)
        temp1 = temp1->next;
    
    return temp1->data;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    struct Node *head = NULL;
        int N,L,x,out;

        cin>>L>>N;
        for(int i=0;i<L;i++){
            cin>>x;
            Insert(&head,x);
        }
        
        out = getNthFromLast(head, N);
        cout<<out<<endl;
	}
	return 0;

}