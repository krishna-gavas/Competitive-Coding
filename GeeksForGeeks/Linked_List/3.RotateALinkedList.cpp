// Rotate a Linked List

// Question:
// Given a singly linked list of size N. The task is to rotate the linked list counter-clockwise by k nodes, 
// where k is a given positive integer smaller than or equal to length of the linked list.

// Example:
// Input:
// N = 8
// value[] = {1,2,3,4,5,6,7,8}
// k = 4
// Output: 5 6 7 8 1 2 3 4

// Your Task:
// The task is to complete the function rotate() which takes a head reference as the first argument 
// and k as the second argument. The printing is done automatically by the driver code

#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

void Print(struct Node** head){
    struct Node* temp = *head;
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

struct Node* rotate(struct Node* head,int k){
    struct Node *cur = head;
    struct Node *tail = head;
    int count = 1;
    while(tail->next != NULL){
        tail = tail->next;
        count++;
    }
    if(k > count)
        k = k % count;
    if(k == 0)
        return head;
    for(int i=1;i<k;i++)
        cur = cur->next;

    tail->next = head;
    head = cur->next;
    cur->next = NULL;
    
    return head;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    struct Node *head = NULL;
        int N,l,K;

        cin>>N;
        for(int i=0;i<N;i++){
            cin>>l;
            Insert(&head,l);
        }
        cin>>K;
        head = rotate(head, K);
        Print(&head);

	}
	return 0;

}