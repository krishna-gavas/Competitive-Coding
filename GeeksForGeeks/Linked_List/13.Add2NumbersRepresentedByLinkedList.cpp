// Add two numbers represented by linked lists

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
void InsertAtStart(struct Node** head, int newdata){
    struct Node* newNode = new Node(newdata);
    newNode->next = *head;
    *head = newNode;
}

struct Node* addTwoLists(struct Node *head1, struct Node *head2){
    struct Node *head = NULL;
    int temp = 0,num;
    while(head1 != NULL && head2 != NULL){
        num = head1->data + head2->data + temp;
        if(num > 9){
            temp = num / 10;
            num = num % 10;
        }
        else{
            temp = 0;
        }
        Insert(&head, num);
        head1 = head1->next;
        head2 = head2->next;
    }
    while(head1 != NULL){
        num = head1->data + temp;
        if(num > 9){
            temp = num / 10;
            num = num % 10;
        }
        else{
            temp = 0;
        }
        Insert(&head, num);
        head1 = head1->next;
    }
    while(head2 != NULL){
        num = head2->data + temp;
        if(num > 9){
            temp = num / 10;
            num = num % 10;
        }
        else{
            temp = 0;
        }
        Insert(&head, num);
        head2 = head2->next;
    }
    if(temp != 0)
        Insert(&head, temp);
    return head;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    struct Node *head1 = NULL;
        struct Node *head2 = NULL;
        int n1,n2,x;

        cin>>n1;
        for(int i=0;i<n1;i++){
            cin>>x;
            InsertAtStart(&head1,x);
        }
        cin>>n2;
        for(int i=0;i<n2;i++){
            cin>>x;
            InsertAtStart(&head2,x);
        }
        
        struct Node* head = addTwoLists(head1, head2);
        Print(head);
	}
	return 0;

}