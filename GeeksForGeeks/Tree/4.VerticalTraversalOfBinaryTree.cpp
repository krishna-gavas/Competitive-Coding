// Vertical Traversal of Binary Tree

// Accept a string s and call buildTree(s) function.
// In buildTree() copy the string elements into a vector.
//     build a queue and push root into it.
//     Access all the vector elements and also check if the queue is not empty:
//     initialize i=1(first element access)
//     For every access make currNode = queue.front() and currVal = ip[i]
//     check if(currVal != "N") and then make currNode->left as currVal and push it to queue and increment i.
//     make currVal = ip[i], check if(currVal != "N") and then make currNode->right as currVal and push it to queue and increment i.
//     finally return root.
// call verticalOrder(root) function
//     Create a multimap where key is the horizontal distance and value is a pair(Node value, Node height).
//     Perform a iterative level-order(BFS) traversal of the tree as follows:
//     create a queue as follows queue< pair<Node *, pair<int height, int horizontal distance> > > queueStack;
//     pop the front of the queue as node, Insert left and right child of node in queue and multimap;

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
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

void verticalOrder(Node *root);

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
        verticalOrder(root);
        cout << endl;
   }
   return 0;
}

void verticalOrder(Node *root){
    if(root==NULL)
        return;
    multimap<int, pair<int, int> > mp;
    int hd = 0,height = 0;
    mp.insert(make_pair(hd, make_pair(root->data,0)));

    queue< pair<Node *, pair<int, int> > > nodeQueue; 
    nodeQueue.push(make_pair(root, make_pair(height, hd)));

    while (nodeQueue.empty() == false) 
    { 
        // Pop the top item from queue 
        struct Node *node = nodeQueue.front().first; 
        height = nodeQueue.front().second.first;
        hd = nodeQueue.front().second.second;
        // cout<<node->data<<endl;
        nodeQueue.pop(); 
  
        // Enqueue left child and right child
        if (node->left){
            nodeQueue.push(make_pair(node->left, make_pair(height+1, hd-1)));
            mp.insert(make_pair(hd-1, make_pair(node->left->data,height+1)));
        }
        if (node->right){
            nodeQueue.push(make_pair(node->right, make_pair(height+1, hd+1))); 
            mp.insert(make_pair(hd+1, make_pair(node->right->data,height+1)));
        }
    }

    map<int, pair<int, int> > ::iterator itr;
    for(itr = mp.begin(); itr != mp.end(); itr++)    
        cout<<itr->second.first<<" ";
}