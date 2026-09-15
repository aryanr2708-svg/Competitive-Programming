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
    bool isPalindrome(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast= head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* cur = slow;
        while(cur!=NULL){
            ListNode* nn = cur->next;
            cur->next=prev;
            prev = cur;
            cur = nn;
        }
        ListNode* lh = head;
        ListNode* rh = prev;
        while(rh!=NULL){
            if(rh->val!=lh->val){
                return false;
            }
            lh = lh->next;
            rh=rh->next;
        }
        return true;
    }
};