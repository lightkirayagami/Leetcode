// Last updated: 27/04/2026, 21:51:42
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
    ListNode* partition(ListNode* head, int x) {

        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);
        ListNode* prev1 = dummy1;
        ListNode* prev2 = dummy2;
        ListNode* curr = head;

        while (curr) {
            if (curr->val < x) {
                prev1->next = curr;
                prev1 = curr;
            } else {
                prev2->next = curr;
                prev2 = curr;
            }
            curr = curr->next;
        }
       prev1->next=dummy2->next;
       prev2->next=NULL;

        return dummy1->next;
    }
};