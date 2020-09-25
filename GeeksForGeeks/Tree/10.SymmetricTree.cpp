// Given a binary tree, check whether it is a mirror of itself

// Question:
// Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror 
// image of itself or not.

// Input:
//          5
//        /   \
//       1     1
//      /       \
//     2         2
// Output: True

// Input:
//          5
//        /   \
//       10     10
//      /  \     \
//     20  20     30
// Output: False

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isMirror() which 
// takes the root of the Binary Tree as its input and returns True if the given Binary Tree is a same as 
// the Mirror image of itself. Else, it returns False.

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

// isSymmetric(): if(root == NULL) return true 
//     return check(root->left,root->right)

// check(leftSub,rightSub): if(both leftSub and rightSub are NULL) return true 
//     if(both leftSub and rightSub are not NULL)
//         if(leftSub->data == rightSub->data && check(leftSub->left,rightSub->right) &&
//             check(leftSub->right,rightSub->left)) then return true 
//     return false;

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

bool isSymmetric(struct Node* root);

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

        if(isSymmetric(root))
            cout<<"True"<<endl;
        else 
            cout<<"False"<<endl;
   }
   return 0;
}

bool check(struct Node* leftSub, struct Node* rightSub){
    if(leftSub == NULL && rightSub == NULL)
        return true;
    if(leftSub != NULL && rightSub != NULL){
        if(leftSub->data == rightSub->data && check(leftSub->left,rightSub->right) && check(leftSub->right,rightSub->left))
            return true;
    }
    return false;
}

bool isSymmetric(struct Node* root){
    if(root==NULL)
        return true;
    return check(root->left,root->right);
}