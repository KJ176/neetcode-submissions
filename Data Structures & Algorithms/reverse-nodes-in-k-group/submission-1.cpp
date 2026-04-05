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
    ListNode* getKthNode(ListNode* node, int k) {
        while (node and k) {
            node = node -> next;
            k--;
        }
        return node;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy;

        while (true) {
            ListNode* kth = getKthNode(groupPrev, k);
            if (kth == nullptr) {
                break;
            }
            ListNode* groupNext = kth -> next;

            ListNode* prev = groupNext;
            ListNode* cur = groupPrev -> next;

            while (cur != groupNext) {
                ListNode* temp = cur -> next;
                cur -> next = prev;
                prev = cur;
                cur = temp;
            }

            ListNode* temp = groupPrev -> next;
            groupPrev -> next = kth;
            groupPrev = temp;
        }
        return dummy -> next;
    }
};
