// Merge K sorted linked lists

// mergeKLists(arr, N): create a maxHeap.
//     for(i=0 to N): make temp = arr[i] and access all the elements of arr[i] and push it to heap.
//     create a head node with data as maxHeap.front() pop the front of heap.
//     while(maxHeap.size() > 0): create temp = new Node(maxHeap.front()) pop maxHeap.front() and do temp->next = head, head = temp;
//     finally return head.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}	
};

void printList(Node *node){
    while(node != NULL){
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<"\n";
} 

Node * mergeKLists(Node *arr[], int N)
{
    // Your code here
    vector<int> maxHeap;
    int flag = 0;
    for(int i=0;i<N;i++){
        Node *temp = arr[i];
        while(temp != NULL){
            if(flag == 0){
                maxHeap.push_back(temp->data);
                make_heap(maxHeap.begin(), maxHeap.end()); 
                temp = temp->next;
                flag = 1;
            }
            else{
                maxHeap.push_back(temp->data);
                push_heap(maxHeap.begin(), maxHeap.end()); 
                temp = temp->next;
            }
        }
    }
    Node *head = new Node(maxHeap.front());
    pop_heap(maxHeap.begin(), maxHeap.end()); 
    maxHeap.pop_back();
    while(maxHeap.size() > 0){
        Node *temp = new Node(maxHeap.front());
        pop_heap(maxHeap.begin(), maxHeap.end()); 
        maxHeap.pop_back();
        temp->next = head;
        head = temp;
    }
    return head;
}

int main() {
	int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        struct Node *arr[N];
        for(int j=0;j<N;j++){
            int n,x;
            cin>>n>>x;
            arr[j] = new Node(x);
            Node *curr = arr[j];
            n--;

            for(int i=0;i<n;i++){
                cin>>x;
                Node *temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }
        Node *res = mergeKLists(arr, N);
        printList(res);
    }   
	return 0;
}