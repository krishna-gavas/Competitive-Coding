// Given a binary tree, check whether it is a mirror of itself

// Accept a string s and call buildTree(s) function.
// In buildTree() copy the string elements into a vector.
//     build a queue and push root into it.
//     Access all the vector elements and also check if the queue is not empty:
//     initialize i=1(first element access)
//     For every access make currNode = queue.front() and currVal = ip[i]
//     check if(currVal != "N") and then make currNode->left as currVal and push it to queue and increment i.
//     make currVal = ip[i], check if(currVal != "N") and then make currNode->right as currVal and push it to queue and increment i.
//     finally return root.
// call isSymmetric(root) function: initialize count = 0, create 2 queues q1 and q2 and push root into both queues.
//     for each traversal increment count pop front items as follows node1 = q1.front() and node2 = q2.front() and if node1->data != node2->data return false
//     if (node1->left != NULL && node1->right != NULL) then q1.push(node1->left) and q1.push(node1->right)
//     else if((!node1->left && node2->right) || (node1->left && !node2->right)) then return false.
//     similarly perform above 2 lines for  node2
//     finally if both queues are empty and (count+1) is even then return true else return false


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

bool isSymmetric(struct Node* root){
    if(root==NULL)
        return true;
    int count = 0;
    queue<Node *> q1; 
    queue<Node *> q2;
    q1.push(root); 
    q2.push(root);
    while (q1.empty() == false) 
    { 
        count++;
        Node *node1 = q1.front(); 
        Node *node2 = q2.front();
        if(node1->data != node2->data)
            return false; 
        q1.pop(); 
        q2.pop();
  
        if (node1->left != NULL && node1->right != NULL){
            q1.push(node1->left);
            q1.push(node1->right);
        }
        else if((!node1->left && node2->right) || (node1->left && !node2->right))
            return false;

        if (node2->right != NULL && node2->left != NULL){
            q2.push(node2->right);
            q2.push(node2->left);
        }
        else if((!node1->left && node2->right) || (node1->left && !node2->right))
            return false;
    }
    if(q1.empty() && q2.empty() && (count+1)%2 == 0)
        return true;
    else 
        return false;
}