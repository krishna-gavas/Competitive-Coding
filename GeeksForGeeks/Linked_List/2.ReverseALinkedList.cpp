// Reverse a Linked List

// Question:
// Given a linked list of N nodes. The task is to reverse this list

// Example:
// Input:
// LinkedList: 1->2->3->4->5->6
// Output: 6 5 4 3 2 1
// Explanation: After reversing the list, 
// elements are 6->5->4->3->2->1.

// Your Task:
// The task is to complete the function reverseList() with head reference as the only argument and should 
// return new head after reversing the list.

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

struct Node* reverseList(struct Node* head){
    struct Node *cur, *prev, *next;
    cur = head;
    prev = NULL;
    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    struct Node *head = NULL;
        int N,l;

        cin>>N;
        for(int i=0;i<N;i++){
            cin>>l;
            Insert(&head,l);
        }
        head = reverseList(head);
        Print(&head);

	}
	return 0;

}