// Last updated: 27/04/2026, 21:49:35
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
    bool isPalindrome(ListNode* head) {
        ListNode* head1=middle(head);
        ListNode*head2= reverse(head1);

        ListNode* curr1=head;
        ListNode* curr2=head2;
        while(curr1&&curr2)
        {
            if(curr1->val!=curr2->val)
            {
                return false;
            }
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return true;



        
        
    }

    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forw=head;

        while(curr)
        {
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
            
            
        }
        return prev;

    }
    ListNode* middle(ListNode* head)
    {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};