class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *resultHeader = new ListNode;
        ListNode *currentNode = resultHeader;
        int previous = 0;
        while (l1 != nullptr || l2 != nullptr || previous != 0) {
            int x = previous;
            previous = 0;
            if (l1 != nullptr) {
                x += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                x += l2->val;
                l2 = l2->next;
            }
            currentNode->next = new ListNode;
            currentNode = currentNode->next;
            currentNode->val = x % 10;
            previous = x / 10;
        }
        return resultHeader->next;
    }
};