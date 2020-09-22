// Maximum path sum from any node to any other node

#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<string.h>
#include<sstream>

using namespace std;

struct Node{
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
    for(string str; iss>>str;)
        ip.push_back(str);

    Node* root = new Node(stoi(ip[0]));

    queue<Node*> q;
    q.push(root);
    int i=1;
    while(!q.empty() && i<ip.size()){
        Node* curNode = q.front();
        q.pop();
        string curVal = ip[i];
        if(curVal != "N"){
            curNode->left = new Node(stoi(curVal));
            q.push(curNode->left);
        }
        i++;
        if(i >= ip.size())
            break;

        curVal = ip[i];
        if(curVal != "N"){
            curNode->right = new Node(stoi(curVal));
            q.push(curNode->right);
        }
        i++;
    }
    return root;
}

int maxPathSum(struct Node* root,int &res){
    if(root == NULL)
        return 0;
    int L = maxPathSum(root->left, res);
    int R = maxPathSum(root->right, res);
    int temp = max(max(L,R)+root->data, root->data);

    int ans = max(temp, L+R+root->data);

    res = max(res,ans);

    return temp;
}

int main(){
    int t;
    string tc;
    getline(cin,tc);
    t = stoi(tc);
    while(t--){
        string str;
        getline(cin,str);
        Node* root = buildTree(str);
        int res=0;
        maxPathSum(root,res);
        cout<<res<<"\n";
    }
}
