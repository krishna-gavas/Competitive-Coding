// First non-repeating character in a stream

// Question:
// Given an input stream of N characters consisting only of lower case alphabets. The task is to find the first non 
// repeating character, each time a character is inserted to the stream. If no non repeating element is found print -1.

// Input:
// The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test 
// case contains an integer N denoting the size of the stream. Then in the next line are x characters which are 
// inserted to the stream.

// Output:
// For each test case in a new line print the first non repeating elements separated by spaces present in the stream 
// at every instinct when a character is added to the stream, if no such element is present print -1

// Example:
// Input:
// 2
// 4
// a a b c
// 3
// a a c

// Output:
// a -1 b b
// a -1 c

#include <iostream>
using namespace std;

struct Node{
    char data;
    Node *next,*prev;
    Node(int data)
    {
        this->data=data;
        next=prev=NULL;
    }
};

Node* Insert(struct Node** head, int newdata){
    struct Node* newNode = new Node(newdata);    
    if(*head == NULL)
        *head = newNode;
    else{
        struct Node* temp = *head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }
    return newNode;
}

int main() {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    char in[n], out[n];
        Node* inDLL[256] = {NULL};
        bool repeated[256] = {false};
        Node *head = NULL;
        for(int i=0;i<n;i++){
            cin>>in[i];
            if(repeated[in[i]]){

            }
            else{
                if(inDLL[in[i]] == NULL){
                    Node *newNode = Insert(&head, in[i]);
                    inDLL[in[i]] = newNode;
                }
                else{
                    Node *tempNode = inDLL[in[i]];
                    if(head == inDLL[in[i]]){
                        if(head->next == NULL)
                            head = NULL;
                        else{
                            head = head->next;
                            head->prev = NULL;
                        }
                    }
                    else if(tempNode->next == NULL){
                        tempNode->prev->next = NULL;
                    }
                    else{
                        Node *prevNode = tempNode->prev, *nextNode = tempNode->next;
                        prevNode->next = tempNode->next;
                        nextNode->prev = tempNode->prev;
                    }
                    inDLL[in[i]] = NULL;
                    repeated[in[i]] = true;
                }
            }
            if(head != NULL)
                cout<<head->data<<" ";
            else 
                cout<<-1<<" ";
        }
        cout<<"\n";
	}
	return 0;
}