// Diameter of Binary Tree

// Question:
// Given a Binary Tree, find diameter of it.
// The diameter of a tree is the number of nodes on the longest path between two leaves in the tree. 
// The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest 
// path are shaded (note that there is more than one path in each tree of length nine, but no path longer 
// than nine nodes).

// Input:
//          10
//         /   \
//       20    30
//     /   \ 
//    40   60
// Output: 4

// Your Task:
// You need to complete the function diameter() that takes node as parameter and returns the diameter.

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
// diameter(root): 
//     initialize height = 0 and call ret = findDiameter(root, &height) and return height.
// findDiameter(root, &height): 
//     if (root == NULL) then return 0;
//     Get the heights of left and right subtrees in lh and rh respectively
//     calculate temp as max(LH,RH) + 1 (which is the height upto that node)
//     calculate ans as max(temp,LH+RH+1) (i.e. max of height upto that node and diameter upto that node)
//     if(ans > height) then height = ans
//     return temp

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

int findDiameter(Node *root, int &height){
    if (root == NULL) 
        return 0;
    
    int LH = findDiameter(root->left,height);
    int RH = findDiameter(root->right,height);

    int temp = max(LH,RH) + 1;
    int ans = max(temp,LH+RH+1);
    height = max(height,ans);
    return temp;
}

int diameter(Node *root){
    if(root == NULL)
        return 0;
    int height = 0;
    findDiameter(root,height);
    return height;
}