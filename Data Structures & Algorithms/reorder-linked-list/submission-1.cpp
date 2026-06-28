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
    void reorderList(ListNode* head) {
        if (!head->next) return;
        ListNode* turtle = head;
        ListNode* rabbit = head;
        ListNode* prev_turtle = nullptr;
        
        while(rabbit && rabbit->next) {
            prev_turtle = turtle;
            turtle = turtle->next;
            rabbit = rabbit->next->next;
        }

        prev_turtle->next = nullptr;

        //turtle position: inverse ll
        ListNode* prev = nullptr;
        ListNode* cur = turtle;

        
        while(cur) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        // now create a new ll connect halved ll head and reversed ll prev
        turtle = head;
        ListNode* first = head;
        ListNode* second = prev;

        while(first && second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            if (!tmp1) break;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};
