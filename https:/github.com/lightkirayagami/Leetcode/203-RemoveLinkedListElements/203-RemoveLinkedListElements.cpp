// Last updated: 27/04/2026, 21:50:04
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
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* curr=head;
        ListNode* prev=dummy;

        while(curr!=NULL)
        {
            if(curr->val==val)
            {
                curr=curr->next;
                prev->next=curr;
            
            }
            else
            {
                prev=curr;
                curr=curr->next;
                
            }
        }
        return dummy->next;

        
        
    }
};