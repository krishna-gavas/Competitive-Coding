// Flattening a Linked List(Not submitted)

// Question:
// Given a Linked List of size N, where every node represents a linked list and contains two pointers of its type:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
// Note: The flattened list will be printed using the bottom pointer instead of next pointer.

// Input:
// 5 -> 10 -> 19 -> 28
// |     |     |     | 
// 7     20    22   35
// |           |     | 
// 8          50    40
// |                 | 
// 30               45
// Output:  5-> 7-> 8- > 10 -> 19-> 20->
// 22-> 28-> 30-> 35-> 40-> 45-> 50.
// Note: | represents the bottom pointer.

// Your Task:
// You need to complete the function flatten() that takes head of the list as parameter and returns the root of 
// flattened list. The printing is done by the driver code.

// Solution:
// flatten(root): if(root == NULL) return NULL 
//     create 2 nodes head1 and head2, point head1 to head 
//     while(head1->next != NULL): make head2 = head1->next
//         point head1 to head2->next 
//         head1 = sortedMerge(head1,head2)
//     return head1 


#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

struct Node* sortedMerge(struct Node* head1, struct Node* head2){
    struct Node *temp, *head;
    int flag = 0;
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(flag == 0){
                head = head1;
                temp = head;
            }
            else{
                temp->bottom = head1;
                temp = temp->bottom;
            }
            head1 = head1->bottom;
        }
        else{
            if(flag == 0){
                head = head2;
                temp = head;
            }
            else{
                temp->bottom = head2;
                temp = temp->bottom;
            }
            head2 = head2->bottom;
        }
        flag = 1;
    }
    while(head1 != NULL ){
        temp->bottom = head1;
        temp = temp->bottom;
        head1 = head1->bottom;
    }
    while(head2 != NULL ){
        temp->bottom = head2;
        temp = temp->bottom;
        head2 = head2->bottom;
    }
    return head;
}

Node *flatten(Node *root)
{
    if(root == NULL)
        return NULL;
    Node* head1 = root;
    Node* head2;
    while(head1->next != NULL){
        head2 = head1->next;
        head1->next = head2->next;
        head1 = sortedMerge(head1,head2);
    }
    return head1;
}