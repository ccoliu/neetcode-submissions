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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;

        if (!cur1 && !cur2) return nullptr;
        if (!cur1) return cur2;
        if (!cur2) return cur1;

        while(cur1 && cur2) {
            if (cur1->val > cur2->val) {
                ans->next = new ListNode(cur2->val);
                ans = ans->next;
                cur2 = cur2->next;
            }
            else {
                ans->next = new ListNode(cur1->val);
                ans = ans->next;
                cur1 = cur1->next;
            }
        }

        while(cur1) {
            ans->next = new ListNode(cur1->val);
            ans = ans->next;
            cur1 = cur1->next;
        }

        while(cur2) {
            ans->next = new ListNode(cur2->val);
            ans = ans->next;
            cur2 = cur2->next;
        }

        ans = dummy->next;
        delete dummy;
        return ans;
    }
};
