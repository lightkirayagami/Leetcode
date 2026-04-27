// Last updated: 27/04/2026, 21:50:35
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
    ListNode* sortList(ListNode* head) {


        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode* middle1=middle(head);
        ListNode* leftnew=head;
        ListNode* rightnew=middle1->next;
        middle1->next=NULL;
        ListNode* l1=sortList(leftnew);
        ListNode* l2=sortList(rightnew);
        return merge(l1,l2);
        
    }

    ListNode* middle(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
            {
                break;
            }
        }
        return slow;
    }

    ListNode* merge(ListNode* l1,ListNode*l2)
    {
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        while(l1&&l2)
        {
            if(l1->val<l2->val)
            {
                curr->next=l1;
                curr=curr->next;
                l1=l1->next;
            }
            else
            {
                curr->next=l2;
                curr=curr->next;
                l2=l2->next;
            }
        }
        if(l1)
        {
            curr->next=l1;
        }
        else
        {
            curr->next=l2;
        }
        return dummy->next;
    }
};