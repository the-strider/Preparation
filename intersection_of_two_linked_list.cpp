class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA or !headB) {
            return NULL;
        }

        ListNode * p1 = headA;
        ListNode * p2 = headB;
        
        int loop = 0;
        while(loop < 3) {
            if(p1 == p2) {
                return p1;
            }
            
            p1 = p1 -> next;
            p2 = p2 -> next;
            
            if(!p1) {
                loop ++;
                p1 = headB;   // change pointer of headA to headB
            }
            if(!p2) {
                loop ++;
                p2 = headA;  // change pointer of headA to headB
            }
        }
        return NULL;
    }
};