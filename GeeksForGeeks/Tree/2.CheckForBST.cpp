// Check for BST

// define MAX_HEIGHT as 100000
// Accept a string s and call buildTree(s) function.
// In buildTree() copy the string elements into a vector.
//     build a queue and push root into it.
//     Access all the vector elements and also check if the queue is not empty:
//     initialize i=1(first element access)
//     For every access make currNode = queue.front() and currVal = ip[i]
//     check if(currVal != "N") and then make currNode->left as currVal and push it to queue and increment i.
//     make currVal = ip[i], check if(currVal != "N") and then make currNode->right as currVal and push it to queue and increment i.
//     finally return root.
// call isBST(root) function.
// In isBST() if(isBSTUtil(root,INT_MIN,INT_MAX) == 1) return true else false.
// In isBSTUtil() if(node ==  NULL) return 1;
//     check if node->data > min && node->data < max && isBSTUtil(node->left,min,node->data) && isBSTUtil(node->right,node->data,max) 
//     then return 1 else return 0.

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
   int data;
   Node* left;
   Node* right;
};



// Utility function to create a new Tree Node
Node* newNode(int val)
{
   Node* temp = new Node;
   temp->data = val;
   temp->left = NULL;
   temp->right = NULL;

   return temp;
}


bool isBST(struct Node* node);
int isBSTUtil(struct Node* node, int min, int max);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = newNode(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = newNode(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = newNode(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
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
    cout << isBST(root) << endl;
   }
   return 0;
}


int isBSTUtil(struct Node* node,int min, int max){
    if(node ==  NULL)
        return 1;
    if(node->data > min && node->data < max && 
        isBSTUtil(node->left,min,node->data) &&
        isBSTUtil(node->right,node->data,max))
        return 1;
    else 
        return 0;
}

bool isBST(Node* root) {
    if(isBSTUtil(root,INT_MIN,INT_MAX) == 1)
        return true;
    else 
        return false;
}
