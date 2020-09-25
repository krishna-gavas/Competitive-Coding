// Given a linked list of 0s, 1s and 2s, sort it.(Segmentation Fault)

// Question:
// Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. 
// The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 
// 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

// Input:
// N = 8
// value[] = {1,2,2,1,2,0,2,2}
// Output: 0 1 1 2 2 2 2 2

// Your Task:
// The task is to complete the function segregate() which segregates the nodes in the linked list as asked 
// in the problem statement and returns the head of the modified linked list. 
// The printing is done automatically by the driver code.

// Solution:
// segregate(head): Create a temp node and point it to head 
//     create 3 dummy head nodes with value 0, also create 3 tail nodes and point them to respective head nodes 
//     while temp is not NULL:
//         if(temp->data == 0) then point tail0 to temp, increment tail0 and temp and make tail0->next = NULL
//         else if(temp->data == 1) then point tail1 to temp, increment tail1 and temp and make tail1->next = NULL
//         else if(temp->data == 2) then point tail2 to temp, increment tail2 and temp and make tail2->next = NULL
//     if(head1 exist) then point tail0 to head1->next(since head1 was dummy) else point it to head2->next
//     if(head2 exist) then point tail1 to head2->next
//     finally increment head0 and return head0


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

void InsertNode(struct Node** head, int newdata, struct Node** tail){
    struct Node *newNode = new Node(newdata);    
    if(*head == NULL){
        *head = newNode;
        *tail = newNode;
    }
    else{
        struct Node *temp = *head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        *tail = newNode;
    }
}

struct Node* segregate(Node *head)
{
    struct Node *temp = head;
    struct Node *head0 = new Node(0), *head1 = new Node(0), *head2 = new Node(0);
    struct Node *tail0 = head0, *tail1 = head1, *tail2 = head2;
    while(temp != NULL){
        if(temp->data == 0){
            tail0->next = temp;
            tail0 = tail0->next;
            temp = temp->next;
            tail0->next = NULL;
        }
        else if(temp->data == 1){
            tail1->next = temp;
            tail1 = tail1->next;
            temp = temp->next;
            tail1->next = NULL;
        }
        else if(temp->data == 2){
            tail2->next = temp;
            tail2 = tail2->next;
            temp = temp->next;
            tail2->next = NULL;
        }
    }
    if(head1->next != NULL)
        tail0->next = head1->next;
    else 
        tail0->next = head2->next;
    
    if(head2->next != NULL)
        tail1->next = head2->next;
    
    head0 = head0->next;

    return head0;
}


int main() {
	int T;
	cin>>T;
	while(T--){
	    struct Node *head = NULL;
        int N,x;

        cin>>N;
        for(int i=0;i<N;i++){
            cin>>x;
            Insert(&head,x);
        }
        struct Node *head1 = segregate(head);     
        Print(head1);
	}
	return 0;

}