class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * prev = NULL;
        ListNode * slow = head;
        ListNode * fast = head;
        for(int i = 0; i < n; i ++) {
            fast = fast -> next;
        }
        
        while(fast != NULL) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next;
        }
        
        if(prev == NULL) {
            return slow -> next;
        } else {
            prev -> next = slow -> next;
            delete slow;
        }
        return head;
    }
};