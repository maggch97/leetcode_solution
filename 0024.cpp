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
    ListNode* swapPairs(ListNode* head) {
        ListNode *root = new ListNode;
        root->next=head;
        ListNode *current = root;
        while(current->next!=nullptr && current->next->next!=nullptr){
            auto a = current->next;
            auto b=a->next;
            auto c=b->next;
            current->next=b;
            b->next=a;
            a->next=c;
            current=a;
        }
        current=root->next;
        delete root;
        return current;
    }
};