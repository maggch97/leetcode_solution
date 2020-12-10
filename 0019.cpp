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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* root = new ListNode;
        root->next=head;
        auto current = root->next;
        int size = 0;
        while(current!=nullptr){
            current=current->next;
            size++;
        }
        n = size-n;
        current = root;
        for(int i=0;i<n;i++){
            current=current->next;
        }
        auto del = current->next;
        current->next=del->next;
        delete del;
        current=root->next;
        delete root;
        return current;
    }
};