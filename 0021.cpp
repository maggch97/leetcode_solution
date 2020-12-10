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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* root3=new ListNode;
        auto c3=root3, c1=l1,c2=l2;
        while(c1!=nullptr || c2!=nullptr){
            if(c2==nullptr || (c1!=nullptr && c1->val<c2->val)){
                c3->next=c1;
                c1=c1->next;
            }else{
                c3->next=c2;
                c2=c2->next;
            }
            c3=c3->next;
        }
        return root3->next;
    }
};