// Pairwise swap elements of a linked list

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