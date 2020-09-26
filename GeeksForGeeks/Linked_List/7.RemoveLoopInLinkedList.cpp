// Remove loop in Linked List(Not Submitted)

// Question:
// You are given a linked list of N nodes. The task is to remove the loop from the linked list, if present. 
// Note: C is the position of the node to which the last node is connected. If it is 0 then no loop

// Example:
// Input:
// N = 3
// value[] = {1,3,4}
// C = 2
// Output: 1

// Input:
// N = 4
// value[] = {1,8,3,4}
// C = 0
// Output: 1

// Your Task:
// Your task is to complete the function removeLoop(). The only argument of the function is head pointer of the
// linked list. Simply remove the loop in the list (if present) without disconnecting any nodes from the list. 
// The driver code will print 1 if your code is correct.

// Solution:
// detectloop(head): if(head == NULL) return false 
//     make 3 nodes namely p,q and end and point p,q to head
//     while(p != NULL && q != NULL && q->next != NULL): make end = p
//         jump p by 1 step and q by 2 steps
//         if(p == q) break  
//     if(p != q) then return
//     if(head != p) then end = endLoop(head,p) (here end node point to end of loop)
//     make end->next = NULL

// endLoop(head,p): make a node q and point it to head 
//     while(p->next != q->next) increment both p and q 
//     return p

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

void removeLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

Node* endLoop(Node* head, Node* p){
    Node *q = head;
    while(p->next != q->next){
        q = q->next;
        p = p->next;
    }
    return p;
}

void removeLoop(Node* head)
{
    if(head == NULL)
        return;
    Node *p = head, *q = head, *end;
    while(p != NULL && q != NULL && q->next != NULL){
        end = p;
        p = p->next;
        q = q->next->next;
        if(p == q)
            break;
    }
    if(p != q)
        return;
    if(head != p)
        end = endLoop(head,p);
    end->next = NULL;
}