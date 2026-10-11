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
    ListNode* reverseList(ListNode* head) {
        // time O(n) / space O(1)
        ListNode* nh = nullptr; // new head
        ListNode* node = head;

        while(node) {
            ListNode *currNode;
            currNode = node;
            node = currNode->next;
            currNode->next = nh;
            nh = currNode;
        }

        return nh;
    }
};
