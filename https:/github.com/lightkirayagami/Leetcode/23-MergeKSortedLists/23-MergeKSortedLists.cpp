// Last updated: 27/04/2026, 21:52:55
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size()==0)
        {
            return NULL;
        }

        return divide(lists,0,lists.size()-1);
        
    }

    ListNode* divide(vector<ListNode*>&lists,int start,int end)
    {
        if(start==end)
        {
            return lists[start];
        }
        int m=(start+end)/2;

        ListNode* left=divide(lists,start,m);
        ListNode* right=divide(lists,m+1,end);
        return merge(left,right);
    }

    ListNode* merge(ListNode* left,ListNode* right)
    {
        ListNode* curr1=left;
        ListNode* curr2=right;
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;

        while(curr1!=NULL&&curr2!=NULL)
        {

            if(curr1->val<curr2->val)
            {
                curr->next=curr1;
                curr1=curr1->next;
                curr=curr->next;
            }
            else
            {
                curr->next=curr2;
                curr2=curr2->next;
                curr=curr->next;
            }
        }

        if(curr1!=NULL)
        {
            curr->next=curr1;
        }
        if(curr2!=NULL)
        {
            curr->next=curr2;
        }

        // curr->next=NULL;
        return dummy->next;

    }
};