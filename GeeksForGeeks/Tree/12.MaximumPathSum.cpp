// Maximum Path Sum

// Question:
// Given a binary tree in which each node element contains a number. Find the maximum possible sum from one 
// leaf node to another.

// Input :      
//            3                               
//          /    \                          
//        4       5                     
//       /  \      
//     -10   4                          

// Output: 16

// Your Task:  
// You dont need to read input or print anything. Complete the function maxPathSum() which takes root node as 
// input parameter and returns the maximum sum between 2 leaf nodes.

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

// maxPathSum(): if(root == NULL) return 0
//     initialize path to INT_MIN and call maxPathSumLtoL(root,path)
//     return path

// maxPathSumLtoL: if(root == NULL) return 0
//     if it is a leaf node then return its value 
//     Lpath = maxPathSumLtoL(root->left, path) and Rpath = maxPathSumLtoL(root->right, path)
//     store maxpath from single leaf node to current node in temp variable 
//     if(current node has both left and right children) then 
//         path = max(path, Lpath + Rpath + root->data) and return temp 
//     if current node doesn't has right child then return root->data + Lpath
//     else return root->data + Rpath


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
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

int maxPathSum(struct Node* root);

Node* buildTree(string str)
{
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   Node* root = new Node(stoi(ip[0]));

   queue<Node*> queue;
   queue.push(root);

   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       Node* currNode = queue.front();
       queue.pop();

       string currVal = ip[i];

       if(currVal != "N") {
           currNode->left = new Node(stoi(currVal));
           queue.push(currNode->left);
       }
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       if(currVal != "N") {
           currNode->right = new Node(stoi(currVal));
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

        cout<<maxPathSum(root)<<"\n";
   }
   return 0;
}

int maxPathSumLtoL(struct Node* root, int &path){
    if(root==NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return root->data;
    int Lpath = maxPathSumLtoL(root->left, path);
    int Rpath = maxPathSumLtoL(root->right, path);

    int temp = max(Lpath,Rpath) + root->data;

    if(root->left != NULL && root->right != NULL){
        path = max(path, Lpath + Rpath + root->data);
        return temp;
    }
    if(root->left != NULL)
        return root->data + Lpath;
    else 
        return root->data + Rpath;
}

int maxPathSum(struct Node* root){
    if(root==NULL)
        return 0;
    int path = INT_MIN;
    maxPathSumLtoL(root,path);

    return path;
}