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
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        while (l1 and l2) {
            if (l1 -> val < l2 -> val) {
                cur -> next = l1;
                l1 = l1 -> next;
            } else {
                cur -> next = l2;
                l2 = l2 -> next;
            }
            cur = cur -> next;
        }
        if (l1) cur -> next = l1;
        else if (l2) cur -> next = l2;

        return dummy -> next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() < 1) return nullptr;
        while(lists.size() > 1) {
            vector<ListNode*> mergedLists;
            for(int i = 0; i < lists.size(); i+=2) {
                ListNode* list1 = lists[i];
                ListNode* list2 = ((i + 1) < lists.size()) ? lists[i + 1] : nullptr ;
                ListNode* mergedList = mergeLists(list1, list2);
                mergedLists.push_back(mergedList);
            }
            lists = mergedLists;
        }
        return lists[0];
    }
};
