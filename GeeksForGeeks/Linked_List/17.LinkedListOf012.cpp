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
    struct Node *head1 = NULL, *head2 = NULL, *head3 = NULL;
    struct Node *tail1 = NULL, *tail2 = NULL, *tail3 = NULL;
    int flag1 = 0, flag2 = 0, flag3 = 0;
    while(temp != NULL){
        if(temp->data == 0){
            InsertNode(&head1,0,&tail1);
            flag1++;
        }
        else if(temp->data == 1){
            InsertNode(&head2,1,&tail2);
            flag2++;
        }
        else if(temp->data == 2){
            InsertNode(&head3,2,&tail3);
            flag3++;
        }
        temp = temp->next;
    }
    if(flag1 == 0){
        if(flag2 == 0){
            if(flag3 == 0)
                head1 = NULL;
            else 
                head1 = head3;
        }
        else {
            
        }

    }
    tail1->next = head2;
    tail2->next = head3;
    tail3->next = NULL;

    return head1;
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