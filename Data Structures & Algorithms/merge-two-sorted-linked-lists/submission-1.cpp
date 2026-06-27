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
        ListNode* n = nullptr;
        ListNode* ans = nullptr;

        if (!cur1 && !cur2) return nullptr;
        if (!cur1) return cur2;
        if (!cur2) return cur1;

        while(cur1 && cur2) {
            if (cur1->val == cur2->val) {
                if (!n) {
                    n = new ListNode(cur2->val);
                    ans = n;
                    n->next = new ListNode(cur2->val);
                    n = n->next;
                }
                else {
                    n->next = new ListNode(cur2->val);
                    n->next->next = new ListNode(cur2->val);
                    n = n->next->next;
                }
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            else if (cur1->val > cur2->val) {
                if (!n) {
                    n = new ListNode(cur2->val);
                    ans = n;
                }
                else {
                    n->next = new ListNode(cur2->val);
                    n = n->next;
                }
                cur2 = cur2->next;
            }
            else {
                if (!n) {
                    n = new ListNode(cur1->val);
                    ans = n;
                }
                else {
                    n->next = new ListNode(cur1->val);
                    n = n->next;
                }
                cur1 = cur1->next;
            }
        }

        while(cur1) {
            n->next = new ListNode(cur1->val);
            n = n->next;
            cur1 = cur1->next;
        }

        while(cur2) {
            n->next = new ListNode(cur2->val);
            n = n->next;
            cur2 = cur2->next;
        }

        return ans;
    }
};
