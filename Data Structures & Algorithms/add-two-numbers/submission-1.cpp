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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;

        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;
        
        int add = 0;

        while(cur1 && cur2) {
            int val = cur1->val + cur2->val + add;
            add = (val >= 10) ? 1 : 0;
            val %= 10;

            ans->next = new ListNode(val);

            cur1 = cur1->next;
            cur2 = cur2->next;
            ans = ans->next;
        }

        while(cur1) {
            int val = cur1->val + add;
            add = (val >= 10) ? 1 : 0;
            val %= 10;

            ans->next = new ListNode(val);

            cur1 = cur1->next;
            ans = ans->next;
        }

        while(cur2) {
            int val = cur2->val + add;
            add = (val >= 10) ? 1 : 0;
            val %= 10;

            ans->next = new ListNode(val);

            cur2 = cur2->next;
            ans = ans->next;
        }

        if (add > 0) ans->next = new ListNode(add);

        ans = dummy->next;
        delete dummy; 
        return ans;
    }
};
