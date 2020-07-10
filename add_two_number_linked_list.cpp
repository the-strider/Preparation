/*
Add two number represented as a linked list in constant space and linear time
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

Solution -> First create a linked list by adding corresponding value of two list 
			in reverse order.
			For e.g 
			9 -> 7 -> 6 -> 5
			     4 -> 3 -> 5
			9 <- 11 <- 9 <- 10 <- head

			now reverse list by forwarding carry
*/

class Solution {
public:
    int countNodes(ListNode * head)
    {
        int cnt = 0;
        while(head) {
            cnt ++;
            head = head -> next;
        }
        return cnt;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n = countNodes(l1);
        int m = countNodes(l2);
        
        if(n < m) {
            swap(l1, l2);
            swap(n, m);
        }

        ListNode * l3 = NULL;
        int d = n - m;
        
        for(int i = 0; i < d; i ++) {
            ListNode * new_node = new ListNode(l1 -> val);
            new_node -> next = l3;
            l3 = new_node;
            l1 = l1 -> next;
        }
        
        while(l1 and l2) {
            int d = l1 -> val + l2 -> val;
            ListNode * new_node = new ListNode(d);
            new_node -> next = l3;
            l3 = new_node;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        
        ListNode * res = NULL;
        int carry = 0;
        while(l3) {
            int val = carry + l3 -> val;
            carry = val / 10;
            val %= 10;
            
            l3 -> val = val;

            ListNode * temp = l3 -> next;
            l3 -> next = res;
            res = l3;
            l3 = temp;
        }
        
        if(carry) {
            ListNode * temp = new ListNode(carry);
            temp -> next = res;
            res = temp;
        }
        return res;
    }
};