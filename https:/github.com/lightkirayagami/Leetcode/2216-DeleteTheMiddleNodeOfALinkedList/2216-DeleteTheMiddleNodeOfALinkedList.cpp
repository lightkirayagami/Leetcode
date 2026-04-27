// Last updated: 27/04/2026, 21:44:55
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        int count1=0;
        while(curr!=NULL)
        {
            count1++;
            curr=curr->next;
        }
        curr=head;
        if(count1==1)
        {
            return NULL;
        }
        for(int i=0;i<count1/2;i++)
        {
            if(i==count1/2-1)
            {
                curr->next=curr->next->next;
            }
            else
            {
                curr=curr->next;
            }
            
        }
        // cout<<count1;
        return head;
        
    }
};