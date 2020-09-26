// Nth node from end of linked list

// Question:
// Given a linked list consisting of L nodes and given a number N. 
// The task is to find the Nth node from the end of the linked list.

// Example:
// Input:
// N = 2
// LinkedList: 1->2->3->4->5->6->7->8->9
// Output: 8

// Your Task:
// The task is to complete the function getNthFromLast() which takes two arguments: reference to head and N 
// and you need to return Nth from the end or -1 in case node doesn't exist..

// Solution: 
// getNthFromLast(head,n): count the number of nodes and store it in count variable 
//     if(n > count) then return -1 
//     make count = count - n 
//     traverse the linked list till count and return the node->data 

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