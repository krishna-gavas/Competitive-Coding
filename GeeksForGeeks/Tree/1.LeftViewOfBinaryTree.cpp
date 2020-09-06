// Left View of Binary Tree

// Question:
// Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree 
// is visited from Left side. The task is to complete the function leftView(), which accepts root of the 
// tree as argument.

// Left view of following tree is 1 2 4 8.

//           1
//        /     \
//      2        3
//    /     \    /    \
//   4     5   6    7
//    \
//      8

// Your Task:
// You just have to complete the function leftView() that prints the left view. The newline is 
// automatically appended by the driver code.

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
// call leftView(root) function.
// In leftView() create a queue of pair<Node *, int> for each node and its level.
//     push root with level 0 into queue and initialize lev = 0
//     while queue is not empty:
//     make t = queue.front() and check if t.second = lev(i.e print first node of every level) and increment lev
//     check if(t.first->left != NULL) and push t.first->left with level t.second+1, check similarly for t.first->right.

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
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

Node* buildTree(string str){
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    
    Node* root = new Node(stoi(ip[0]));

    queue<Node*> queue;
    queue.push(root);

    int i=1;
    while(!queue.empty() && i < ip.size()){
        Node* currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if(currVal != "N"){
            currNode->left = new Node(stoi(currVal));

            queue.push(currNode->left);
        }
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        if(currVal != "N"){
            currNode->right = new Node(stoi(currVal));

            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

void leftView(Node *root)
{
    if(root == NULL)
        return;

    queue<pair<Node *, int>> q;
    q.push(make_pair(root,0));
    int lev = 0;
    while(q.empty() == false){
        pair<Node *, int> t = q.front();
        if(t.second == lev){
            cout<<t.first->data<<" ";
            lev++;
        }
        if(t.first->left != NULL)
            q.push(make_pair(t.first->left, t.second+1));
        if(t.first->right != NULL)
            q.push(make_pair(t.first->right, t.second+1));
        q.pop();
    }
}

void inOrder(Node *root){
    if(root == NULL)
        return ;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main() {
	int T;
	cin>>T;
    cin.ignore();
	while(T--){
	    string s;
        getline(cin,s);
        Node* root = buildTree(s);
        // inOrder(root);
        // cout<<"\n";
        leftView(root);
        cout<<"\n";
	}
	return 0;

}