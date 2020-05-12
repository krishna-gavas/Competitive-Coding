// Level order traversal in spiral form

// Accept a string s and call buildTree(s) function.
// In buildTree() copy the string elements into a vector.
//     build a queue and push root into it.
//     Access all the vector elements and also check if the queue is not empty:
//     initialize i=1(first element access)
//     For every access make currNode = queue.front() and currVal = ip[i]
//     check if(currVal != "N") and then make currNode->left as currVal and push it to queue and increment i.
//     make currVal = ip[i], check if(currVal != "N") and then make currNode->right as currVal and push it to queue and increment i.
//     finally return root.
// call printSpiral(root) function
    // Create a double ended queue(deque) as deque<pair<Node *, int> > nodeQueue; and push root to it.
    // Initialize level = 0.
    // If level is odd: then node = pop_front(), print node->data and then push_back(node->left) and push_back(node->right)
    // If level is even: then node = pop_back(), print node->data and then push_front(node->right) and push_front(node->left)



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

void printSpiral(Node *root);

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
        printSpiral(root);
        cout << endl;
   }
   return 0;
}

void printSpiral(Node *root){
    if(root==NULL)
        return;

    int level = 0,oldlevel;
    deque<pair<Node *, int> > nodeQueue; 
    nodeQueue.push_back(make_pair(root,level));

    while (nodeQueue.empty() == false) 
    { 
        if(oldlevel%2 == 1)
            level = nodeQueue.front().second;
        else 
            level = nodeQueue.back().second;
        oldlevel = level;

        struct Node *node;
        if(level % 2 == 1){
            node = nodeQueue.front().first; 
            cout<<node->data<<" ";
            nodeQueue.pop_front(); 
            if (node->left)
                nodeQueue.push_back(make_pair(node->left,level+1));
            if (node->right)
                nodeQueue.push_back(make_pair(node->right,level+1)); 
        }
        else{
            node = nodeQueue.back().first; 
            cout<<node->data<<" ";
            nodeQueue.pop_back();
            if (node->right)
                nodeQueue.push_front(make_pair(node->right,level+1)); 
            if (node->left)
                nodeQueue.push_front(make_pair(node->left,level+1));
        }
    }
}