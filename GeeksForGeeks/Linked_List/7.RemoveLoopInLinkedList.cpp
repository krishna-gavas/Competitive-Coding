// Remove loop in Linked List(Not Submitted)

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

void removeTheLoop(struct Node **head){
    struct Node *temp1 = *head, *temp2 = *head,*temp3 = *head;
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
    *head = temp3;
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
        removeTheLoop(&head);
        
        Print(head);
	}
	return 0;

}