// Last updated: 27/04/2026, 21:51:36
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right||!head)
        {
            return head;
        }

        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* prev=dummy;

       for(int i=1;i<left;i++)
       {
        prev=prev->next;
       }
       ListNode* curr=prev->next;
       ListNode* forward=NULL;
       ListNode* reversehead=reverse(curr,forward,right-left+1);
       
        prev->next=reversehead;
        curr->next=forward;
        return dummy->next;

        
    }
    ListNode* reverse(ListNode*& head,ListNode*& forward,int x)
    {
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr&&x>0)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            x--;
        }
        return prev;

    }
};