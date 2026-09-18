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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||!head->next||k<=1){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* prevgrp = dummy;
        while (true){
            ListNode* kth=prevgrp;
            for(int i=0;i<k && kth;i++){
                kth=kth->next;
            }
            if(!kth){
                break;
            }
            ListNode* grpst=prevgrp->next;
            ListNode* nxtgrpst=kth->next;
            ListNode* prev = nxtgrpst;
            ListNode* cur= grpst;
            while(cur!=nxtgrpst){
                ListNode* temp=cur->next;
                cur->next=prev;
                prev=cur;
                cur=temp;
            }
            prevgrp->next=kth;
            prevgrp=grpst;
        }
        return dummy->next;
    }
};