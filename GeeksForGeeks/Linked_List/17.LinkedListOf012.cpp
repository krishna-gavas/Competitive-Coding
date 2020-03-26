// Given a linked list of 0s, 1s and 2s, sort it.(Segmentation Fault)

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

void InsertNode(struct Node** head, int newdata, struct Node** tail){
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

struct Node* segregate(Node *head)
{
    struct Node *temp = head;
    struct Node *head1 = NULL, *head2 = NULL, *head3 = NULL;
    struct Node *tail1 = NULL, *tail2 = NULL, *tail3 = NULL;
    int flag1 = 0, flag2 = 0, flag3 = 0;
    while(temp != NULL){
        if(temp->data == 0){
            InsertNode(&head1,0,&tail1);
            flag1++;
        }
        else if(temp->data == 1){
            InsertNode(&head2,1,&tail2);
            flag2++;
        }
        else if(temp->data == 2){
            InsertNode(&head3,2,&tail3);
            flag3++;
        }
        temp = temp->next;
    }
    if(flag1 == 0){
        if(flag2 == 0){
            if(flag3 == 0)
                head1 = NULL;
            else 
                head1 = head3;
        }
        else {
            
        }

    }
    tail1->next = head2;
    tail2->next = head3;
    tail3->next = NULL;

    return head1;
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
        struct Node *head1 = segregate(head);     
        Print(head1);
	}
	return 0;

}