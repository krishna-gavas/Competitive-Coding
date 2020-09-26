// Detect Loop in linked list

// Question:
// Given a linked list of N nodes. The task is to check if the the linked list has a loop. 
// Linked list can contain self loop.

// Example:
// Input:
// N = 3
// value[] = {1,3,4}
// x = 2
// Output: True

// Input:
// N = 4
// value[] = {1,8,3,4}
// x = 0
// Output: False

// Your Task:
// The task is to complete the function detectloop() which contains reference to the head as only argument. 
// This function should return 1 if linked list contains loop, else return 0.

// Solution:
// detectloop(head): if(head == NULL) return false 
//     make 2 nodes namely p,q and point them to head
//     while(p != NULL && q != NULL && q->next != NULL) 
//         jump p by 1 step and q by 2 steps
//         if(p == q) return true 
//     return false

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

void Print(struct Node* head, int j){
    struct Node* temp = head;
    for(int i=0;i<(3*j);i++){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void Insert(struct Node** head, int newdata, struct Node** tail){
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

int detectloop(struct Node *head){
    if(head == NULL)
        return false;
    Node *p = head, *q = head;
    while(p != NULL && q != NULL && q->next != NULL){
        p = p->next;
        q = q->next->next;
        if(p == q)
            return true;
    }
    return false;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    struct Node *head = NULL, *tail = NULL;
        int N,l,K,out,J;

        cin>>N;
        for(int i=0;i<N;i++){
            cin>>l;
            Insert(&head,l,&tail);
        }
        cin>>K;
        J = K;
        if(K > 0){
            struct Node *temp = head;
            while(--K)
                temp = temp->next;
            tail->next = temp;
        }
        // Print(head,J);
        out = detectloop(head);
        if(out)
            cout<<"True\n";
        else 
            cout<<"False\n";
	}
	return 0;

}