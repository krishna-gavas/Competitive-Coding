// Height of Binary Tree

// Question:
// Given a binary tree, find its height.

// Input:
//   2
//    \
//     1
//    /
//  3
// Output: 3

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function height() that 
// takes root Node of the Tree as input and returns the Height of the Tree. If the Tree is empty, return 0. 

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
// call height(root) function: if root is NULL return 0.
//     find leftHeight = height(root->left) and rightHeight = height(root->right)
//     return maximum(leftHeight,rightHeight) + 1.


#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
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

int height(struct Node* root);

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
        string s; 
        getline(cin, s);
        Node* root = buildTree(s);

        cout<<height(root)<<endl;
   }
   return 0;
}

int height(struct Node* root){
    if(root==NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int ret =  max(leftHeight,rightHeight);
    return ret+1;
}