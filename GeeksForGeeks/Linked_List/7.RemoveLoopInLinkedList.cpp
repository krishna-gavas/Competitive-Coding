// Remove loop in Linked List(Not Submitted)

// Question:
// You are given a linked list of N nodes. The task is to remove the loop from the linked list, if present. 
// Note: C is the position of the node to which the last node is connected. If it is 0 then no loop

// Example:
// Input:
// N = 3
// value[] = {1,3,4}
// C = 2
// Output: 1

// Input:
// N = 4
// value[] = {1,8,3,4}
// C = 0
// Output: 1

// Your Task:
// Your task is to complete the function removeLoop(). The only argument of the function is head pointer of the
// linked list. Simply remove the loop in the list (if present) without disconnecting any nodes from the list. 
// The driver code will print 1 if your code is correct.


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

void Print(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
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

void removeTheLoop(struct Node *head){
    struct Node *temp1 = head, *temp2 = head,*temp3 = head;
    int count = 0;
    while(temp1 != NULL){
        if(temp1->data < 0){
            temp2->next = NULL;
            break;
        }
        temp1->data = -(temp1->data);
        temp1 = temp1->next;
        temp2->next = temp1;
        count++;
    }
    head = temp3;
    // struct Node *temp3 = *head;
    // for(int i=0;i<count;i++){
    //     cout<<temp3->data<<" ";
    //     temp3 = temp3->next;
    // }
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
        // removeTheLoop(head);
        
        Print(head);
	}
	return 0;

}