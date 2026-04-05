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
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;

        int carry = 0;

        while (l1 not_eq nullptr or l2 not_eq nullptr or carry) {
            int val1 = l1 not_eq nullptr ? l1 -> val : 0;
            int val2 = l2 not_eq nullptr ? l2 -> val : 0;

            int val = val1 + val2 + carry;

            carry = val / 10;
            val = val % 10;

            cur -> next = new ListNode(val);

            cur = cur -> next;
            l1 = l1 not_eq nullptr ? l1 -> next : nullptr;
            l2 = l2 not_eq nullptr ? l2 -> next : nullptr;
        }

        return dummy -> next;
    }
};
