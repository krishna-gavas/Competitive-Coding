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
    struct Node* left;
    struct Node* right;
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
vector<int> levelOrder(struct Node* node);

void inOrder(struct Node* node)
{
  if (node == NULL)
    return;

  inOrder(node->left);
  printf("%d ", node->data);

  inOrder(node->right);
}

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


int main()
{
  int t;
  scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
        vector <int> res = levelOrder(root);
        for (int i : res) cout << i << " ";
        cout << endl;
  }
  return 0;
}

vector<int> levelOrder(Node* root)
{
    vector<int> res;
    if(root==NULL)
        return res;
    int level = 0;
    queue<Node *> nodeQueue;
    nodeQueue.push(root);
    
    while (nodeQueue.empty() == false) 
    { 
        // Pop the top item from queue 
        struct Node *node = nodeQueue.front(); 
        res.push_back(node->data);
        nodeQueue.pop(); 
  
        // Enqueue left child and right child
        if (node->left != NULL){
            nodeQueue.push(node->left);
        }
        if (node->right != NULL){
            nodeQueue.push(node->right); 
        }
    }
    return res;
}