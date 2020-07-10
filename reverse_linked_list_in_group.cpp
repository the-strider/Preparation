class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * new_head = new ListNode();
        ListNode * temp_head = new_head;
        ListNode * prev = NULL;
        int cnt = 0;
        
        ListNode * start_node = head;
        while(head) {
            cnt ++;
            ListNode * temp = head -> next;
            head -> next = prev;
            prev = head;
            head = temp;
            if(cnt == k) {
                temp_head -> next = prev;
                prev = NULL;
                temp_head = start_node;
                start_node = head;
                cnt = 0;
            }
        }
        
        if(prev) {
            ListNode * prev_rev = NULL;
            while(prev) {
                ListNode * temp = prev -> next;
                prev -> next = prev_rev;
                prev_rev = prev;
                prev = temp;
            }
            temp_head -> next = prev_rev;
        }
        return new_head -> next;
    }
};