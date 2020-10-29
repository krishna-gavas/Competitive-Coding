// Binary Heap Operations

// Question:
// A binary heap is a Binary Tree with the following properties:
// 1) It’s a complete tree (All levels are completely filled except possibly the last level and the last level has all 
// keys as left as possible). This property of Binary Heap makes them suitable to be stored in an array.
// 2) A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at the root must be minimum among all 
// keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary 
// Heap is similar to MinHeap.
// You are given an empty Binary Min Heap and some queries and your task is to implement the three methods insertKey,  
// deleteKey,  and extractMin on the Binary Min Heap and call them as per the query given below:
// 1) 1  x  (a query of this type means to insert an element in the min-heap with value x )
// 2) 2  x  (a query of this type means to remove an element at position x from the min-heap)
// 3) 3  (a query like this removes the min element from the min-heap and prints it ).

// Input:
// Q = 7
// Queries:
// insertKey(4)
// insertKey(2)
// extractMin()
// insertKey(6)
// deleteKey(0)
// extractMin()
// extractMin()
// Output: 2 6 - 1

// Your Task:
// You are required to complete the 3 methods insertKey() which take one argument the value to be inserted, deleteKey() 
// which takes one argument the position from where the element is to be deleted and extractMin() which returns the 
// minimum element in the heap(-1 if the heap is empty)

// Solution:
// insertKey(k): 
//     if(heap_size < capacity) then pos = heap_size and insert k into harr[pos], increment heapsize and ppos = parent(pos).
//         while(harr[ppos] > harr[pos]): swap(harr[pos], harr[ppos]), pos = ppos and ppos = parent(pos).
// extractMin():
//     if(heap_size <= 0) return -1
//     if(heap_size == 1) then heap_size-- and return harr[0]
//     root = harr[0], harr[0] = harr[heap_size - 1], decrement heap_size call MinHeapify(0) and return root.
// deleteKey(i): 
//     if(i < heap_size) then call decreaseKey(i, INT_MIN) and then call extractMin()


#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

struct MinHeap
{
    int *harr;
    int capacity, heap_size;
    MinHeap(int cap) {
        heap_size = 0; 
        capacity = cap; 
        harr = new int[cap];
    }

    ~MinHeap(){
        delete[] harr;
    }

    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return (2*i + 1);
    }
    int right(int i){
        return (2*i + 2);
    }
    void MinHeapify(int);
    int extractMin();
    void decreaseKey(int i, int new_val);
    void deleteKey(int i);
    void insertKey(int k);
};
void printArray(int arr[], int size){
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

int main() {
	int T;
    cin>>T;
    while(T--){
        ll a;
        cin>>a;
        MinHeap h(a);
        for(ll i=0;i<a;i++){
            int c,n;
            cin>>c;
            if(c == 1){
                cin>>n;
                h.insertKey(n);
            }
            if(c == 2){
                cin>>n;
                h.deleteKey(n);
            }
            if(c == 3)
                cout<< h.extractMin()<<endl;;
        printArray(h.harr, h.heap_size);
        cout<<endl;
        }
        cout<<endl;
        h.harr = NULL;
    }
    return 0;
}

/* Removes min element from min heap and returns it */
int MinHeap::extractMin() {
    // Your code here
    if(heap_size <= 0)
        return -1;
    if(heap_size == 1){
        heap_size--;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);
    return root;
}

/* Removes element from position x in the min heap  */
void MinHeap::deleteKey(int i) {
    // Your code here
    if(i < heap_size){
        decreaseKey(i, INT_MIN);
        extractMin();
    }
}

/* Inserts an element at position x into the min heap*/
void MinHeap::insertKey(int k) {
    // Your code here
    if(heap_size < capacity){
        int pos = heap_size;
        harr[pos] = k;
        heap_size++;
        int ppos = parent(pos);
        while(harr[ppos] > harr[pos]){
            swap(harr[pos], harr[ppos]);
            pos = ppos;
            ppos = parent(pos);
        }
    }
}

// Decrease Key operation, helps in deleting key from heap
void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) 
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) 
        smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}