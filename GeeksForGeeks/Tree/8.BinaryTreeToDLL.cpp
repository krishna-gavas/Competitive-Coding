// Binary Tree to DLL

// Accept a string s and call buildTree(s) function.
// In buildTree() copy the string elements into a vector.
//     build a queue and push root into it.
//     Access all the vector elements and also check if the queue is not empty:
//     initialize i=1(first element access)
//     For every access make currNode = queue.front() and currVal = ip[i]
//     check if(currVal != "N") and then make currNode->left as currVal and push it to queue and increment i.
//     make currVal = ip[i], check if(currVal != "N") and then make currNode->right as currVal and push it to queue and increment i.
//     finally return root.
// call bToDLL(root, &head) function to make a linkedList of a Binary tree with left as prev and right as next:
//    Create an empty stack S and Initialize curr = root.
//    Push the curr to S and set curr = curr->left until curr is NULL.
//    step: If current is NULL and stack is not empty then Pop the top item from stack, curr = S.top() and set prev->right = curr and curr->left = prev.
//    set prev = curr and curr = curr->right and then go to step
// call printList(head) which prints linked list in forward and reverse direction


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
    Node *curr = root, *prev; 
    int flag = 0;
  
    while (curr != NULL || s.empty() == false) 
    { 
        /* Reach the left most Node of the 
           curr Node */
        while (curr !=  NULL) 
        { 
            /* place pointer to a tree node on 
               the stack before traversing 
              the node's left subtree */
            s.push(curr); 
            curr = curr->left; 
        } 
  
        /* Current must be NULL at this point */
        curr = s.top(); 
        s.pop(); 
        if(flag == 0){
            *head_ref = curr;
            flag = 1;
        }
        else{
            prev->right = curr;
            curr->left = prev;
        }
  
        // cout << curr->data << " "; 
  
        /* we have visited the node and its 
           left subtree.  Now, it's right 
           subtree's turn */
        prev = curr;
        curr = curr->right; 
  
    }
}