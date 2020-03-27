// Delete without head pointer

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

struct Node* findNode(struct Node* head, int val){
    struct Node *current = head;
    while(current != NULL){
        if( current->data == val)
            break;
        current = current->next;
    }
    return current;
}

void deleteNode(struct Node* del){
    while(del->next->next != NULL){
        del->data = del->next->data;
        del = del->next;
    }
    del->data = del->next->data;
    del->next = NULL;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    struct Node *head = NULL;
        int N,x,k;

        cin>>N;
        for(int i=0;i<N;i++){
            cin>>x;
            Insert(&head,x);
        }
        cin>>k;

        struct Node *del = findNode(head, k);  
        if( del != NULL && del->next != NULL)
            deleteNode(del);   
        Print(head);
	}
	return 0;

}