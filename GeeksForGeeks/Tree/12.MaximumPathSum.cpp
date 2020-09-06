// Maximum Path Sum

// Question:
// Given a binary tree in which each node element contains a number. Find the maximum possible sum from one 
// leaf node to another.

// Input :      
//            3                               
//          /    \                          
//        4       5                     
//       /  \      
//     -10   4                          

// Output: 16

// Input :    
//             -15                               
//          /      \                          
//         5         6                      
//       /  \       / \
//     -8    1     3   9
//    /  \              \
//   2   -3              0
//                      / \
//                     4  -1
//                        /
//                      10  

// Output :  27

// Your Task:  
// You dont need to read input or print anything. Complete the function maxPathSum() which takes root node as 
// input parameter and returns the maximum sum between 2 leaf nodes.

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
// call maxPathSum(root) function: call pathSum(root) function and return second value of the pair returned by pathSum(root) function.
// pathSum(root) function: this function returns a pair<root_to_leaf_path_sum, leaf_to_leaf_path_sum>
//     if root is NULL return <0,0>
//     if left and right child of root are NULL then return <root->data, INT_MIN>
//     if left child is NULL and ltolPath for right child is INT_MIN return <root->data + pathSum(root->right).first, INT_MIN> 
//     if right child is NULL nd ltolPath for left child is INT_MIN return <root->data + pathSum(root->left).first, INT_MIN>
//     lsum1 and lsum2 are rtplPath and ltolPath for left child similarly rsum1 and rsum2 for right child
//     if(lsum1 > rsum1) then sum1 = lsum1 + root->data else sum1 = rsum1 + root->data
//      if(lsum2 > rsum2){ if(lsum1+rsum1+root->data > lsum2) then sum2 = lsum1+rsum1+root->data else sum2 = lsum2 }
//      else{ if(lsum1+rsum1+root->data > rsum2) then sum2 = lsum1+rsum1+root->data  else sum2 = rsum2 }
//      finally return <sum1, sum2>

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

int maxPathSum(struct Node* root);

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

        cout<<maxPathSum(root)<<"\n";
   }
   return 0;
}

pair<int, int>  pathSum(Node *root){
    if(root == NULL)
        return make_pair(0,0);

    if(root->left == NULL && root->right == NULL)
        return make_pair(root->data, INT_MIN);

    if(root->left == NULL && pathSum(root->right).second == INT_MIN) 
        return make_pair(root->data + pathSum(root->right).first, INT_MIN);
    if(root->right == NULL && pathSum(root->left).second == INT_MIN)
        return make_pair(root->data + pathSum(root->left).first, INT_MIN);

    pair<int, int> lsum = pathSum(root->left);
    pair<int, int> rsum = pathSum(root->right);
    int lsum1 = lsum.first;
    int rsum1 = rsum.first;
    int lsum2 = lsum.second;
    int rsum2 = rsum.second;

    // cout<<root->data<<" ";
    int sum1,sum2;
    if(lsum1 > rsum1){
            sum1 = lsum1 + root->data ;
    }
    else{
            sum1 = rsum1 + root->data ;
    }

    if(lsum2 > rsum2){
        if(lsum1+rsum1+root->data > lsum2)
            sum2 = lsum1+rsum1+root->data;
        else
            sum2 = lsum2;
    }
    else{
        if(lsum1+rsum1+root->data > rsum2)
            sum2 = lsum1+rsum1+root->data;
        else
            sum2 = rsum2;
    }

    return make_pair(sum1, sum2);
}

int maxPathSum(struct Node* root){
    if(root==NULL)
        return 0;
    
    int sum = pathSum(root).second;

    return sum;
    
}