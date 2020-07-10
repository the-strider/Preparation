/*
Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
*/

class Solution {
public:
    int countNode(ListNode * head) {
        int cnt = 0;
        ListNode * temp = head;
        while(temp) {
            cnt ++;
            temp = temp -> next;
        }
        return cnt;
    }

    void rotate(ListNode **head, int k) {
        // Inplace rotate list
        int n = countNode(*head);
        if(!head or k % n == 0) {
            return;
        }
        k %= n;
        
        ListNode * temp_head = *head;
        ListNode * temp = *head;
        for(int i = 0; i < k; i ++) {
            temp = temp -> next;
        }
        
         while(temp -> next) {
            temp = temp -> next;
            temp_head = temp_head -> next;
        }
        
        ListNode * new_head = temp_head -> next;
        temp_head -> next = NULL;
        temp -> next = *head;
        
        *(head) = new_head;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        // Rotate without changing actual list
        if(!head) return head;
        
        ListNode * new_head = new ListNode();
        ListNode * temp_new_head = new_head;
        ListNode * temp_head = head;
        
        while(temp_head) {
            temp_new_head -> next = new ListNode(temp_head -> val);
            temp_head = temp_head -> next;
            temp_new_head = temp_new_head -> next;
        }
        
        rotate(&new_head -> next, k);
        return new_head -> next;
    }
};