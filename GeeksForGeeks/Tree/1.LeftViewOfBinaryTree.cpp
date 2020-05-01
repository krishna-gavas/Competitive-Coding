// Left View of Binary Tree

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
    Node* tempNode = root;
    while(tempNode != NULL){
        if((tempNode->left != NULL && tempNode->left->data == 'N') || (tempNode->left == NULL)){
                cout<<tempNode->data<<" ";
                tempNode = tempNode->right;
                continue;
        }
        cout<<tempNode->data<<" ";
        tempNode = tempNode->left;
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