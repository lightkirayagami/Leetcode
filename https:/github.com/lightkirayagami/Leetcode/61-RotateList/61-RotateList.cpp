// Last updated: 27/04/2026, 21:52:17
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head; // No rotation needed
        }

        int size = 0;
        ListNode* curr = head;
        while (curr) {
            size++;
            curr = curr->next;
        }
        k = k % size;
        curr = head;
        for (int i = 0; i < k; i++) {
            ListNode* prev = new ListNode(-1);
            prev->next=head;
            curr = head;
            while (curr->next) {
                curr = curr->next;
                prev = prev->next;
            }
            prev->next = NULL;
            curr->next = head;
            head=curr;
        }
        return head;
    }
};