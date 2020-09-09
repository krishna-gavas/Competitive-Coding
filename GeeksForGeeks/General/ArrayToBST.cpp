#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

void PreOrder(Node* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

Node* ArrayToBST(int A[], int L, int R){
    if(L > R)
        return NULL;
    int mid = (L+R)/2;
    Node* root = newNode(A[mid]);
    cout<<root->data<<" ";
    root->left = ArrayToBST(A,L,mid-1);
    root->left = ArrayToBST(A,mid+1,R);
    return root;
}

int main() {
   int t;
   cin>>t;
   while(t--)
   {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        Node* root = ArrayToBST(A,0,N-1);
        // PreOrder(root);
        cout<<"\n";
   }
   return 0;
}