// Binary Tree to DLL

// Question:
// Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in 
// nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL 
// must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) 
// must be the head node of the DLL.

// Input:
//        10
//       /   \
//      20   30
//    /   \
//   40   60
// Output:
// 40 20 60 10 30 
// 30 10 60 20 40

// Your Task:
// You don't have to take input. Complete the function bToDLL() that takes root node of the tree as a parameter 
// and returns the head of DLL . The driver code prints the DLL both ways.

// Solution:
// Accept a string s and call buildTree(s) function.
// In buildTree() copy the string elements into a vector.
//     build a queue and push root into it.
//     Access all the vector elements and also check if the queue is not empty:
//     initialize i=1(first element access)
//     For every access make currNode = queue.front() and currVal = ip[i]
//     check if(currVal != "N") and then make currNode->left as currVal and push it to queue and increment i.
//     make currVal = ip[i], check if(currVal != "N") and then make currNode->right as currVal and push it to queue and increment i.
//     finally return root.

// bToDLL(root, **head): if(root == NULL) return
//     create a stack of type node and initialize cur to root and prev to NULL 
//     while(curr is not null or stack is not empty)
//         push curr to stack and move left till curr is NULL
//         store top of stack to curr and pop top of stack 
//         if(prev == NULL) then *head_ref = curr
//         else make prev->right = curr and curr->left = prev
//         make prev = curr and curr = curr->right


#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <sstream>
#include <map>
using namespace std;

struct Node
{
   int data;
   Node* left;
   Node* right;
};

Node* newNode(int val)
{
   Node* temp = new Node;
   temp->data = val;
   temp->left = NULL;
   temp->right = NULL;

   return temp;
}

void bToDLL(Node *root, Node **head_ref);

Node* buildTree(string str)
{
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   Node* root = newNode(stoi(ip[0]));

   queue<Node*> queue;
   queue.push(root);

   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       Node* currNode = queue.front();
       queue.pop();

       string currVal = ip[i];

       if(currVal != "N") {

           currNode->left = newNode(stoi(currVal));
           queue.push(currNode->left);
       }
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       if(currVal != "N") {

           currNode->right = newNode(stoi(currVal));
           queue.push(currNode->right);
       }
       i++;
   }
   return root;
}

void printList(Node *node){
    Node *prev = NULL;
    while(node != NULL){
        cout<<node->data<<" ";
        prev = node;
        node = node->right;
    }
    cout<<endl;
    while(prev != NULL){
        cout<<prev->data<<" ";
        prev = prev->left;
    }
    cout<<endl;
}

void inorder(Node *root){
    if(root == NULL)
        return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
 
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s, ch; 
        getline(cin, s);
        Node* root = buildTree(s);

        Node* head = NULL;
        bToDLL(root, &head);
        printList(head);
   }
   return 0;
}

void bToDLL(Node *root, Node **head_ref){
    if(root==NULL)
        return;

    stack<Node *> s; 
    Node *curr = root, *prev = NULL; 
    while (curr != NULL || !s.empty()){ 
        while (curr !=  NULL){ 
            s.push(curr); 
            curr = curr->left; 
        } 
        /* Current must be NULL at this point */
        curr = s.top(); 
        cout<<"Cur= "<<curr->data<<endl;
        s.pop(); 
        if(prev == NULL)
            *head_ref = curr;
        else{
            prev->right = curr;
            curr->left = prev;
        }
        prev = curr;
        curr = curr->right;  
    }
}