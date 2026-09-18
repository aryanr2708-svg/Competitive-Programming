/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        Node* cur=head;
        while(cur!=NULL){
            Node* cNode=new Node(cur->val);
            cNode->next=cur->next;
            cur->next=cNode;
            cur=cNode->next;
        }
        cur = head;
        while(cur!=NULL){
            if(cur->random){
                cur->next->random=cur->random->next;
            }
            cur=cur->next->next;
        }
        cur=head;
        Node* dummyHead= head->next;
        while(cur!=NULL){
            Node* ncur=cur->next;
            cur->next=ncur->next;
            if(ncur->next!=NULL){
                ncur->next=ncur->next->next;
            }
            cur=cur->next;
        }
    return dummyHead;
    }
};