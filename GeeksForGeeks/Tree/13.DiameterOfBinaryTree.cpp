// Diameter of Binary Tree

// Accept a string s and call buildTree(s) function.
// In buildTree() copy the string elements into a vector.
//     build a queue and push root into it.
//     Access all the vector elements and also check if the queue is not empty:
//     initialize i=1(first element access)
//     For every access make currNode = queue.front() and currVal = ip[i]
//     check if(currVal != "N") and then make currNode->left as currVal and push it to queue and increment i.
//     make currVal = ip[i], check if(currVal != "N") and then make currNode->right as currVal and push it to queue and increment i.
//     finally return root.
// call diameter(root) function: initialize height = 0 and call ret = diameterOpt(root, &height) and return ret.
// diameterOpt(root, &height): initialize lh,rl,ldiameter and rdiameter to 0.
//     if (root == NULL) then *height = 0 and return 0;
//     Get the heights of left and right subtrees in lh and rh and store the returned values in ldiameter and ldiameter
//     calculate height as *height = max(lh, rh) + 1.
//     finally return max(lh + rh + 1, max(ldiameter, rdiameter))

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

int diameter(Node *root);

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

        cout<<diameter(root)<<"\n";
   }
   return 0;
}

int diameterOpt(Node *root, int *height){
    /* lh --> Height of left subtree 
     rh --> Height of right subtree */
  int lh = 0, rh = 0; 
   
  /* ldiameter  --> diameter of left subtree 
     rdiameter  --> Diameter of right subtree */
  int ldiameter = 0, rdiameter = 0; 
   
  if (root == NULL) 
  { 
    *height = 0; 
     return 0; /* diameter is also 0 */
  } 
   
  /* Get the heights of left and right subtrees in lh and rh 
    And store the returned values in ldiameter and ldiameter */
  ldiameter = diameterOpt(root->left, &lh); 
  rdiameter = diameterOpt(root->right, &rh); 
   
  /* Height of current node is max of heights of left and 
     right subtrees plus 1*/
  *height = max(lh, rh) + 1; 
   
  return max(lh + rh + 1, max(ldiameter, rdiameter));
}

int diameter(Node *root){
    if(root == NULL)
        return 0;
    int height = 0;
    int ret = diameterOpt(root, &height);
    return ret;
}