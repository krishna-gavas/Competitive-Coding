// Flattening a Linked List(Not submitted)

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