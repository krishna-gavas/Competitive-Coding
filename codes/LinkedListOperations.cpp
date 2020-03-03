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

void InsertAtStart(struct Node** head, int newdata){
    struct Node* newNode = new Node(newdata);
    newNode->next = *head;
    *head = newNode;
}

void InsertAtEnd(struct Node** head, int newdata){
    struct Node* newNode = new Node(newdata);    
    if(*head == NULL)
        *head = newNode;
    else{
        struct Node* temp = *head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void InsertAtN(struct Node** head, int newdata,int n){
    struct Node* newNode = new Node(newdata);
    if(n == 1){
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    for(int i=0;i<n-2;i++)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

void DeleteAtN(struct Node** head,int n){
    struct Node* temp1 = *head;
    if(n == 1){
        *head = temp1->next;
        free(temp1);
        return;
    }
    for(int i=0;i<n-2;i++)
        temp1 = temp1->next;
    struct Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    struct Node* head = NULL;
        int N,l;

        cin>>N;
        for(int i=0;i<N;i++){
            cin>>l;
            InsertAtEnd(&head,l);
            // InsertAtStart(&head,l);
        }
        Print(&head);
        // InsertAtN(&head,6,2);
        // DeleteAtN(&head,2);
	}
	return 0;

}