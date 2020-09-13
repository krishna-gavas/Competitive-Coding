// LRU Cache(SEGMENTATION FAULT)

// Question:
// The task is to design and implement methods of an LRU cache. The class has two methods get() and set() which are defined as follows.
// get(x)   : Returns the value of the key x if the key exists in the cache otherwise returns -1.
// set(x,y) : inserts the value if the key x is not already present. If the cache reaches its capacity it should 
// invalidate the least recently used item before inserting the new item.
// In the constructor of the class the size of the cache should be intitialized.

// Input:
// N = 2
// Q = 2
// Queries = SET 1 2 GET 1
// Output: 2

// Your Task:
// You only need to complete the provided functions get() and set().

#include <iostream>
#include <stack>
#include <map>
#include <unordered_map>
using namespace std;

struct Node
{
    int key;
    int value;
    Node *next,*pre;
    Node(int key, int value)
    {
        this->key=key;
        this->value=value;
        next=pre=NULL;
    }

};

class LRUCache {
  private:
    static unordered_map<int, Node *> hsmap;
    static int capacity, count;
    static Node *head, *tail;

  public:
    LRUCache(int cap) {
        capacity = cap;
        head->next = tail;
        tail->pre = head;
    }

    static int get(int key) {
        
        if (hsmap.find(key) == hsmap.end()) 
            return -1;
        else{
            Node *newNode = hsmap[key];
            return newNode->value;
        }
    }

    static void set(int key, int value) {
        if (hsmap.find(key) == hsmap.end()){
            if(capacity == 0){
                Node *tempNode = head;
                head = head->next;
                head->pre = NULL;
                hsmap.erase(tempNode->key);
                free(tempNode);
                capacity++;
            }
            Node *newNode = new Node(key, value);
            newNode->pre = tail;
            tail->next = newNode;
            tail = newNode;
            if(head->key == 0 && head->value == 0)
                head = newNode;
            hsmap[key] = newNode;
            capacity--;
        }
        else{
            Node *tempNode = hsmap[key];
            Node *tempPrev = tempNode->pre;
            Node *tempNext = tempNode->next;
            tempPrev->next = tempNext;
            tempNext->pre = tempPrev;
            hsmap.erase(key);
            Node *newNode = new Node(key, value);
            newNode->pre = tail;
            tail->next = newNode;
            tail = newNode;
            hsmap[key] = newNode;
        }
    }
};

unordered_map<int, Node *> temp;
int LRUCache::capacity = 0;
Node *LRUCache::head = new Node(0,0);
Node *LRUCache::tail = new Node(0,0);
int LRUCache::count = 0;
unordered_map<int, Node *> LRUCache::hsmap = temp;

int main(){
    int T;
	cin>>T;
	while(T--){
	    int capacity, queries;
        cin>>capacity;
        cin>>queries;

        LRUCache *cache = new LRUCache(capacity);
        while(queries--){
            string q;
            cin>>q;
            if(q == "SET"){
                int key, value;
                cin>>key>>value;
                cache->set(key, value);
            }
            else{
                int key;
                cin>>key;
                cout<<cache->get(key)<<" ";
            }
        }
        cout<<"\n";
	}
	return 0;
}