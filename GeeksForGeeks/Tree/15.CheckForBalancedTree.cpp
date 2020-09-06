// Check if given Binary Tree is Height Balanced or Not

// Question:
// Given a binary tree, find if it is height balanced or not. 
// A tree is height balanced if difference between heights of left and right subtrees is not more than one 
// for all nodes of tree. 

// Input:
//        10
//      /   \
//     20   30 
//   /   \
//  40   60
// Output: 1

// Your Task:
// You don't need to take input. Just complete the function isBalanced() that takes root node as parameter 
// and returns true, if the tree is balanced else returns false.

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
// call isBalanced(root) function: if root is NULL return true
//     leftHeight = height(root->left) and if leftHeight is -1 return false and similar for root->right.
//     if(abs(leftHeight - rightHeight) > 1) return false else true.
// height(root): if root is NULL return 0.
//     leftHeight = height(root->left) and if(leftHeight == -1) return -1 and similar for root->right.
//     if(abs(leftHeight - rightHeight) > 1) return -1.
//     finally return max(leftHeight,rightHeight)+1.

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <sstream>
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

bool isBalanced(Node *root);

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

        cout<<isBalanced(root)<<"\n";
   }
   return 0;
}

int height(struct Node* root){
    if(root==NULL)
        return 0;
    int leftHeight = height(root->left);
    if(leftHeight == -1)
        return -1;
    int rightHeight = height(root->right);
    if(rightHeight == -1)
        return -1;

    if(abs(leftHeight - rightHeight) > 1)
        return -1;
    int ret =  max(leftHeight,rightHeight);
    return ret+1;
}

bool isBalanced(Node *root){
    if(root==NULL)
        return true;

    int leftHeight = height(root->left);
    if(leftHeight == -1)
        return false;

    int rightHeight = height(root->right);
    if(rightHeight == -1)
        return false;

    if(abs(leftHeight - rightHeight) > 1)
        return false;
    else 
        return true;
}