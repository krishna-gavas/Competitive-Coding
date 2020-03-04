// Rotate a Linked List

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

struct Node* rotate(struct Node* head,int k){
    struct Node *cur = head;
    struct Node *tail = head;
    int count = 1;
    while(tail->next != NULL){
        tail = tail->next;
        count++;
    }
    if(k > count)
        k = k % count;
    if(k == 0)
        return head;
    for(int i=1;i<k;i++)
        cur = cur->next;

    tail->next = head;
    head = cur->next;
    cur->next = NULL;
    
    return head;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    struct Node *head = NULL;
        int N,l,K;

        cin>>N;
        for(int i=0;i<N;i++){
            cin>>l;
            Insert(&head,l);
        }
        cin>>K;
        head = rotate(head, K);
        Print(&head);

	}
	return 0;

}