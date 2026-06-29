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
        int len = 0;
        ListNode* cur = head;

        while(cur) {
            cur = cur->next;
            len++;
        }

        if (len == 1) return nullptr;

        int rm = len - n;

        ListNode* prev = nullptr;
        cur = head;
        int idx = 0;

        while (idx < rm && cur) {
            prev = cur;
            cur = cur->next;
            idx++;
        }

        if (head == cur) {
            head = cur->next;
            delete cur;
            return head;
        }

        prev->next = cur->next;
        delete cur;

        return head;
    }
};
