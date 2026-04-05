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
        int count = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            count++;
            cur = cur -> next;
        }
        int removeIdx = count - n;

        if (removeIdx == 0) return head -> next;

        cur = head;
        for (int i = 0; i < removeIdx - 1; i++) {
            cur = cur -> next;
        }
        cur -> next = cur -> next -> next;

        return head;
    }
};
