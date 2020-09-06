// Determine if Two Trees are Identical

// Question:
// Given two binary trees, the task is to find if both of them are identical or not. 

// Input:
//      1          1
//    /   \      /   \
//   2     3    2     3
// Output: Yes

// Input:
//     1       1
//   /  \     /  \
//  2    3   3    2
// Output: No

// Your task:
// Since this is a functional problem you don't have to worry about input, you just have to complete the 
// function isIdentical() that takes two roots as parameters and returns true or false. The printing is 
// done by the driver code.

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
// call isIdentical(root1, root2) function: if root1 and root2 are both NULL return true.
//     create 2 queues q1 and q2 and push root1 and root2 into them respectively for level order traversal.
//     for each traversal pop front items as follows node1 = q1.front() and node2 = q2.front() and if node1->data != node2->data return false
//     if(node1->left != NULL && node2->left != NULL) then q1.push(node1->left) and q2.push(node2->left) 
//     else if(node1->left != NULL || node2->left != NULL) return false
//     similarly perform above 2 lines for right node
//     finally if both queues are empty return true else return false


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

bool isIdentical(Node *r1, Node *r2);

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
        string str1, str2; 
        getline(cin, str1);
        Node* rootA = buildTree(str1);
        getline(cin, str2);
        Node* rootB = buildTree(str2);
        if(isIdentical(rootA, rootB)){
            cout<<"Yes \n";
        }
        else {
            cout<<"No \n";
        }
   }
   return 0;
}

bool isIdentical(Node *r1, Node *r2){
    if(r1==NULL && r2==NULL)
        return true;

    queue<Node *> q1, q2; 
  
    q1.push(r1); 
    q2.push(r2);

    while (q1.empty() == false && q2.empty() == false) 
    { 
        // Print front of queue and remove it from queue 
        Node *node1 = q1.front(); 
        Node *node2 = q2.front();
  
        if(node1->data != node2->data)
            return false;

        q1.pop(); 
        q2.pop();

        if(node1->left != NULL && node2->left != NULL){
            q1.push(node1->left);
            q2.push(node2->left);
        }
        else if(node1->left != NULL || node2->left != NULL)
            return false;

        if(node1->right != NULL && node2->right != NULL){
            q1.push(node1->right);
            q2.push(node2->right);
        }
        else if(node1->right != NULL || node2->right != NULL)
            return false;

    }
    if(q1.empty() && q2.empty())
        return true;
    else 
        return false;
}