// Minimize the sum of product


#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

map<char, string> codes;
map<char, int> freq;

struct MinHeapNode{
    char data;
    int freq;
    MinHeapNode *left,*right;
    MinHeapNode(char data, int freq){
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare{
    bool operator()(MinHeapNode* l, MinHeapNode* r){
        return (l->freq > r->freq);
    }
};

void printCodes(struct MinHeapNode* root, string str){
    if(!root)
        return;
    if(root->data != '$')
        cout<<root->data<<": "<<str<<"\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void storeCodes(struct MinHeapNode* root, string str){
    if(root == NULL)
        return;
    if(root->data != '$')
        codes[root->data] = str;
    storeCodes(root->left, str + "0");
    storeCodes(root->right, str + "1");
}

priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
void HuffmanCodes(int size){
    struct MinHeapNode *left, *right, *top;
    for(map<char, int> :: iterator v=freq.begin(); v != freq.end(); v++)
        minHeap.push(new MinHeapNode(v->first, v->second));
    while(minHeap.size() != 1){
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    storeCodes(minHeap.top(), "");
}

void calcFreq(string str, int n){
    for(int i=0; i<str.size(); i++)
        freq[str[i]]++;
}


// Complete the function below
string decode_file(struct MinHeapNode* root, string s)
{
//add code here.
    return "Krish";
}

int main() {
    int T;
    cin>>T;
    while(T--){
        codes.clear();
        freq.clear();
        minHeap = priority_queue<MinHeapNode*, vector<MinHeapNode*> , compare>();
        string str;
        cin>>str;
        string encodedString, decodedString;
        calcFreq(str, str.length());
        HuffmanCodes(str.length());

        for(auto i: str)
            encodedString += codes[i];

        decodedString = decode_file(minHeap.top(), encodedString);
        cout<<decodedString<<endl;
    }
    return 0;
}

