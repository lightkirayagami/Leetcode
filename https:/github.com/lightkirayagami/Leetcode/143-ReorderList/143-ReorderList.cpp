// Last updated: 27/04/2026, 21:50:41
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
    void reorderList(ListNode* head) {

        ListNode* middleNode=middle(head);

        ListNode* right=reverse(middleNode->next);
        middleNode->next=NULL;

        ListNode* left=head;
        ListNode* dummy=new ListNode(-1);

        ListNode* curr=dummy;

        while(left!=NULL&&right!=NULL)
        {
            curr->next=left;
            left=left->next;
            curr=curr->next;
            curr->next=right;
            right=right->next;
            curr=curr->next;
        }

        if(left!=NULL)
        {
            curr->next=left;
        }
        if(right!=NULL)
        {
            curr->next=right;
        }
        head=dummy->next;

        
    }

    ListNode* middle(ListNode* curr)
    {
        ListNode* slow=curr;
        ListNode* fast=curr;
        while(fast!=NULL &&fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* curr)
    {

        ListNode* prev=NULL;
        ListNode* forward=NULL;

        while(curr!=NULL)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;

        }

        return prev;
    }
};