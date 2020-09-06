// Count Leaves in Binary Tree

// Question:
// Given a Binary Tree of size N , You have to count leaves in it. For example, there are two leaves in 
// following tree
//         1
//      /      \
//    10      39
//   /
// 5

// Input:
// First line of input contains the number of test cases T. For each test case, there will be only a single line 
// of input which is a string representing the tree as described below: 
// The values in the string are in the order of level order traversal of the tree where, numbers denote node 
// values, and a character “N” denotes NULL child.

// Output:
// For each test case print the count of leaves.


// Your Task:
// You don't have to take input. Complete the function countLeaves() that takes root node of given tree as parameter 
// and returns the count of leaves in tree . The printing is done by the driver code

// Example:
// Input:
// 2
// 3 4 2 
// 4 8 10 7 N 5 1 3 
// Output:
// 2
// 3

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
// call countLeaves(root) function: 
//     if root is NULL return 0, initialize count = 0.
//     create a queue for level order traversing of tree and push root to it.
//     at every iteration make node = q.front() and if node->left and node->right both are null then increment count.
//     if(node->left != NULL) q.push(node->left) and if(node->right != NULL) q.push(node->right).
//     finally return count

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

int countLeaves(Node *root);

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

        cout<<countLeaves(root)<<"\n";
   }
   return 0;
}

int countLeaves(Node *root){
    if(root == NULL)
        return 0;

    queue<Node *> q; 
    int count = 0;
    q.push(root);

    while (q.empty() == false) 
    { 
        Node *node = q.front(); 
  
        if(node->left == NULL && node->right == NULL)
            count++;

        q.pop(); 

        if(node->left != NULL){
            q.push(node->left);
        }

        if(node->right != NULL){
            q.push(node->right);
        }
    }
    return count;
}