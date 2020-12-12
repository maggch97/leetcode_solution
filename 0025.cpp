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
        if(k==1)return head;
        ListNode* root = new ListNode;
        root->next=head;
        ListNode* current = root;
        for(;;){
            int idx = 0;
            auto end = current;
            while(idx<k && end!=nullptr){
                end = end->next;
                idx++;
            }
            if(idx<k || end==nullptr){
                break;
            }
            auto l = current->next;
            auto r = end;
            auto rr  = end->next;
            for(auto a= l->next, pre =l;pre!=end;){
                auto tmp = a->next;
                a->next=pre;
                pre =a;
                a=tmp;
            }
            l->next=rr;
            current->next=r;
            current=l;
        }
        return root->next;
    }
};