// Last updated: 27/04/2026, 21:50:26
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* currA=headA;
        ListNode*currB=headB;
        int lenA=0;
        while(currA)
        {
            lenA++;
            currA=currA->next;
        }
        int lenB=0;
        while(currB)
        {
            lenB++;
            currB=currB->next;
        }

        if(lenA<lenB)
        {
            int x=lenB-lenA;
            while(x>0)
            {
                x--;
                headB=headB->next;
            }
            ListNode* currA=headA;
            ListNode* currB=headB;
            while(currA&&currB)
            {
                if(currA==currB)
                {
                    return currA;
                }
                currA=currA->next;
                currB=currB->next;
            }  
        }
        else
        {
            int x=lenA-lenB;
            while(x>0)
            {
                x--;
                headA=headA->next;
            }
            ListNode* currA=headA;
            ListNode* currB=headB;
            while(currA&&currB)
            {
                if(currA==currB)
                {
                    return currA;
                }
                currA=currA->next;
                currB=currB->next;
            }  
        }
        return NULL;

        
    }
};