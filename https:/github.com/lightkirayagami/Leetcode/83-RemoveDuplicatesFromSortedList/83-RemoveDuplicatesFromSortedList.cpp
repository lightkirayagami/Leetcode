// Last updated: 27/04/2026, 21:51:47
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode*prev=dummy;
        ListNode*curr=head;
        
        while(curr!=NULL&&curr->next!=NULL)
        {
            if(curr->val==curr->next->val)
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