class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        //Edge Cases 
        if(!head || !head->next || k==0) return head;

        //Compute Length
        ListNode *curr = head;
        int len = 1;

        while(curr->next!=NULL)
        {
                curr = curr->next;
                ++len;
       }


        //go till that node
        curr->next = head;
        k= k % len;
        k = len-k;

        while(k--) curr = curr->next;

        //make the node head and break connection

        head = curr->next;
        curr->next = NULL;


        return head;

    }
};