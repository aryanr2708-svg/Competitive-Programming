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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        return msort(left,right);
    }
    ListNode* msort(ListNode* left,ListNode* right){
        ListNode* t= new ListNode(0);
        ListNode* cur=t;
        while(left!=NULL && right!=NULL){
            if(left->val <= right->val){
                cur->next=left;
                left=left->next;
            }
            else{
                cur->next=right;
                right=right->next;
            }
        cur=cur->next;
        }
        if(left!=NULL){
            cur->next=left;
            left=left->next;
        }
        if(right!=NULL){
            cur->next=right;
            right=right->next;
        }
    return t->next;
    }
};