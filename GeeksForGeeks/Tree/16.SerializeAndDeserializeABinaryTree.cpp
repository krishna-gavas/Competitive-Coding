// Serialize and Deserialize a Binary Tree

// Accept a string s and call buildTree(s) function.
// In buildTree() copy the string elements into a vector.
//     build a queue and push root into it.
//     Access all the vector elements and also check if the queue is not empty:
//     initialize i=1(first element access)
//     For every access make currNode = queue.front() and currVal = ip[i]
//     check if(currVal != "N") and then make currNode->left as currVal and push it to queue and increment i.
//     make currVal = ip[i], check if(currVal != "N") and then make currNode->right as currVal and push it to queue and increment i.
//     finally return root.
// Create a vector A and call serialize(root, A)  create a node as getRoot = deSerialize(A) and then call inorder(getRoot).
// serialize(root, A): create a queue for level order traversal and push root to it.
//     create a temp node with value -1 which is used to replace NULL.
//     for each traversal node = q.front() , A.push_back(node->data) if(node->data == -1) then continue.
//     if(node->left != NULL) then q.push(node->left) else q.push(temp).
//     if(node->right != NULL) then q.push(node->right) else q.push(temp).
// deSerialize(A): similar to bulid tree function except
//     create a queue and insert A[0] into it as root node.
//     check if currVal != -1 instead of currVal != 'N'

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
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
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

void serialize(Node *root,vector<int> &A)
{
    if(root == NULL)
        return ;

    queue<Node *> q; 
    q.push(root);
    Node *temp = new Node(-1);
    while (q.empty() == false){ 
        Node *node = q.front(); 
        A.push_back(node->data);
        q.pop(); 
        if(node->data == -1)
            continue;

        if(node->left != NULL)
            q.push(node->left);
        else 
            q.push(temp);

        if(node->right != NULL)
            q.push(node->right);
        else 
            q.push(temp);
    }
}

Node * deSerialize(vector<int> &A)
{
    if(A.size() == 0)
        return NULL;

    Node* root = new Node(A[0]);

    queue<Node*> queue;
    queue.push(root);

    int i = 1;
    while(!queue.empty() && i < A.size()) {

        Node* currNode = queue.front();
        queue.pop();

        int currVal = A[i];

        if(currVal != -1) {
            currNode->left = new Node(currVal);
            queue.push(currNode->left);
        }
        i++;
        if(i >= A.size())
            break;
        currVal = A[i];

        if(currVal != -1) {
            currNode->right = new Node(currVal);
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder(Node *root){
    if(root == NULL)
        return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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

        vector<int> A;
        serialize(root, A);
        // for(int i=0;i<A.size();i++)
        //     cout<<A[i]<<" ";
        // cout<<endl;
        Node *getRoot = deSerialize(A);
        inorder(getRoot);
        cout<<"\n";
   }
   return 0;
}
