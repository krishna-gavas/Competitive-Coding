// Pairwise swap elements of a linked list

// Question:
// Given a singly linked list of size N. The task is to swap elements in the linked list pairwise.
// For example, if the input list is 1 2 3 4, the resulting list after swaps will be 2 1 4 3.

// Input:
// LinkedList: 1->2->2->4->5->6->7->8
// Output: 2 1 4 2 6 5 8 7

// Your Task:
// The task is to complete the function pairWiseSwap() which takes the head node as the only argument 
// and returns the modified head.

// Solution:
// pairWiseSwap(head): create 3 nodes namely first,second,temp and point them to head and initialize flag = 0
//     while(second->next != NULL): make first as second->next and point second->next to first->next 
//         point first->next to second 
//         if(flag is 0) then make first as head 
//         else point temp->next to first and make temp = second 
//         make second = second->next and first = second 
//         if(second == NULL) then break 
//         make flag = 1
//     return head


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

struct Node* pairWiseSwap(struct Node *head){
    struct Node *temp = head, *first = head, *second = head;
    int flag = 0;
    while(second->next != NULL){
        first = second->next;
        second->next = first->next;
        first->next = second;
        if(flag == 0)
            head = first;
        if(flag != 0){
            temp->next = first;
            temp = second;
        }
        second = second->next;
        first = second;

        if(second == NULL)
            break;
        flag = 1;
    }
    return head;
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
        
        head = pairWiseSwap(head);
        Print(head);
	}
	return 0;
}