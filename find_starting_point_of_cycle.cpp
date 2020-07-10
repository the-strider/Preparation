class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head or !head -> next) {
            return NULL;
        }
        
        ListNode * slow = head;
        ListNode * fast = head;
        
        do {
            if(!fast or !fast -> next) {
                return NULL;
            }
            slow = slow -> next;
            fast = fast -> next -> next;
        } while(slow != fast);
        
        ListNode * prev = NULL;
        slow = head;
        int cnt = 0;
        while(slow != fast) {
            prev = fast;  // starting previous node of starting point if found
            slow = slow -> next;
            fast = fast -> next;
        }
        // remove loop
        prev -> next = NULL;
        return slow;
    }
};