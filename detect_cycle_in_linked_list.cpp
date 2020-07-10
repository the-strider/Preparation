class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) {
            return 0;
        }

        ListNode * slow = head;
        ListNode * fast = head -> next;
        
        while(slow and fast) {
            if(slow == fast) {
                return true;
            }
            slow = slow -> next;
            fast = fast -> next ? fast -> next -> next: fast -> next;
        }
        return false;
    }
};