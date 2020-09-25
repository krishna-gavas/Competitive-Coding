// ZigZag Tree Traversal


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

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

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

vector <int> zigZagTraversal(Node* root);

int main()
{
    int t;
    scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
        vector <int> res = zigZagTraversal(root);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout<<endl;
  }
  return 0;
}

vector <int> zigZagTraversal(Node* root)
{
    vector<int> out;
	if(root==NULL)
        return out;
    int level = 0,oldlevel=0;
    deque<pair<Node *, int> > nodeQueue; 
    nodeQueue.push_back(make_pair(root,level));

    while (!nodeQueue.empty()){ 
        if(oldlevel%2 == 0)
            level = nodeQueue.front().second;
        else 
            level = nodeQueue.back().second;
        oldlevel = level;

        struct Node *node;
        if(level % 2 == 0){
            node = nodeQueue.front().first; 
            out.push_back(node->data);
            nodeQueue.pop_front(); 
            if (node->left != NULL)
                nodeQueue.push_back(make_pair(node->left,level+1));
            if (node->right != NULL)
                nodeQueue.push_back(make_pair(node->right,level+1)); 
        }
        else{
            node = nodeQueue.back().first;
            out.push_back(node->data);
            nodeQueue.pop_back();
            if (node->right != NULL)
                nodeQueue.push_front(make_pair(node->right,level+1)); 
            if (node->left != NULL)
                nodeQueue.push_front(make_pair(node->left,level+1));
        }
    }
    return out;
}