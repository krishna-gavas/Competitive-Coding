// Intersection Point in Y Shapped Linked Lists

// Question:
// Given two singly linked lists of size N and M, write a program to get the point where two 
// linked lists intersect each other.

// Example: 
// Input:
// LinkList1 = {10,20,5,10}
// LinkList2 = {30,40,50,5,10}
// Output: 5

// Your Task:
// The task is to complete the function intersetPoint() which finds the point of intersection of two 
// linked list. The function should return data value of a node where two linked lists merge. 
// If linked list do not merge at any point, then it should return -1.

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

int intersectPoint(struct Node* head1, struct Node* head2){
    struct Node *temp1 = head1;
    while(temp1 != NULL){
        struct Node *temp2 = head2;
        while(temp2 != NULL){
            if(temp1->next == temp2->next){
                temp1 = temp1->next;
                return temp1->data;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return -1;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    struct Node *head = NULL, *head1 = NULL, *head2 = NULL;
        struct Node *tail = NULL, *tail1 = NULL, *tail2 = NULL;
        int X,Y,Z,l,out;

        cin>>X>>Y>>Z;
        for(int i=0;i<X;i++){
            cin>>l;
            Insert(&head1,l,&tail1);
        }
        for(int i=0;i<Y;i++){
            cin>>l;
            Insert(&head2,l,&tail2);
        }
        for(int i=0;i<Z;i++){
            cin>>l;
            Insert(&head,l,&tail);
        }
        tail1->next = head;
        tail2->next = head;
        out = intersectPoint(head1, head2);
        cout<<out<<endl;

	}
	return 0;

}