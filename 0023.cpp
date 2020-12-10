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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* root = new ListNode;
        auto current = root;
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=nullptr){
                pq.push({lists[i]->val,lists[i]});
            }
        }
        while(!pq.empty()){
            auto now = pq.top();
            pq.pop();
            current->next=now.second;
            current = current->next;
            if(now.second->next!=nullptr){
                pq.push({now.second->next->val,now.second->next});
            }
        }
        return root->next;
    }
};