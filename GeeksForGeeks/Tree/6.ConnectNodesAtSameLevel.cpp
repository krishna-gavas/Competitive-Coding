// Connect Nodes at Same Level

// Question:
// Given a binary tree, connect the nodes that are at same level. You'll be given an addition nextRight 
// pointer for the same.

// Initially, all the nextRight pointers point to garbage values. Your function should set these pointers 
// to point next right for each node.
//        10                       10 ------> NULL
//       / \                       /      \
//      3   5       =>     3 ------> 5 --------> NULL
//     / \     \               /  \           \
//    4   1   2          4 --> 1 -----> 2 -------> NULL

// Input:
//       10
//     /   \
//    20   30
//   /  \
//  40  60
// Output:
// 10 20 30 40 60
// 40 20 60 10 30

// Your Task:
// You don't have to take input. Complete the function connect() that takes root as parameter and connects 
// the nodes at same level. The printing is done by the driver code.

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
// call connect(p) function
//   Create and empty queue for level order traversal as queue<pair<Node *, int> > nodeQueue; and push root to it.
//   Initialize level = 0.
//   At each traversal level = nodeQueue.front().second; and node = nodeQueue.front().first;
//   if(nodeQueue.front().second == level)
//       node->nextRight = nodeQueue.front().first;
//   else
//       node->nextRight = NULL;
//   push node->left and node->right to nodeQueue



#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

struct Node
{
   int data;
   Node* left;
   Node* right;
   Node* nextRight;
};

Node* newNode(int val)
{
   Node* temp = new Node;
   temp->data = val;
   temp->left = NULL;
   temp->right = NULL;
   temp->nextRight = NULL;

   return temp;
}

void connect(Node *p);

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

void printSpecial(Node *root){
    if(root == NULL)
        return ;

    Node* next_root = NULL;

    while(root != NULL){
        cout<<root->data<<" ";

        if(root->left && (!next_root))
            next_root = root->left;
        else if(root->right && (!next_root))
            next_root = root->right;

        root = root->nextRight;
    }
    printSpecial(next_root);
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
        connect(root);
        printSpecial(root);
        cout<<endl;
        inorder(root);
        cout << endl;
   }
   return 0;
}

void connect(Node *root){
   if (root == NULL)  
        return; 
  
    int level = 0,oldlevel;
    // Create an empty queue for level order tarversal 
    queue<pair<Node *, int> > nodeQueue;
  
    // Enqueue Root and initialize height 
    nodeQueue.push(make_pair(root,level)); 
    root->nextRight = NULL;
  
    while (nodeQueue.empty() == false){ 

        level = nodeQueue.front().second;
        oldlevel = level;

        // Print front of queue and remove it from queue 
        Node *node = nodeQueue.front().first; 
        // cout << node->data << " "; 
        nodeQueue.pop(); 
        if(node == root){
            node->nextRight = NULL;
        }
        else if( !nodeQueue.empty() && nodeQueue.front().second == level)
            node->nextRight = nodeQueue.front().first;
        else
            node->nextRight = NULL;
            
  
        /* Enqueue left child */
        if (node->left) 
            nodeQueue.push(make_pair(node->left,level+1)); 
  
        /*Enqueue right child */
        if (node->right) 
            nodeQueue.push(make_pair(node->right,level+1));  
    }
}