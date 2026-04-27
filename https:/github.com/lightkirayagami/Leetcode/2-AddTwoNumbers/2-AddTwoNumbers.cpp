// Last updated: 27/04/2026, 21:53:19
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1=l1;
        ListNode* curr2=l2;

        ListNode* temp=new ListNode(-1);
        ListNode* head=temp;
        int carry=0;
        while(curr1&&curr2)
        {
            int x=curr1->val+curr2->val+carry;
            if(x>=10)
            {
                carry=1;
                temp->next=new ListNode(x%10);
                
            }
            else
            {
                carry=0;
                temp->next=new ListNode(x%10);
            }
            temp=temp->next;
            curr1=curr1->next;
            curr2=curr2->next;
        }

        while(curr1)
        {
            int x=curr1->val+carry;
            if(x>=10)
            {
                carry=1;
                temp->next=new ListNode(x%10);
            }
            else
            {
                carry=0;
                temp->next=new ListNode(x%10);
            }
            temp=temp->next;
            curr1=curr1->next;
         
        }
        while(curr2)
        {
            int x=curr2->val+carry;
            if(x>=10)
            {
                carry=1;
                temp->next=new ListNode(x%10);
            }
            else
            {
                carry=0;
                temp->next=new ListNode(x%10);
            }
            temp=temp->next;
            curr2=curr2->next;
        }
        if(carry>0)
        {
            temp->next=new ListNode(1);
        }
        return head->next;
        
    }
};