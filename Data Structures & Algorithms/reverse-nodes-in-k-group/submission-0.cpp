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
    ListNode* reverse(ListNode* from, ListNode* to) {
        ListNode* prev = to->next;
        ListNode* cur = from;
        while(prev != to) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return to;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;

        while(true) {
            ListNode* kth = groupPrev;
            for(int i=0; i < k && kth; i++) kth = kth->next;
            if (!kth) break;

            ListNode* groupStart = groupPrev->next;
            ListNode* newGroup = kth->next;

            ListNode* newNode = reverse(groupStart, kth);
            groupPrev->next = newNode;
            groupPrev = groupStart;
        }

        return dummy.next;
    }
};
