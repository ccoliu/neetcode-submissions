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
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];

        while(lists.size() > 1) {
            ListNode* dummy = new ListNode(0);
            ListNode* cur = dummy;

            ListNode* first = lists[0];
            ListNode* sec = lists[1];

            while(first && sec) {
                if (first->val <= sec->val) {
                    cur->next = new ListNode(first->val);
                    first = first->next;
                    cur = cur->next;
                }
                else {
                    cur->next = new ListNode(sec->val);
                    sec = sec->next;
                    cur = cur->next;
                }
            }

            while(first) {
                cur->next = new ListNode(first->val);
                cur = cur->next;
                first = first->next;
            }

            while(sec) {
                cur->next = new ListNode(sec->val);
                cur = cur->next;
                sec = sec->next;
            }

            cur = dummy->next;
            delete dummy;

            lists.erase(lists.begin());
            lists.erase(lists.begin());
            lists.push_back(cur);
        }

        return lists[0];
    }
};
