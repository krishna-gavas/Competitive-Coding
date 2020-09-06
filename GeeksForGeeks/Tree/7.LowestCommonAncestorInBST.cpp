// Lowest Common Ancestor in a BST

// Question:
// Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors 
// of the two nodes in the BST.

// Input:
//               5
//            /    \
//          4       6
//         /         \
//        3           7
//                     \
//                      8
// n1 = 7, n2 = 8
// Output: 7

// Input:
//      2
//    /   \
//   1     3
// n1 = 1, n2 = 3
// Output: 2

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function LCA() which takes 
// the root Node of the BST and two integer values n1 and n2 as inputs and returns the Lowest Common Ancestor 
// of the Nodes with values n1 and n2 in the given BST.

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
// call LCA(root, n1, n2) function
//     if n1 and n2 are both less than root->data then return LCA(root->left,n1,n2)
//     if n1 and n2 are both greater than root->data then return LCA(root->right,n1,n2)
//     finally return root



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

Node* LCA(Node *root, int n1, int n2);

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
        int l,h;
        getline(cin, s);
        cin>>l;
        cin>>h;
        Node* root = buildTree(s);
        cout <<LCA(root, l, h)->data<< endl;
   }
   return 0;
}

Node* LCA(Node *root, int n1, int n2){
    if(root==NULL)
        return NULL;

    if(n1 < root->data && n2 < root->data)
        return LCA(root->left,n1,n2);
    
    if(n1 > root->data && n2 > root->data)
        return LCA(root->right,n1,n2);

    return root;
}