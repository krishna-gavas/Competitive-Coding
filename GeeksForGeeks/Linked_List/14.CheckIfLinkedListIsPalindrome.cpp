// Check if Linked List is Palindrome

// Question:
// Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

// Input:
// N = 3
// value[] = {1,2,1}
// Output: 1

// Your Task:
// The task is to complete the function isPalindrome() which takes head as reference as the only parameter 
// and returns true or false if linked list is palindrome or not respectively.

// Solution:
// isPalindrome(head): create a stack and initialize len,odd and count to 0
//     create a temp node, point it to head and find length of linked list 
//     again point temp to head 
//     if len is 1 or if len is 2 and both nodes have same data then return true 
//     if len is odd then make odd = 1 and make len = len/2
//     push all the elements till len to stack and check whether all elements after len equals top of stack and pop them
//     if stack is empty return true else return false 

#include <iostream>
#include <stack>

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

bool isPalindrome(Node *head)
{
    stack<int> s;
    int len=0,odd=0,count=0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    temp = head;
    if(len == 1 || (len == 2 && temp->data == temp->next->data))
        return true;
    if(len % 2 == 1)
        odd = 1;
    len = len/2;
    while(temp != NULL){
        if(count < len)
            s.push(temp->data);
        if(count > len || (count == len && odd == 0)){
            if(s.top() == temp->data)
                s.pop();
        }
        count++;
        temp = temp->next;
    }
    if(s.empty())
        return true;
    else 
        return false;
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