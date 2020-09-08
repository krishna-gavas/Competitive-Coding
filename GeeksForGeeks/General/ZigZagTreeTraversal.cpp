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
    Node* root = new Node(stoi(ip[0]));
        
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
            currNode->left = new Node(stoi(currVal));
                
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
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
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
// Contributed by: Hashit Sidhwa

// } Driver Code Ends


//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return a vector containing the zig zag level order traversal of the given tree
vector <int> zigZagTraversal(Node* root)
{
    vector<int> out;
	if(root==NULL)
        return out;
    int level = 0,oldlevel=0;
    deque<pair<Node *, int> > nodeQueue; 
    nodeQueue.push_back(make_pair(root,level));

    while (nodeQueue.empty() == false) 
    { 
        if(oldlevel%2 == 0)
            level = nodeQueue.front().second;
        else 
            level = nodeQueue.back().second;
        oldlevel = level;

        struct Node *node;
        if(level % 2 == 0){
            node = nodeQueue.front().first; 
            // cout<<node->data<<" ";
            out.push_back(node->data);
            nodeQueue.pop_front(); 
            if (node->left != NULL)
                nodeQueue.push_back(make_pair(node->left,level+1));
            if (node->right != NULL)
                nodeQueue.push_back(make_pair(node->right,level+1)); 
        }
        else{
            node = nodeQueue.back().first; 
            // cout<<node->data<<" ";
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