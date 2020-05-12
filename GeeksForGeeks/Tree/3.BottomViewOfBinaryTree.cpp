// Bottom View of Binary Tree

// Accept a string s and call buildTree(s) function.
// In buildTree() copy the string elements into a vector.
//     build a queue and push root into it.
//     Access all the vector elements and also check if the queue is not empty:
//     initialize i=1(first element access)
//     For every access make currNode = queue.front() and currVal = ip[i]
//     check if(currVal != "N") and then make currNode->left as currVal and push it to queue and increment i.
//     make currVal = ip[i], check if(currVal != "N") and then make currNode->right as currVal and push it to queue and increment i.
//     finally return root.
// call bottomView(root) function
//     Create a map where key is the horizontal distance and value is a pair(Node value, Node height). 
//     Perform a iterative pre-order traversal of the tree as follows: 
//     create a stack as follows stack< pair<Node *, pair<int height, int horizontal distance> > > nodeStack;
//     If the current node at a horizontal distance of hd is the first we’ve seen, insert it in the map. 
//     Otherwise, compare the node with the existing one in map and if the height of the new node is greater, update in the Map

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

void bottomView(Node *root);

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
        bottomView(root);
        cout << endl;
   }
   return 0;
}

void bottomView(Node *root){
    if(root==NULL)
        return;
    map<int, pair<int, int> > mp;
    int hd = 0,height = 0;
    mp.insert(make_pair(hd, make_pair(root->data,0)));

    stack< pair<Node *, pair<int, int> > > nodeStack; 
    nodeStack.push(make_pair(root, make_pair(height, hd)));

    while (nodeStack.empty() == false) 
    { 
        // Pop the top item from stack and print it 
        struct Node *node = nodeStack.top().first; 
        height = nodeStack.top().second.first;
        hd = nodeStack.top().second.second;
        // cout<<node->data<<endl;
        nodeStack.pop(); 
  
        // Push right and left children of the popped node to stack 
        if (node->right){
            nodeStack.push(make_pair(node->right, make_pair(height+1, hd+1))); 
            if (mp.find(hd+1) == mp.end())
                mp.insert(make_pair(hd+1, make_pair(node->right->data,height+1)));
            else if(mp[hd+1].second <= height+1)
                mp[hd+1] = make_pair(node->right->data,height+1);
        }
        if (node->left){
            nodeStack.push(make_pair(node->left, make_pair(height+1, hd-1)));
            if (mp.find(hd-1) == mp.end())
                mp.insert(make_pair(hd-1, make_pair(node->left->data,height+1)));
            else if(mp[hd-1].second <= height+1)
                mp[hd-1] = make_pair(node->left->data,height+1);
        }
    }

    map<int, pair<int, int> > ::iterator itr;
    for(itr = mp.begin(); itr != mp.end(); itr++)    
        cout<<itr->second.first<<" ";
}
