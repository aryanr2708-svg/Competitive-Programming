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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_set<int> mp;
        if(!head || head->next == NULL){
            return head;
        }
        ListNode* cur = head;
        mp.insert(cur->val);
        while(cur && cur->next){
            if(mp.count(cur->next->val)){
                ListNode* temp=cur->next;
                cur->next=cur->next->next;
                delete temp;
            }
            else{
                mp.insert(cur->next->val);
                cur=cur->next;
            }
        }
        return head;
    }
};