#include<iostream>
using namespace std;

struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* getNewNode(int data){
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

BstNode* Insert(BstNode* root, int data){
    if(root == NULL)
        root = getNewNode(data);
    else if(data <= root->data)
        root->left = Insert(root->left,data);
    else
        root->right = Insert(root->right,data);

    return root;
}

BstNode* FindMinNode(BstNode* root){
    if(root == NULL){
        cout<<"Error: Tree is empty"<<endl;
        return root;
    }

    while(root->left != NULL)
        root = root->left;

    return root;
    
}

BstNode* Delete(BstNode* root, int data){
    if(root == NULL)
        return root;
    else if(data < root->data)
        root->left = Delete(root->left,data);
    else if(data > root->data)
        root->right = Delete(root->right,data);
    else{
        //case1: No child
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        //case2: 1 child
        else if(root->left == NULL){
            struct BstNode* temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL){
            struct BstNode* temp = root;
            root = root->left;
            free(temp);
        }
        //case3: 2 children
        else{
            struct BstNode* temp = FindMinNode(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }
    }
    return root;
}

bool Search(BstNode* root, int data){
    if(root == NULL)
        return false;
    else if(root->data == data)
        return true;
    else if(data <= root->data)
        return Search(root->left,data);
    else
        return Search(root->right,data);

}

int FindMin(BstNode* root){
    if(root == NULL){
        cout<<"Error: Tree is empty"<<endl;
        return -1;
    }

    while(root->left != NULL)
        root = root->left;

    return root->data;
    
}

int FindMax(BstNode* root){
    if(root == NULL){
        cout<<"Error: Tree is empty"<<endl;
        return -1;
    }
    
    while(root->right != NULL)
        root = root->right;

    return root->data;
    
}

int Max(int a,int b){
    if(a > b)
        return a;
    else
        return b;
}

int FindHeight(BstNode* root){
    if(root == NULL){
        cout<<"Error: Tree is empty"<<endl;
        return -1;
    }
    int leftHeight,rightHeight;
    leftHeight = FindHeight(root->left);
    rightHeight = FindHeight(root->right);

    return Max(leftHeight,rightHeight)+1;
}

void Inorder(BstNode* root){
    if(root == NULL)
        return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

int main(){
    BstNode* root = NULL;
    int choice,ele,max,min,height,flag=0;
    cout<<" 1. Insert\n 2. Delete\n 3. Search\n 4. Find Minimum\n 5. Find Maximum\n 6. Find Height\n 7. Traversal\n 8. Exit\n";
    
    while(flag == 0){
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            
            case 1: cout<<"Enter the Element to be Inserted: ";
                    cin>>ele;
                    root = Insert(root,ele);
                    break;

            case 2: cout<<"Enter the Element to be Deleted: ";
                    cin>>ele;
                    root = Delete(root,ele);
                    break;

            case 3: cout<<"Enter the number to be searched\n";
                    cin>>ele;
                    if(Search(root,ele)==true)
                        cout<<"Found"<<endl;
                    else
                        cout<<"Not Found"<<endl;       
                    break;

            case 4: min = FindMin(root);
                    cout<<"Minimum element is :"<<min<<endl;
                    break;

            case 5: max = FindMax(root);
                    cout<<"Maximum element is :"<<max<<endl;
                    break;

            case 6: height = FindHeight(root);
                    cout<<"Height of the Tree is :"<<height<<endl;
                    break;

            case 7: cout<<"Inorder Traversal is as follows: "<<endl;
                    Inorder(root);
                    cout<<endl;
                    break;

            case 8: flag = 1;
                    break;
        }
    }
    

    return 0;
}