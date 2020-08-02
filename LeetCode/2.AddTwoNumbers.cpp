/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void Insert(struct ListNode** head, int newdata){
        struct ListNode *newNode = new ListNode(newdata);
        if(*head == NULL)
            *head = newNode;
        else{
            struct ListNode *temp = *head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        struct ListNode *head = NULL;
        int temp = 0,num;
        while(head1 != NULL && head2 != NULL){
            num = head1->val + head2->val + temp;
            if(num > 9){
                temp = num / 10;
                num = num % 10;
            }
            else{
                temp = 0;
            }
            Insert(&head, num);
            head1 = head1->next;
            head2 = head2->next;
        }
        while(head1 != NULL){
            num = head1->val + temp;
            if(num > 9){
                temp = num / 10;
                num = num % 10;
            }
            else{
                temp = 0;
            }
            Insert(&head, num);
            head1 = head1->next;
        }
        while(head2 != NULL){
            num = head2->val + temp;
            if(num > 9){
                temp = num / 10;
                num = num % 10;
            }
            else{
                temp = 0;
            }
            Insert(&head, num);
            head2 = head2->next;
        }
        if(temp != 0)
            Insert(&head, temp);
        return head;
    }
};