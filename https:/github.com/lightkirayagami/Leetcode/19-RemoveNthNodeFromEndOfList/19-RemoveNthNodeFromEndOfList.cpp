// Last updated: 27/04/2026, 21:53:02
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* curr=head;
        int len=0;
         while(curr)
         {
            curr=curr->next;
            len++;
         }


         curr=head;
         ListNode* dummy=new ListNode(-1);
         dummy->next=head;
         curr=dummy;


         for(int i=0;i<len-n;i++)
         {
            curr=curr->next;
         }

         curr->next=curr->next->next;

         return dummy->next;


    }
};