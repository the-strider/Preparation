// Iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * prev = NULL;
        ListNode * curr = head;
        while(curr) {
            ListNode * next_temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next_temp;
        }
        return prev;
    }
};


// Recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head or !head -> next) {
            return head;
        }
        ListNode * prev = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return prev;
    }
};