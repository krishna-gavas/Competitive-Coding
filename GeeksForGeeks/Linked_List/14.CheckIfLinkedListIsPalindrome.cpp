// Check if Linked List is Palindrome

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

struct Node* check(struct Node *head, struct Node *tail){
    struct Node *temp;
    if(tail->next != NULL){
        temp = tail;
        tail = tail->next;
        struct Node *out = check(head, tail);
        if(out == NULL)
            return NULL;
        else 
            head = out;
    }
    else{
        if(head->data != tail->data)
            return NULL;
        head = head->next;
        return head;
    }    
    if(head->data != temp->data)
        return NULL;
    head = head->next;
    return head;
}

bool isPalindrome(Node *head)
{
    struct Node *temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    if(count == 1)
        return true;
    count = (count / 2) + 1;
    struct Node *tail = head;
    for(int i=1;i<count;i++)
        tail = tail->next;

    struct Node *out = check(head, tail);
    if(out == NULL)
        return false;
    else 
        return true;
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
        
        bool out = isPalindrome(head);
        if(out)
            cout<<1<<"\n";
        else 
            cout<<0<<"\n";
	}
	return 0;

}