// Lowest Common Ancestor in a BST

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