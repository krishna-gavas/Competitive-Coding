// Delete without head pointer

// Question:
// You are given a pointer/ reference to the node which is to be deleted from the linked list of N nodes. 
// The task is to delete the node. Pointer/ reference to head node is not given. 
// Note: No head reference is given to you.

// Input:
// N = 4
// value[] = {10,20,4,30}
// node = 20
// Output: 10 4 30

// Your Task:
// You only need to complete the function deleteNode that takes reference to the node that needs to be deleted. 
// The printing is done automatically by the driver code.

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

void Print(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

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

struct Node* findNode(struct Node* head, int val){
    struct Node *current = head;
    while(current != NULL){
        if( current->data == val)
            break;
        current = current->next;
    }
    return current;
}

void deleteNode(struct Node* del){
    while(del->next->next != NULL){
        del->data = del->next->data;
        del = del->next;
    }
    del->data = del->next->data;
    del->next = NULL;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    struct Node *head = NULL;
        int N,x,k;

        cin>>N;
        for(int i=0;i<N;i++){
            cin>>x;
            Insert(&head,x);
        }
        cin>>k;

        struct Node *del = findNode(head, k);  
        if( del != NULL && del->next != NULL)
            deleteNode(del);   
        Print(head);
	}
	return 0;

}