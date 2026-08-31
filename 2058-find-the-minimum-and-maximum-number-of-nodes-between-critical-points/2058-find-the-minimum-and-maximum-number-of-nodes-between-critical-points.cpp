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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>cp;
        if(head==nullptr||head->next==nullptr||head->next->next==nullptr){
            return{-1,-1};
        }
        ListNode* prev=head;
        ListNode* cur=head->next;
        int ci=1;
        while(cur->next!=nullptr){
            ListNode* nextnode=cur->next;
            bool isMax = (cur->val>prev->val)&&(cur->val>nextnode->val);
            bool isMin = (cur->val<prev->val)&&(cur->val<nextnode->val);
            if(isMax||isMin){
                cp.push_back(ci);
            }
            prev=cur;
            cur=nextnode;
            ci++;
        }
        if(cp.size()<2){
            return{-1,-1};
        }
        int maxd=cp.back()-cp.front();
        int mind=INT_MAX;
        for(int i=1;i<cp.size();i++){
            int cd=cp[i]-cp[i-1];
            mind=min(mind,cd);
        }
        return {mind,maxd};
    }
};