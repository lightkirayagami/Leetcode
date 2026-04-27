// Last updated: 27/04/2026, 21:50:47
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head==NULL)
        {
            return NULL;
        }

        Node * curr=head;
        //adding new node in between

        while(curr)
        {
            Node* nextNode=curr->next;

            curr->next=new Node(curr->val);
            curr->next->next=nextNode;

            curr=nextNode;
        }


        curr=head;
        //setting random pointers

        while(curr)
        {
            if(curr->random==NULL)
            {
                curr->next->random=NULL;
            }
            else
            {
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }

        //seperate next;

        Node* dummy=new Node(NULL);
        Node* newcurr=dummy;
        curr=head;

        while(curr&&curr->next)
        {
            newcurr->next=curr->next;
            newcurr=newcurr->next;
            curr->next=curr->next->next;
            curr=curr->next;
           
            
        }
        return dummy->next;


    }
};